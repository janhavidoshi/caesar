#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Reference
string caesar(string plaintext, int k);

// Return explicit key from Main

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!(key[i] >= 48 && key[i] <= 57))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
    int k = atoi(key);
    if (k <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }
    else
    {
        string plaintext = get_string("plaintext: ");
        string ciphertext = caesar(plaintext, k);
        printf("ciphertext:%s\n", ciphertext);
        return 0;
    }
}

//Defining function ceasar

string caesar(string plaintext, int k)
{
    int n = strlen(plaintext);
    string ciphertext = plaintext;
    for (int i = 0; i < n; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') // Converting lowercase letters
        {
            ciphertext[i] = ((plaintext[i] - 96 + k) % 26) + 96;
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') // Converting uppercase letters
        {
            ciphertext[i] = ((plaintext[i] - 64 + k) % 26) + 64;
        }
        else // Other characters to remain the same
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}
