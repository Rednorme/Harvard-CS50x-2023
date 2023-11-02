#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float coleman_liau_index(int words, int letters, int sentences);

int main(void)
{
    string sentence = get_string("Text: ");

    int amount_of_words = 0;
    int amount_of_sentences = 0;
    int amount_of_letters = 0;

    for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        if (islower(sentence[i]) || isupper(sentence[i]))
        {
            amount_of_letters++;
        }

        if (sentence[i] == ' ' || sentence[i + 1] == '\0')
        {
            amount_of_words++;
        }

        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            amount_of_sentences++;
        }
    }

    int grade = round(coleman_liau_index(amount_of_words, amount_of_letters, amount_of_sentences));

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

float coleman_liau_index(int words, int letters, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    return 0.0588 * L - 0.296 * S - 15.8;
}
