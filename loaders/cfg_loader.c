#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int FLCN_MAX_LINE_LEN,
           FLCN_GLFW_SAMPLES,
           FLCN_AA,
           FLCN_VSYNC,
           FLCN_WIN_WIDTH,
           FLCN_WIN_HEIGHT,
           FLCN_DEBUG;

int flcn_load_config(void);

static int parse_buffer(char *buffer) {
    char *token;
    if (buffer && strlen(buffer) != 0 && buffer[0] == 'F') {
        token = strtok(buffer, " ");
        if (token) {
            if (!strcmp(token, "FLCN_AA"))
                FLCN_AA = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "FLCN_VSYNC"))
                FLCN_VSYNC = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "FLCN_GLFW_SAMPLES"))
                FLCN_GLFW_SAMPLES = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "FLCN_MAX_LINE_LEN"))
                FLCN_MAX_LINE_LEN = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "FLCN_WIN_WIDTH"))
                FLCN_WIN_WIDTH = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "FLCN_WIN_HEIGHT"))
                FLCN_WIN_HEIGHT = atoi(strtok(NULL, "="));
            else if (!strcmp(token, "FLCN_DEBUG"))
                FLCN_DEBUG = atoi(strtok(NULL, "="));
        }
    }
    return 0;
}

int flcn_load_config() {
    int c, i;
    char *buffer = malloc(100);
    FILE *config = fopen("falcon.cfg", "r");

    /* Default Values */
    FLCN_MAX_LINE_LEN = 509;
    FLCN_GLFW_SAMPLES = 4;
    FLCN_AA           = 1;
    FLCN_VSYNC        = 1;
    FLCN_DEBUG        = 0;

    if (!config)
        config = fopen("~/falcon.cfg", "r");
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
