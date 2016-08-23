#include <stdlib.h>

int   sfd_strlen(const char *s);
char *sfd_strdup(const char *s);
char *sfd_strcat(const char *s1, const char *s2);

int sfd_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char *sfd_strdup(const char *s) {
    int i, sl = sfd_strlen(s);
    char *s2 = malloc((unsigned long)(sl + 1));
    for (i = 0; i <= sl; i++)
        s2[i] = s[i];
    return s2;
}

char *sfd_strcat(const char *s1, const char *s2) {
    int l1 = sfd_strlen(s1);
    char *s3 = malloc((unsigned long)(l1 + sfd_strlen(s2) + 1));
    char c;
    int i = 0;
    while ((c = s1[i]) != '\0')
        s3[i++] = c;
    while ((c = s2[i - l1]) != '\0')
        s3[i++] = c;
    s3[i] = '\0';
    return s3;
}
