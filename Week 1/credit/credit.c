#include <cs50.h>
#include <stdio.h>

// Function prototypes
bool luhn_algorithm(long number);
int get_length(long number);
int get_first_digits(long number, int n);
void print_card_type(long number);

int main(void)
{
    // 1. Prompt for input
    long number = get_long("Number: ");

    // 2. Calculate checksum using Luhn's Algorithm
    if (luhn_algorithm(number))
    {
        // 3. Check for card length and starting digits
        print_card_type(number);
    }
    else
    {
        // If checksum is invalid, print INVALID
        printf("INVALID\n");
    }
}

// Function to apply Luhn's Algorithm to validate the credit card number
bool luhn_algorithm(long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;  // Subtract 9 from double digits (equivalent to sum of digits)
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }

    // Valid if the sum modulo 10 is 0
    return (sum % 10 == 0);
}

// Function to get the length of the number
int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

// Function to get the first n digits of the number
int get_first_digits(long number, int n)
{
    while (number >= 100)
    {
        number /= 10;
    }
    return number;
}

// Function to determine and print the credit card type
void print_card_type(long number)
{
    int length = get_length(number);
    int first_two_digits = get_first_digits(number, 2);
    int first_digit = get_first_digits(number, 1);

    // 4. Print card type or INVALID
    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
