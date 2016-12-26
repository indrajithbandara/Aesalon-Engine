#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <AL/al.h>
#include <AL/alc.h>

#include "globals.h"

#include "sfdlibs/sfdlib_wav.c"
#include "sfdlibs/sfdlib_bmp.c"

#include "cli.c"
#include "logger.c"
#include "input.c"
#include "config.c"
#include "graphics.c"
#include "audio.c"

void asln_shutdown() {
    if (ASLN_AUDIO_CONTEXT != NULL) {
        alcMakeContextCurrent(NULL);
        alcDestroyContext(ASLN_AUDIO_CONTEXT);
    }
    if (ASLN_AUDIO_DEV != NULL)
        alcCloseDevice(ASLN_AUDIO_DEV);
    if (ASLN_WINDOW != NULL)
        glfwDestroyWindow(ASLN_WINDOW);
    glfwTerminate();
}

int main(int argc, char *argv[]) {
    printf("%s | Aesalon Game Engine %s |%s\n\n", RED, VERSION, RESET);
    asln_logger_clear();
    asln_config_load();
    asln_graphics_init();
    asln_graphics_splash();
    asln_input_init();
    asln_audio_init();
    while (!glfwWindowShouldClose(ASLN_WINDOW)) {
        if (!ASLN_PAUSED)
            asln_graphics_render();
        glfwPollEvents();
    }
    asln_shutdown();
    return 0;
}
