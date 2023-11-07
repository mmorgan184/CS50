#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string s = get_string("Text: ");

    // count letters, words, and sentences
    float letters = count_letters(s);
    float words = count_words(s);
    float sentences = count_sentences(s);

    // calculate the coleman-liau formula-
    int coleman = round(0.0588 * (100.0 * letters / words) - 0.296 * (100.0 * sentences / words) - 15.8);

    if (coleman >= 16)
    {
            printf("Grade 16+\n");
    }
    else if (coleman < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", coleman);
    }
}
int count_letters(string s)
{
    int count = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(isalpha(s[i]))
        {
            count++;
        }
    }
    return count;
}
int count_words(string s)
{
    int count = 0;
    for(int i = 1; i < strlen(s); i++)
    {
        if(s[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}
int count_sentences(string s)
{
    int count = 0;
    for(int i = 1; i<strlen(s); i++)
    {
        if(s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            count++;
        }
    }
    return count;
}
