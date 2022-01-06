#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool has_letter(const char *kicks, const char letter) {
    for (int j = 0; j < strlen(kicks); j++)
    {
        if (kicks[j] == letter)
        {
            return true;
        }
    }
    return false;
}

void print_hangman(const char *kicks, const char *secretword) {
    for (int i = 0; i < strlen(secretword); i++)
    {
        char letter = secretword[i];
        if (!has_letter(kicks, letter))
        {
            if (letter == ' ')
            {
                printf(" ");
            }
            else
            {
                printf("_ ");
            }
        }
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");
}

void kick(char * kicks, int attempts) {
    char letter;
    printf("Enter a letter: ");
    scanf(" %c", &letter);
    fflush(stdin);

    kicks[attempts] = letter;
}

int main() {

    char secretword[20];

    sprintf(secretword, "Black Hole");

    bool won = false;
    bool hanged = false;
    int attempts = 0;
    char kicks[26];

    do {
        print_hangman(kicks, secretword);

        kick(kicks, attempts);

        if(attempts == 25) {
            hanged = true;
        } else {
            attempts++;
        }
    } while(!won && !hanged);

    printf("secretword: %s\n", secretword);
}