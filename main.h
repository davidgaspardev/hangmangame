#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void print_hangman();
bool has_letter_in_kicks(const char letter);
void kick();
bool already_kicked(const char letter);
bool won();
bool hanged();
bool has_letter_in_secretword(const char letter);