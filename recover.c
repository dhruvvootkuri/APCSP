#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r"); //Opens card.raw, the file we are working with

    if (argc != 2) //We want to check that there are only 2 arguments
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    if (file == NULL) //We want to make sure the file isn't null
    {
        printf("Could not open card.raw.\n");
        return 2;
    }

    unsigned char 
    buffer[BLOCK_SIZE]; //We create an array called buffer, which is used later to store information on the 512 byte blocks

    FILE *img = NULL; //This creates an image to be used later on

    int x = 0;
    int new_jpg = 0;

    while (fread(buffer, BLOCK_SIZE, 1, file) ==
           1) //While every block we take gives us a full block... (At the very end there are not as many bytes as we want)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0) //Checks for jpeg signature...
        {
            if (new_jpg == 1) //New_jpg checks if we got a jpeg file before or not, 1 being yes, 0 being no
            {
                fclose(img); //If we already found a jpeg, this statement has been run before, meaning the img file has been assigned a value.  Therefore, it is necessary to close the img file before writing to it once more
            }

            else
            {
                new_jpg = 1; //If we have never written to a jpeg before, now we have!
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", x);
            img = fopen(filename, "a"); //Here, we write a file for our jpeg, and assign it to img.  This will be written to later
            x++; //After every jpeg, we add 1 to our counter.  This counter is used for writing the names of the files.

        }

        if (new_jpg == 1) //THis is not necessarily for a jpeg.  It can be for any 512-byte block!
        {
            fwrite(&buffer, BLOCK_SIZE, 1,
                   img); //We now write in our buffer array data (which, using fread, now stores the data for the 512-byte block).
            //While some may not be able to be opened, as they are not jpeg's, only the jpeg files are displayed with sprintf
        }
    }
    fclose(file);
    fclose(img);

    return 0;
}


