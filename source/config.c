/* config.c - This file is part of Aesalon, a simple, lightweight 3D game engine written in ANSI C.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Aesalon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Aesalon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Aesalon.  If not, see <http://www.gnu.org/licenses/>.
 */

int asln_load_config(void);
void asln_print_config(void);
static int parse_buffer(char *);

int asln_config_load() {
    FILE *config;
    asln_config = malloc(sizeof(ASLN_CONFIG));

    puts("Setting Default Config Values...");
    asln_config->api               = 1;
    asln_config->debug             = 0;
    asln_config->max_shader_length = 509;
    asln_config->max_audio_buffers = 100;
    asln_config->max_audio_sources = 100;
    asln_config->max_line_length   = 509;
    asln_config->samples           = 4;
    asln_config->antialiasing      = 1;
    asln_config->vsync             = 1;

    puts("Opening Config File...");
    if (((config = fopen("aesalon.cfg", "r")) != NULL) || ((config = fopen("~/aesalon.cfg", "r")) != NULL)) {
        int c, i = 0;
        char *buffer = malloc(asln_config->max_line_length);
        puts("Reading Values...");
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
        free(buffer);
        puts("Closing Config File...");
        fclose(config);
        puts("Printing Config Values...\n");
        asln_print_config();
    } else
        puts("Unable to Open Any Config File, Using Defaults Instead");
    return 0;
}

void asln_print_config() {
    printf(
        "\n  {-------|asln_config|-------}\n"
        "  =============================\n"
        "  | api               | %5d |\n"
        "  | debug             | %5d |\n"
        "  | max_shader_length | %5d |\n"
        "  | max_audio_buffers | %5d |\n"
        "  | max_audio_sources | %5d |\n"
        "  | max_line_length   | %5d |\n"
        "  | samples           | %5d |\n"
        "  | antialiasing      | %5d |\n"
        "  | vsync             | %5d |\n"
        "  =============================\n\n",
        asln_config->api,
        asln_config->debug,
        asln_config->max_shader_length,
        asln_config->max_audio_buffers,
        asln_config->max_audio_sources,
        asln_config->max_line_length,
        asln_config->samples,
        asln_config->antialiasing,
        asln_config->vsync
    );
}

static int parse_buffer(char *buffer) {
    char *token;
    if (buffer && strlen(buffer) != 0 && buffer[0] == 'A') {
        token = strtok(buffer, " ");
        if (token) {
            if      (strcmp(token, "ASLN_AA")           == 0) asln_config->antialiasing    = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_VSYNC")        == 0) asln_config->vsync           = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_GLFW_SAMPLES") == 0) asln_config->samples         = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_MAX_LINE_LEN") == 0) asln_config->max_line_length = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_WIN_WIDTH")    == 0) asln_config->win_width       = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_WIN_HEIGHT")   == 0) asln_config->win_height      = atoi(strtok(NULL, "="));
            else if (strcmp(token, "ASLN_DEBUG")        == 0) asln_config->debug           = atoi(strtok(NULL, "="));

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
