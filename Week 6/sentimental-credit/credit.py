def luhn_algorithm(number):
    """
    Apply Luhn's Algorithm to validate the credit card number.
    """
    sum_digits = 0
    alternate = False

    while number > 0:
        digit = number % 10
        if alternate:
            digit *= 2
            if digit > 9:
                digit -= 9
        sum_digits += digit
        alternate = not alternate
        number //= 10

    return sum_digits % 10 == 0


def get_length(number):
    """
    Get the length of the number.
    """
    return len(str(number))


def get_first_digits(number, n):
    """
    Get the first n digits of the number.
    """
    return int(str(number)[:n])


def print_card_type(number):
    """
    Determine and print the credit card type.
    """
    length = get_length(number)
    first_two_digits = get_first_digits(number, 2)
    first_digit = get_first_digits(number, 1)

    if length == 15 and (first_two_digits == 34 or first_two_digits == 37):
        print("AMEX")
    elif length == 16 and (51 <= first_two_digits <= 55):
        print("MASTERCARD")
    elif (length == 13 or length == 16) and first_digit == 4:
        print("VISA")
    else:
        print("INVALID")


def main():
    """
    Main function to validate credit card number.
    """
    while True:
        try:
            number = int(input("Number: "))
            if number > 0:
                break
        except ValueError:
            pass

    if luhn_algorithm(number):
        print_card_type(number)
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
