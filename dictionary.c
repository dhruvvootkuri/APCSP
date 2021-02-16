//In dictionary.c, I created 5 functions that help to create a spell - checker.
//While none of these functions are called in this file, it is used in another that was made by the course.
//My objective in this code was to load in a "dictionary", which was a text file of a bunch of words, and scan another text file to check if there were any words in that file that weren't in the dictionary.  If that were to occur, it would be considered misspelled.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> //These are just a bunch of libraries I needed in this file

#include "dictionary.h" //dictionary.h was just a file that defined all the functions I will be using.

//This is a datatype I created called a node.  This node is used for my hash table.

typedef struct node
{
    char word[LENGTH + 1]; //Word is the word the node will be storing. My hash table will be used to load in the dictionary, so each node uses a word.
    struct node *next; //Next is an address of another node.
    //Now would be a good idea to explain my concept for the hash table.
    //My hash table is an array of addresses to nodes.  These nodes that the elements in the array point to would have a word, and an address to another node.
    //You know what the word is for, but the next variable is used to store another node, with another node.
    //There are only so many spots in my array, and my hash function may put two words under one element.
    //However, two words can't be stored under one element, and a multidimensional array wouldn't work because we don't know how many words could get into a collision!
    //So, here was my solution.  If a word were to be inserted into an element, the element would then become the address to a node that contains the word.
    //If the number of words under that same element grows, then we could just create a linked list, where the element has an address to one node, that node's next attribute has an address to another node, and so on!

}
node;

FILE *file; //This is the file that I defined which will be used for my dictionary.

// Number of buckets in hash table
const unsigned int N = (LENGTH * 26) + 1; //This is how many elements I will be having in my list.  I chose this specific value because of how my hash function works.
//(The function will be explained later :D )

//For my hash table, I created an array called table that had elements of type node.
node *table[N];

int size_count = 0; //Size count is used later as a counter to determine how many words are in my dictionary.


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int length = strlen(word); //Length is just the length of the word given
    char copy[length + 1]; // take a byte extra for null terminating character
    copy[length] = '\0'; //In the very end, we want a null terminating character.


    char lower_word[LENGTH + 1]; //Lower_word is a variable that stores the given word in all lowercase.
    for (int j = 0; j < LENGTH; j++)
    {
        lower_word[j] = 0; //We just make this for loop so this lower_word has some placeholder values.
    }

    //decapatalize words in text
    for (int i = 0; i < length; i++)
    {
        lower_word[i] = tolower(word[i]); //We change every character in lower_word to the lowercase of the given word
    }

    node *node_checker = table[hash(word)]; //Basically, I created a hash function that gives us an integer for which element we should reference.
    //How it works will be explained later, but all you need to know for now is that we used it to figure out which linked list we will find the word in if it were in the dictionary.

    while (node_checker != NULL) //Basically, we are going into a loop that goes down the linked list, and keeps checking if we found the word.
    //However, if node_checker goes down the line, and it reached the end before the code returned true, then the next attribute would be null.
    //This means that at if node_checker = node_checker->next and node_checker-> is null, we know we reached the end!
    {
        if (strcasecmp(node_checker->word, word) == 0) //Only if the words match do we return true and end the function.
        {
            return true;
        }
        else //If not, keep moving down the line!
        {
            node_checker = node_checker->next;
        }
    }
    return false; //If we went through the whoel line and still the code didn't end from a return true, we can only assume the word isn't in the dictionary.

}

