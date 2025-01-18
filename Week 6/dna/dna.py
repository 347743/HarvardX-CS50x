import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    database = []
    try:
        with open(sys.argv[1], "r") as file:
            reader = csv.DictReader(file)
            for row in reader:
                # Convert STR counts to integers
                row.update({key: int(value) for key, value in row.items() if key != "name"})
                database.append(row)
    except FileNotFoundError:
        print(f"Error: Could not find file {sys.argv[1]}")
        sys.exit(1)

    # Read DNA sequence file into a variable
    try:
        with open(sys.argv[2], "r") as file:
            sequence = file.read().strip()
    except FileNotFoundError:
        print(f"Error: Could not find file {sys.argv[2]}")
        sys.exit(1)

    # Find longest match of each STR in DNA sequence
    if database:
        str_counts = {str_name: longest_match(sequence, str_name)
                      for str_name in database[0] if str_name != "name"}
    else:
        print("Error: Database is empty or invalid.")
        sys.exit(1)

    # Check database for matching profiles
    for person in database:
        if all(person[str_name] == str_counts[str_name] for str_name in str_counts):
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length - subsequence_length + 1):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        while sequence[i + count * subsequence_length:i + (count + 1) * subsequence_length] == subsequence:
            count += 1

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
