#include <stdio.h>
#include <ctype.h>
#include "../sfd_ctype.h"

int sfd_isalnum(char c);
int sfd_isalpha(char c);
int sfd_isdigit(char c);
int sfd_islower(char c);
int sfd_isprint(char c);
int sfd_ispunct(char c);
int sfd_isspace(char c);
int sfd_isupper(char c);

char sfd_tolower(char c);
char sfd_toupper(char c);

int main() {
    char c;

    puts("Testing isalnum...");
    for (c = 0; c < 127; c++)
        printf("Testing isalnum: %6d, %6d = %6d : %s\n", c, isalnum(c), sfd_isalnum(c), ((isalnum(c) == sfd_isalnum(c)) || ((isalnum(c) > 0) && (sfd_isalnum(c) > 0))) ? "Pass" : "Fail");

    puts("Testing isalpha...");
    for (c = 0; c < 127; c++)
        printf("Testing isalpha: %6d, %6d = %6d : %s\n", c, isalpha(c), sfd_isalpha(c), ((isalpha(c) == sfd_isalpha(c)) || ((isalpha(c) > 0) && (sfd_isalpha(c) > 0))) ? "Pass" : "Fail");

    puts("Testing isdigit...");
    for (c = 0; c < 127; c++)
        printf("Testing isdigit: %6d, %6d = %6d : %s\n", c, isdigit(c), sfd_isdigit(c), ((isdigit(c) == sfd_isdigit(c)) || ((isdigit(c) > 0) && (sfd_isdigit(c) > 0))) ? "Pass" : "Fail");

    puts("Testing islower...");
    for (c = 0; c < 127; c++)
        printf("Testing islower: %6d, %6d = %6d : %s\n", c, islower(c), sfd_islower(c), ((islower(c) == sfd_islower(c)) || ((islower(c) > 0) && (sfd_islower(c) > 0))) ? "Pass" : "Fail");

    puts("Testing isprint...");
    for (c = 0; c < 127; c++)
        printf("Testing isprint: %6d, %6d = %6d : %s\n", c, isprint(c), sfd_isprint(c), ((isprint(c) == sfd_isprint(c)) || ((isprint(c) > 0) && (sfd_isprint(c) > 0))) ? "Pass" : "Fail");

    puts("Testing ispunct...");
    for (c = 0; c < 127; c++)
        printf("Testing ispunct: %6d, %6d = %6d : %s\n", c, ispunct(c), sfd_ispunct(c),  ((ispunct(c) == sfd_ispunct(c)) || ((ispunct(c) > 0) && (sfd_ispunct(c) > 0))) ? "Pass" : "Fail");

    puts("Testing isspace...");
    for (c = 0; c < 127; c++)
        printf("Testing isspace: %6d, %6d = %6d : %s\n", c, isspace(c), sfd_isspace(c),  ((isspace(c) == sfd_isspace(c)) || ((isspace(c) > 0) && (sfd_isspace(c) > 0))) ? "Pass" : "Fail");

    puts("Testing isupper...");
    for (c = 0; c < 127; c++)
        printf("Testing isupper: %6d, %6d = %6d : %s\n", c, isupper(c), sfd_isupper(c), ((isupper(c) == sfd_isupper(c)) || ((isupper(c) > 0) && (sfd_isupper(c) > 0))) ? "Pass" : "Fail");



    puts("Test Complete");
}
