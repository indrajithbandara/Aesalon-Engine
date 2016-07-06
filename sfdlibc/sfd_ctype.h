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


int sfd_isalnum(char c) {
    return (sfd_isalpha(c) || sfd_isdigit(c));
}

int sfd_isalpha(char c) {
    return (sfd_islower(c) || sfd_isupper(c));
}

int sfd_isdigit(char c) {
    return (c >= '0' && c <= '9');
}

int sfd_islower(char c) {
    return (c >= 'a' && c <= 'z');
}

int sfd_isprint(char c) {
    return (c >= 32 && c <= 126);
}

int sfd_ispunct(char c) {
    return (((c >= 33)  && (c <= 47)) ||
            ((c >= 58)  && (c <= 64)) ||
            ((c >= 91)  && (c <= 96)) ||
            ((c >= 123) && (c <= 126)));
}

int sfd_isspace(char c) {
    return (c == ' ' || ((c >= 9) && (c <= 13)));
}

int sfd_isupper(char c) {
    return (c >= 'A' && c <= 'Z');
}


char sfd_tolower(char c) {
    return (sfd_isupper(c)) ? (c - 32) : c;
}

char sfd_toupper(char c) {
    return (sfd_islower(c)) ? (c + 32) : c;
}
