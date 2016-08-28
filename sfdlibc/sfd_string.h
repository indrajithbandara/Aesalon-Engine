#include <stdlib.h>
#include <string.h>
#include "sfd_ctype.h"

int sfd_streql(const char*, const char*);
int sfd_streql_ct(const char*, const char*);
int sfd_strlen(const char*);

char *sfd_strdup(const char*);
char *sfd_strcat(const char*, const char*);
char *sfd_strlow(const char*);
char *sfd_strtok(char*, const char*);
char *sfd_strupp(const char*);

int sfd_streql(const char *s1, const char *s2) {
    int i, l = sfd_strlen(s1);
    if (l != sfd_strlen(s2))
        return 0;
    for (i = 0; i < l; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}

int sfd_streql_ct(const char *s1, const char *s2) {
    int i, eql = 1;
    int l1 = sfd_strlen(s1);
    int l2 = sfd_strlen(s2);
    int l  = (l1 > l2) ? l1 : l2;
    for (i = 0; i < l; i++)
        if (s1[i] != s2[i])
            eql = 0;
    return eql;
}

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

char *sfd_strlow(const char *s) {
    int i, l = sfd_strlen(s);
    char *s1 = malloc(l + 1);
    for (i = 0; i < l; i++)
        s1[i] = sfd_tolower(s[i]);
    s1[i + 1] = '\0';
    return s1;
}

char *sfd_strtok(char *s, const char *d) {
    /* Temp until implemented */
    return strtok(s, d);
}

char *sfd_strupp(const char *s) {
    int i, l = sfd_strlen(s);
    char *s1 = malloc(l + 1);
    printf("%d\n", l);
    for (i = 0; i < l; i++)
        s1[i] = sfd_toupper(s[i]);
    s1[i + 1] = '\0';
    return s1;
}
