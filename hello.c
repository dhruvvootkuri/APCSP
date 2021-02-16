#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get name
    string name = get_string("What is your name?\n");

    //Prints name
    printf("Hello, %s\n", name);
}