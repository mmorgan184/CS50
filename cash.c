#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    // prompting the user for how much change is owed
    int cents;
    do
    {
        cents = get_int("Change Owed: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    // take 25 away as many times as necessary until cents is less than 25
    // count how many times the loop iterates
    int quarters = 0;
    while (cents > 24)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // TODO
    // take 10 away as many times as necessary until cents is less than 10
    // count how many times the loop iterates
    int dimes = 0;
    while (cents > 9)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // TODO
    // take 5 away as many times as necessary until cents is less than 5
    // count how many times the loop iterates
    int nickels = 0;
    while (cents > 4)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // TODO
    // take 1 away as many times as necessary until cents is 0
    // count how many times the loop iterates
    int pennies = 0;
    while (cents > 0)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
