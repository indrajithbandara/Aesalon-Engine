#include <stdio.h>
#include <stdlib.h>
#include "../sfdlibc/sfd_string.h"
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
    if (buffer && sfd_strlen(buffer) != 0 && buffer[0] == 'A') {
        token = sfd_strtok(buffer, " ");
        if (token) {
            if      (sfd_streql(token, "ASLN_AA"))           ASLN_AA           = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_VSYNC"))        ASLN_VSYNC        = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_GLFW_SAMPLES")) ASLN_GLFW_SAMPLES = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_MAX_LINE_LEN")) ASLN_MAX_LINE_LEN = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_WIN_WIDTH"))    ASLN_WIN_WIDTH    = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_WIN_HEIGHT"))   ASLN_WIN_HEIGHT   = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_DEBUG"))        ASLN_DEBUG        = atoi(sfd_strtok(NULL, "="));

            else if (sfd_streql(token, "BIND_KEY_A")) asln_bind_key('A', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_B")) asln_bind_key('B', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_C")) asln_bind_key('C', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_D")) asln_bind_key('D', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_E")) asln_bind_key('E', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_F")) asln_bind_key('F', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_G")) asln_bind_key('G', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_H")) asln_bind_key('H', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_I")) asln_bind_key('I', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_J")) asln_bind_key('J', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_K")) asln_bind_key('K', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_L")) asln_bind_key('L', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_M")) asln_bind_key('M', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_N")) asln_bind_key('N', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_O")) asln_bind_key('O', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_P")) asln_bind_key('P', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_Q")) asln_bind_key('Q', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_R")) asln_bind_key('R', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_S")) asln_bind_key('S', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_T")) asln_bind_key('T', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_U")) asln_bind_key('U', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_V")) asln_bind_key('V', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_W")) asln_bind_key('W', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_X")) asln_bind_key('X', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_Y")) asln_bind_key('Y', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_Z")) asln_bind_key('Z', sfd_strtok(NULL, "="));

            else if (sfd_streql(token, "BIND_LEFT_CLICK"))  asln_bind_mbutton(1, sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_RIGHT_CLICK")) asln_bind_mbutton(2, sfd_strtok(NULL, "="));
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
