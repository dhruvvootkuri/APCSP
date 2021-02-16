#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //char str[] = "strtok needs to be called several times to split a string";
    int x = 0;

    if (argc <= 1) //checks if key is given
    {
        printf("Usage: ./caesar key\n");
        x++;
        return 1;
    }

    if (argc > 2 && x == 0) //cheks if too many arguments are given
    {
        printf("Usage: ./caesar key\n");
        x++;
        return 1;
    }
    if (argc == 2) //checks if it is string
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z')) && x == 0)
            {

                printf("Usage: ./caesar key\n");
                x++;
                return 1;
            }
        }
        if (x == 0)
        {
            int key = atoi(argv[1]);
        }
    }
    if (x == 0)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        for (int j = 0; j < strlen(plaintext); j++)
        {
            char c = plaintext[j];
            if (isalpha(c)) //for all letters
            {
                if (isupper(c)) //for all uppercase letters
                {
                    c = c - 64;
                    c = (c + key) % 26;
                    c = c + 64;
                }
                else if (islower(c)) //for all lowercase letters
                {
                    c = c - 96;
                    c = (c + key) % 26;
                    c = c + 96;
                }
                //non-letters are not changed
            }
            plaintext[j] = c;
        }
        printf("ciphertext: %s\n", plaintext);
    }
}