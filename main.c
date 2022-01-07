#include "main.h"

// Global variables
char secretword[20];
int attempts = 0;
char kicks[26];

int main() {
    sprintf(secretword, "Black Hole");

    do {
        print_hangman();
        kick();
    } while(!won() && !hanged());

    printf("secretword: %s\n", secretword);
}

void print_hangman() {
    for (int i = 0; i < strlen(secretword); i++)
    {
        char letter = secretword[i];
        if (!has_letter_in_kicks(letter))
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

bool has_letter_in_kicks(const char letter) {
    for (int j = 0; j < strlen(kicks); j++)
    {
        if (kicks[j] == letter)
        {
            return true;
        }
    }
    return false;
}

void kick() {
    char letter;
    printf("Enter a letter: ");
    scanf(" %c", &letter);
    fflush(stdin);

    if (!already_kicked(letter)) {
        kicks[attempts] = letter;
        attempts++;
    }
}

bool already_kicked(const char letter) {
    for (int i = 0; i < strlen(kicks); i++)
    {
        if (kicks[i] == letter)
        {
            return true;
        }
    }
    return false;
}

bool won() {
    for (int i = 0; i < strlen(secretword); i++)
    {
        if (!has_letter_in_kicks(secretword[i]) && secretword[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

bool hanged() {
    int failed_attempts = 0;
    for (int i = 0; i < strlen(kicks); i++)
    {
        if(!has_letter_in_secretword(kicks[i]))
        {
            failed_attempts++;
        }
    }

    return failed_attempts > 4;
}

bool has_letter_in_secretword(const char letter) {
    for (int j = 0; j < strlen(secretword); j++)
    {
        if (secretword[j] == letter)
        {
            return true;
        }
    }
    return false;
}