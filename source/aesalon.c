/* aesalon.c - This file is part of Aesalon, a simple, lightweight 3D game engine written in ANSI C.
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
 
#define ASLN_VERSION    "0.85"
#define ASLN_GAME_TITLE "Aesalon Engine"

/* #define GLFW_INCLUDE_VULKAN */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <AL/al.h>
#include <AL/alc.h>

#include "../sfdlibs/files/filetypes/sfd_libwav.c"
#include "asln_structs.c"

ASLN_STATE  *asln_state;
ASLN_CONFIG *asln_config;
ASLN_AUDIO  *asln_audio;

#include "asln_input.c"
#include "asln_config.c"
#include "asln_graphics.c"
#include "asln_audio.c"

void asln_shutdown() {
    asln_audio_cleanup();
    puts("\nExiting");
    glfwTerminate();
}

static void error_callback(int err, const char *desc) {
    fprintf(stderr, "  GLFW Error %d: %s\n", err, desc);
}

int main(int argc, char *argv[]) {
    asln_state = malloc(sizeof(ASLN_STATE));
    printf("\nAesalon Game Engine Version %s\n\n\n", ASLN_VERSION);
    glfwSetErrorCallback(error_callback);
    asln_config_load();
    asln_graphics_init();
    asln_input_init();
    asln_audio_init();
    asln_state->paused = 0;
    while (!glfwWindowShouldClose(asln_state->window)) {
        if (!asln_state->paused)
            asln_graphics_render();
        glfwPollEvents();
    }
    /*
    } else
        puts("Vulkan Support Not Detected");
    */
    asln_shutdown();
    return 0;
}
