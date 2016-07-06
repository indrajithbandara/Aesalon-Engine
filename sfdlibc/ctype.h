int islower(char c);
int isupper(char c);
int isalpha(char c);
int isdigit(char c);
int isalnum(char c);

char tolower(char c);
char toupper(char c);


int isdigit(char c) {
    return (c >= '0' && c <= '9');
}

int isalnum(char c) {
    return (isalpha(c) || isdigit(c));
}

int isalpha(char c) {
    return (islower(c) || isupper(c));
}

int islower(char c) {
    return (c >= 'a' && c <= 'z');
}

int isupper(char c) {
    return (c >= 'A' && c <= 'Z');
}

char tolower(char c) {
    if (isupper(c))
        return (c - 32);
    else
        return c;
}

char toupper(char c) {
    if (islower(c))
        return (c + 32);
    else
        return c;
}
