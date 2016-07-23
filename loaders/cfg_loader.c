#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int ASLN_MAX_LINE_LEN,
           ASLN_GLFW_SAMPLES,
           ASLN_AA,
           ASLN_VSYNC,
           ASLN_WIN_WIDTH,
           ASLN_WIN_HEIGHT,
           ASLN_DEBUG;

int asln_load_config(void);

static int parse_buffer(char *buffer) {
    char *token;
    if (buffer && strlen(buffer) != 0 && buffer[0] == 'A') {
        token = strtok(buffer, " ");
        if (token) {
            if (!strcmp(token, "ASLN_AA"))
                ASLN_AA = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "ASLN_VSYNC"))
                ASLN_VSYNC = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "ASLN_GLFW_SAMPLES"))
                ASLN_GLFW_SAMPLES = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "ASLN_MAX_LINE_LEN"))
                ASLN_MAX_LINE_LEN = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "ASLN_WIN_WIDTH"))
                ASLN_WIN_WIDTH = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "ASLN_WIN_HEIGHT"))
                ASLN_WIN_HEIGHT = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "ASLN_DEBUG"))
                ASLN_DEBUG = atoi(strtok(NULL, "="));
        }
    }
    return 0;
}

int asln_load_config() {
    int c, i;
    char *buffer = malloc(100);
    FILE *config = fopen("aesalon.cfg", "r");

    /* Default Values */
    ASLN_MAX_LINE_LEN = 509;
    ASLN_GLFW_SAMPLES = 4;
    ASLN_AA           = 1;
    ASLN_VSYNC        = 1;
    ASLN_DEBUG        = 0;

    if (!config)
        config = fopen("~/aesalon.cfg", "r");
    if (config) {
        c = i = 0;
        while (c != EOF) {
            while ((c = fgetc(config)) != '\n' && c != EOF)
                buffer[i++] = (char)c;
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
