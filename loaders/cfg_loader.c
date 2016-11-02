#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../input/binding.c"

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
            if      (strcmp(token, "ASLN_AA")           == 0) ASLN_AA           = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_VSYNC")        == 0) ASLN_VSYNC        = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_GLFW_SAMPLES") == 0) ASLN_GLFW_SAMPLES = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_MAX_LINE_LEN") == 0) ASLN_MAX_LINE_LEN = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_WIN_WIDTH")    == 0) ASLN_WIN_WIDTH    = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_WIN_HEIGHT")   == 0) ASLN_WIN_HEIGHT   = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_DEBUG")        == 0) ASLN_DEBUG        = atoi(strtok(NULL, "="));

            else if (strcmp(token, "BIND_KEY_A") == 0) asln_bind_key('A', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_B") == 0) asln_bind_key('B', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_C") == 0) asln_bind_key('C', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_D") == 0) asln_bind_key('D', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_E") == 0) asln_bind_key('E', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_F") == 0) asln_bind_key('F', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_G") == 0) asln_bind_key('G', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_H") == 0) asln_bind_key('H', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_I") == 0) asln_bind_key('I', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_J") == 0) asln_bind_key('J', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_K") == 0) asln_bind_key('K', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_L") == 0) asln_bind_key('L', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_M") == 0) asln_bind_key('M', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_N") == 0) asln_bind_key('N', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_O") == 0) asln_bind_key('O', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_P") == 0) asln_bind_key('P', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_Q") == 0) asln_bind_key('Q', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_R") == 0) asln_bind_key('R', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_S") == 0) asln_bind_key('S', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_T") == 0) asln_bind_key('T', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_U") == 0) asln_bind_key('U', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_V") == 0) asln_bind_key('V', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_W") == 0) asln_bind_key('W', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_X") == 0) asln_bind_key('X', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_Y") == 0) asln_bind_key('Y', strtok(NULL, "="));
            else if (strcmp(token, "BIND_KEY_Z") == 0) asln_bind_key('Z', strtok(NULL, "="));

            else if (strcmp(token, "BIND_LEFT_CLICK")  == 0) asln_bind_mbutton(1, strtok(NULL, "="));
            else if (strcmp(token, "BIND_RIGHT_CLICK") == 0) asln_bind_mbutton(2, strtok(NULL, "="));
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
    printf("\n | Debugging:\t\t%d\n | Anti-Aliasing:\t%d\n | V-Sync:\t\t%d\n | Resolution:\t\t%d x %d\n", ASLN_DEBUG, ASLN_AA, ASLN_VSYNC, ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT);
    return -1;
}
