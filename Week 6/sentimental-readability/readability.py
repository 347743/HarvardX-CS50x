import re
import math


def count_letters(text):
    """Count the number of letters in the text."""
    return sum(1 for char in text if char.isalpha())


def count_words(text):
    """Count the number of words in the text."""
    return len(text.split())


def count_sentences(text):
    """Count the number of sentences in the text."""
    return sum(1 for char in text if char in '.!?')


def main():
    # Prompt the user for some text
    text = input("Text: ")

    # Count the number of letters, words, and sentences in the text
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Compute the Coleman-Liau index
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # Print the grade level
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()
