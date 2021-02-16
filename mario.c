#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //creates variable
    int height;

    do
    {
        //gets user input
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); //conditional statements foe height requirements
    for (int i = 1; i < height + 1; i++) //for every line...
    {
        for (int b = height; b > i; b--) //prints the spaces that come before the asterisk(s)
        {
            printf(" ");
        }
        for (int a = 1; a < i + 1; a++) //prints the asterisk(s)
        {
            printf("#");
        }
        printf("\n"); //new line
    }

}