// Hashes word to a number
unsigned int hash(const char *word) //For the moment you have been waiting for, the HASH FUNCTION.  The hash function gives us an integer that is used to reference the element in the array that the word is suppsoed to go under.
{
    int sum = 0;
    int ascii = 0;
    //Here's my logic: I take every letter and convert it to a number, like A/a = 1, B/b = 2, C/c = 3, and so on.
    //Next, I add them all together and that's my answer!
    for (int i = 0; i < strlen(word); i++)
    {
        if ((int)word[i] == 39) //To account for apostrophe's, I stated that if it has the ascii value of an apostrophe, it is supposeed to have an ascii value of 26.
        //I chose 26 instead of 39 because I made the array (LENGTH * 26) as its size because that is the maximum value a word should be given.
        //If the word has the max length of 45 and it is all Z/z, the highest character in the alphabet, should it give LENGTH*26.
        //Throwing an apostrophe in there with a higher value would cause problems.
        {
            ascii = 26;
        }
        else if (((int)word[i] >= 97) && ((int)word[i] <= 122)) //I accounted for lowercase and uppercase in these else ifs.
        {
            ascii = (int) word[i] - 96;
        }
        else if (((int)word[i] >= 65) && ((int)word[i] <= 90))
        {
            ascii = (int) word[i] - 64;
        }
        sum = sum + ascii; //I add them to my sum...
    }

    return sum;
}



// Here is where I load in my dictionary.  The dictionary is EXTREMELY long, which is why I needed to make this hash table.
bool load(const char *dictionary)
{
    file = fopen(dictionary, "r"); //This function is called in another file, as I explained previously, and it gives an argument that is the name of the dictionary file.
    //file opens this dictionary up.
    if (file == NULL) //Basically, if dictionary is empty or has some sort of issue that mkaes it null, we automatically know we cannot load it in.
    {
        return false;
    }

    char wordc[LENGTH + 1]; //Here, I define a word called wordc.  It would be of size LENGTH+1 because that is the max number of characters it can be.

    while (fscanf(file, "%s", wordc) != EOF) //Here, we take every single word in our file, and put it into wordc, until we get to EOF(end of file)
    {
        node *n = malloc(sizeof(node)); //n is the node we will be using to insert wordc into our table.
        if (n == NULL) //If n were null, that means e don't have enough memory for the dictionary, and we failed.
        //However, if n were not null, it would be storing the address of a node by now.
        {
            fclose(file);
            return false;
        }
        else //If n isn't null...
        {
            strcpy(n->word, wordc); //We copy in wordc to n->word, so it will be stored in that node whenever we need to retrieve it.
            n->next = NULL; //As you may recall, the next attribute of n is an address. For now, we don't have an address, so let's make it null.

            unsigned int index = hash(wordc); //Here we run our hash function to determine which linked list n should be in, based on the word, wordc.

            n->next = table[index]; //Now, what I have done to insert it is that I made the value of n->next hold the value of the element in the table.
            //The element in the table would either be holding an address of another node, or it is null, as no word has needed to go there.
            table[index] = n; //In case there were nodes in the linked list already, we now have two values pointing to the first node in the linked list.
            //Now, we can make the value of table[index] the address of n without worrying about orphaning the other elements in the linked list.

            size_count++; //You may recall size-count, which I defined earlier in the code.  It is used to count all the words in our dictionary.
        }
    }
    fclose(file); //We close the file, as it is unused, and we don't want to waste memory.
    return true; //If we've gotten this far without an error or false being returned, I think it's safe to say we loaded everything successfully.
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_count; //We used this in load.  We now just return it in this function.
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++) //We unload the linked list under every element in the array.
    {
        node *node_checker = table[i]; //Node_checker is a placeholder value that holds the value of table[i]

        while (node_checker != NULL) //If node_checker does become null, that means we have gone through the whole linked list.
        {
            node *checker2 = node_checker; //This is another temporary node, necessary to prevent orphaning of the other nodes in the list.
            node_checker = node_checker->next; //Now that node_checker is now equal to the next node in the list, checker2 is now able to free itself.
            //That is because the other nodes are not orphaned anymore.
            //We have node_checker, which is the first node in our list, which is all we need to keep everything unorphaned.
            //Now, whenever checker2, which is right before node_checker now, can free, or "delete" the previous node.
            free(checker2);
        }
    }
    return true; //If we got all the way through this with no errors, we can return true.
}
