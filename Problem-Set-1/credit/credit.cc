#include <cs50.h>
#include <stdio.h>

bool luhns_algorithm(long number);
void card_type_detector(long number);

int main(void)
{
    long cc_number = get_long("Number: ");

    if (luhns_algorithm(cc_number) == true)
    {
        card_type_detector(cc_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhns_algorithm(long number)
{
    long sum_last = 0;

    long sum_second_to_last = 0;

    for (long i = (number - (number % 10)) / 10; i > 0; i = (i - (i % 10)) / 100)
    {
        long last_digit = i % 10;

        if (last_digit * 2 > 9)
        {
            sum_second_to_last += last_digit * 2 % 10;
            sum_second_to_last += last_digit * 2 / 10;
        }
        else
        {
            sum_second_to_last += i % 10 * 2;
        }
    }

    for (long j = number; j > 0; j = (j - (j % 10)) / 100)
    {
        sum_last += j % 10;
    }

    if ((sum_second_to_last + sum_last) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void card_type_detector(long number)
{
    int card_length = 0;

    for (long counter = number; counter > 0; counter /= 10)
    {
        card_length++;
    }

    if (card_length > 12 && card_length < 17)
    {
        if (number / (long) 1e14 == 51 || number / (long) 1e14 == 52 || number / (long) 1e14 == 53 || number / (long) 1e14 == 54 ||
            number / (long) 1e14 == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (number / (long) 1e15 == 4)
        {
            printf("VISA\n");
        }

        else if (number / (long) 1e13 == 34 || number / (long) 1e13 == 37)
        {
            printf("AMEX\n");
        }
        else if (number / (long) 1e14 == 4)
        {
            printf("INVALID\n");
        }
        else if (number / (long) 1e12 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
