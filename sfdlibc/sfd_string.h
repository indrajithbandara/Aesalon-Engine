int   sfd_strlen(const char *s);
char *sfd_strdup(const char *s);


int sfd_strlen(const char *s) {
    int i;
    while (s[i] != '\0')
        i++;
    return i;
}

char *sfd_strdup(const char *s) {
    int i, sl = sfd_strlen(s);
    char *s2 = malloc(sl + 1);
    for (i = 0; i <= sl; i++)
        s2[i] = s[i];
    return s2;
}
