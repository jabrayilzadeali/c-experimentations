#include "libcs50/cs50.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * AMEX
 * starts with: 37, 34
 * length: 15
 *
 * Visa
 * starts with: 4
 * length: 16
 *
 * Mastercard
 * starts with: 2, 5
 * length: 16
 */

long long power(int a, int b)
{
    int i = 1;
    long long k = a;
    do
    {
        k *= a;
        i++;
    } while (i < b);
    return k;
}

int countDigits(long long number)
{
    int count = 0;
    do
    {
        number /= 10;
        ++count;
    } while (number != 0);
    return count;
}

void main()
{
    bool algorithm;
    bool length_and_first_num;
    char result;
    long long user_input = get_long_long("credit card number: ");
    long long credit_card = user_input;
    long long copy_number = user_input;
    long long copy_number2 = user_input;
    copy_number /= 10;
    int total_number = 0;
    do
    {
        int last_digit = copy_number % 10;
        int last_digit_x_2 = last_digit * 2;
        if (last_digit_x_2 / 10 == 0)
        {
            total_number += last_digit_x_2;
        }
        else
        {
            int copy_of_last_digit_x_2 = last_digit_x_2;
            do
            {
                total_number += copy_of_last_digit_x_2 % 10;
                copy_of_last_digit_x_2 /= 10;
            } while (copy_of_last_digit_x_2 != 0);
        }
        copy_number /= 100;
    } while (copy_number != 0);

    do
    {
        total_number += copy_number2 % 10;
        copy_number2 /= 100;
    } while (copy_number2 != 0);

    if (total_number % 10 == 0)
    {
        algorithm = true;
        // printf("Algorithm is true\n");
    }
    else
    {
        // printf("Last digit in algorithm is not 0 in calculation. This is incorrect\n");
        printf("INVALID");
        exit(0);
    }

    int number_of_digits = countDigits(user_input);

    if (number_of_digits == 16)
    {
        int first_digit = credit_card / power(10, 15);
        if (first_digit == 4)
        {
            // printf("VISA\n");
            result = 'v';
            length_and_first_num = true;
        }
        else if (first_digit == 2 || first_digit == 5)
        {
            // printf("MASTERCARD\n");
            result = 'm';

            length_and_first_num = true;
        }
        else
        {
            // printf("INVALID\n");
            result = 'i';
            length_and_first_num = false;
        }
    }
    else if (number_of_digits == 15)
    {
        int first_two_digits = credit_card / power(10, 13);
        if (first_two_digits == 34 || first_two_digits == 37)
        {
            // printf("AMEX\n");
            result = 'a';
            length_and_first_num = true;
        }
        else
        {
            // printf("INVALID\n");
            result = 'i';
            length_and_first_num = false;
        }
    }
    else
    {
        // printf("INVALID\n");
        result = 'i';
        length_and_first_num = false;
    }

    if (algorithm == true && length_and_first_num == true)
    {
        if (result == 'i')
        {
            printf("INVALID");
        }
        else if (result == 'v')
        {
            printf("VISA");
        }
        else if (result == 'm')
        {
            printf("MASTERCARD");
        }
        else if (result = 'a')
        {
            printf("AMEX");
        }
        // printf("%d\n", algorithm);
        // printf("%d\n", length_and_first_num);
        // printf("%d\n", result);
    }
    else
    {
        printf("%d\n", algorithm);
        printf("%d\n", length_and_first_num);
        printf("i");
    }
}
