char * strdup(char *s) {
    int count = 0;
    char c = s[0];
    while (c != '\0') {
        count++;
        c = s[count];
    }
    char *s2 = malloc(count);
    int j = 0;
    for (; j < count; j++)
        s2[j] = s[j];
    return s2;
}
