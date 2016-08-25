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
            if      (sfd_streql(token, "ASLN_AA")           == 0) ASLN_AA           = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_VSYNC")        == 0) ASLN_VSYNC        = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_GLFW_SAMPLES") == 0) ASLN_GLFW_SAMPLES = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_MAX_LINE_LEN") == 0) ASLN_MAX_LINE_LEN = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_WIN_WIDTH")    == 0) ASLN_WIN_WIDTH    = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_WIN_HEIGHT")   == 0) ASLN_WIN_HEIGHT   = atoi(sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "ASLN_DEBUG")        == 0) ASLN_DEBUG        = atoi(sfd_strtok(NULL, "="));

            else if (sfd_streql(token, "BIND_KEY_A") == 0) alsn_bind_key('A', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_B") == 0) alsn_bind_key('B', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_C") == 0) alsn_bind_key('C', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_D") == 0) alsn_bind_key('D', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_E") == 0) alsn_bind_key('E', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_F") == 0) alsn_bind_key('F', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_G") == 0) alsn_bind_key('G', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_H") == 0) alsn_bind_key('H', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_I") == 0) alsn_bind_key('I', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_J") == 0) alsn_bind_key('J', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_K") == 0) alsn_bind_key('K', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_L") == 0) alsn_bind_key('L', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_M") == 0) alsn_bind_key('M', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_N") == 0) alsn_bind_key('N', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_O") == 0) alsn_bind_key('O', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_P") == 0) alsn_bind_key('P', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_Q") == 0) alsn_bind_key('Q', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_R") == 0) alsn_bind_key('R', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_S") == 0) alsn_bind_key('S', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_T") == 0) alsn_bind_key('T', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_U") == 0) alsn_bind_key('U', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_V") == 0) alsn_bind_key('V', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_W") == 0) alsn_bind_key('W', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_X") == 0) alsn_bind_key('X', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_Y") == 0) alsn_bind_key('Y', sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_KEY_Z") == 0) alsn_bind_key('Z', sfd_strtok(NULL, "="));

            else if (sfd_streql(token, "BIND_LEFT_CLICK")  == 0) alsn_bind_mbutton(1, sfd_strtok(NULL, "="));
            else if (sfd_streql(token, "BIND_RIGHT_CLICK") == 0) alsn_bind_mbutton(2, sfd_strtok(NULL, "="));
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
