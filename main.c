#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char secretword[20];

    sprintf(secretword, "Black Hole");

    bool won = false;
    bool hanged = false;
    int attempts = 0;
    char letter;
    char kicks[26];

    do {
        for (int i = 0; i < strlen(secretword); i++)
        {
            bool has_letter = false;
            for (int j = 0; j < strlen(kicks); j++)
            {
                if (kicks[j] == secretword[i])
                {
                    printf("%c", kicks[j]);
                    has_letter = true;
                    break;
                }
            }
            if (!has_letter)
            {
                if (secretword[i] == ' ')
                {
                    printf(" ");
                }
                else
                {
                    printf("_ ");
                }
            }
        }
        printf("\n");

        printf("Enter a letter: ");
        scanf(" %c", &letter);
        fflush(stdin);

        kicks[attempts] = letter;

        if(attempts == 25) {
            hanged = true;
        } else {
            attempts++;
        }
    } while(!won && !hanged);

    printf("secretword: %s\n", secretword);
}