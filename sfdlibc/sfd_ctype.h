int sfd_isalnum(const char c);
int sfd_isalpha(const char c);
int sfd_isdigit(const char c);
int sfd_islower(const char c);
int sfd_isprint(const char c);
int sfd_ispunct(const char c);
int sfd_isspace(const char c);
int sfd_isupper(const char c);

char sfd_tolower(const char c);
char sfd_toupper(const char c);


int sfd_isalnum(const char c) {
    return (sfd_isalpha(c) || sfd_isdigit(c));
}

int sfd_isalpha(const char c) {
    return (sfd_islower(c) || sfd_isupper(c));
}

int sfd_isdigit(const char c) {
    return (c >= '0' && c <= '9');
}

int sfd_islower(const char c) {
    return (c >= 'a' && c <= 'z');
}

int sfd_isprint(const char c) {
    return (c >= 32 && c <= 126);
}

int sfd_ispunct(const char c) {
    return (((c >= 33)  && (c <= 47)) ||
            ((c >= 58)  && (c <= 64)) ||
            ((c >= 91)  && (c <= 96)) ||
            ((c >= 123) && (c <= 126)));
}

int sfd_isspace(const char c) {
    return (c == ' ' || ((c >= 9) && (c <= 13)));
}

int sfd_isupper(const char c) {
    return (c >= 'A' && c <= 'Z');
}


char sfd_tolower(const char c) {
    return (sfd_isupper(c)) ? (c + 32) : c;
}

char sfd_toupper(const char c) {
    return (sfd_islower(c)) ? (c - 32) : c;
}
