#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_usage()
{
    printf("Usage: ./caesar key\n");
}

int main(int argc, string argv[])
{
    char *endptr;
    //Check the command line argument
    if (argc != 2)
    {
        print_usage();
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            print_usage();
            return 1;
        }
    }

    // Convert a string to int
    int key = atoi(argv[1]);
    if (key < 0)
    {
        print_usage();
        return 1;
    }


    // Prompt user for plaintext
    string s = get_string("plaintext: ");

    //Print output ciphertext
    printf("ciphertext: ");


    // Check for lowercase, uppercase and not-alphabetical characters
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isupper(s[i]))
        {
            printf("%c", (s[i] - 65 + key) % 26 + 65);
        }

        else if (islower(s[i]))
        {
            printf("%c", (s[i] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
