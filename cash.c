#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed:"); //gets change
    }
    while (dollars < 0 || dollars == 0); //conditional statements to prevent invalid change
    int cents = round(dollars * 100);
    int coins = 0;
    do
    {
        if (cents > 25 || cents == 25) //if it is big enough to bite off a quarter
        {
            coins++; //Add to the number of necessary coins
            cents = cents - 25; //Decrease cents 

        }
        else if (cents > 10 || cents == 10) //Dime
        {
            coins++;
            cents = cents - 10;

        }
        else if (cents > 5 || cents == 5) //Nickel
        {
            coins++;
            cents = cents - 5;

        }
        else if (cents > 1 || cents == 1) //Penny
        {
            coins++;
            cents = cents - 1;

        }
    }
    while (cents > 0); //Loop doesn't end until we bit off everything in cents
    printf("%d\n", coins); //Print coins added after loop
}