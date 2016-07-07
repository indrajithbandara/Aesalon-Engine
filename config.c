#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_buffer(char *buffer) {
    extern int FLCN_AA, FLCN_GLFW_SAMPLES, FLCN_MAX_LINE_LEN;
    char *token;
    if (buffer && strlen(buffer) != 0 && buffer[0] == 'F') {
        token = strtok(buffer, " ");
        if (token) {
            if (!strcmp(token, "FLCN_AA"))
                FLCN_AA = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "FLCN_GLFW_SAMPLES"))
                FLCN_GLFW_SAMPLES = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "FLCN_MAX_LINE_LEN"))
                FLCN_MAX_LINE_LEN = atoi(strtok(NULL, "="));
        }
    }
    return 0;
}

int flcn_load_config() {
    int c, i;
    char *buffer = malloc(100);
    FILE *config = fopen("falcon.conf", "r");
    c = i = 0;
    if (config) {
        while (c != EOF) {
            while ((c = fgetc(config)) != '\n' && c != EOF)
                buffer[i++] = c;
            if (i < 100) {
                buffer[i] = '\0';
                parse_buffer(buffer);
                i = 0;
            } else {
                fclose(config);
                break;
            }
        }
        fclose(config);
    }
    free(buffer);
    return -1;
}
