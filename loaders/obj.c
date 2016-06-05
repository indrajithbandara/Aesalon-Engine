#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline(FILE *file) {
    int c = fgetc(file);
    if (c != EOF) {
        char *s = malloc(1000);
        int i = 0;
        while (c != '\n' && c != EOF) {
            s[i++] = c;
            c = fgetc(file);
        }
        s[i] = '\0';
        return s;
    }
    return "EOF";
}


int loadModel(char *filename) {
    FILE *obj = fopen(filename, "r");
    if (obj == NULL)
        return -1;
    char *ayy;
    while(strcmp((ayy = readline(obj)), "EOF") != 0)
        puts(ayy);
    return 0;
}

int main() {
    loadModel("obj.c");
    return 0;
}
