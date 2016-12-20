#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <AL/al.h>
#include <AL/alc.h>

#include "globals.h"

#include "sfdlibs/sfdlib_wav.h"

#include "cli.c"
#include "logger.c"
#include "input/handler.c"
#include "input/binding.c"
#include "loaders/cfg_loader.c"
#include "gfx/gl_init.c"
#include "gfx/renderer.c"
#include "audio/al_init.c"
#include "gameloop.c"
#include "menus.c"

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
    printf("%sAesalon Game Engine %s%s\n\n", RED, VERSION, RESET);
    asln_clear_log();
    asln_load_config();
    asln_init_gl();
    asln_splash();
    input_init();
    asln_init_al();
    asln_play_theme();
    asln_gameloop();
    asln_shutdown();
    return 0;
}
