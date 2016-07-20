#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <GLFW/glfw3.h>

#include "globals.h"

#include "input/handler.c"
#include "gfx/gl_init.c"
#include "gfx/renderer.c"
#include "logger.c"
#include "loaders/cfg_loader.c"

void exitGame(void) {
    glfwDestroyWindow(FLCN_WINDOW);
    glfwTerminate();
    exit(0);
}

int main(int argc, char *argv[]) {
    const GLFWvidmode *mode;
    printf("Falcon Game Engine %s\n", VERSION);

    if (!glfwInit())
        return -1;

    puts("Reading Config...");
    flcn_load_config();

    if(FLCN_AA)
        glfwWindowHint(GLFW_SAMPLES, FLCN_GLFW_SAMPLES);

    if (!FLCN_WIN_WIDTH || !FLCN_WIN_HEIGHT) {
        mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        FLCN_WIN_WIDTH  = (*mode).width;
        FLCN_WIN_HEIGHT = (*mode).height;
    }

    FLCN_WINDOW = glfwCreateWindow(FLCN_WIN_WIDTH, FLCN_WIN_HEIGHT, GAME_TITLE,
                                   glfwGetPrimaryMonitor(), NULL);

    if (FLCN_WINDOW == NULL)
        return -1;

    printf("\nDebugging:\t%d\nAnti-Aliasing:\t%d\nV-Sync:\t\t%d\nResolution:\t%d x %d\n", FLCN_DEBUG, FLCN_AA, FLCN_VSYNC, FLCN_WIN_WIDTH, FLCN_WIN_HEIGHT);

    flcn_clear_log();

    glfwMakeContextCurrent(FLCN_WINDOW);
    glfwSwapInterval(FLCN_VSYNC);
    glfwSetKeyCallback(FLCN_WINDOW, key_callback);


    glfwGetFramebufferSize(FLCN_WINDOW, &FLCN_WIN_WIDTH, &FLCN_WIN_HEIGHT);

    flcn_init_gl();

    while (!glfwWindowShouldClose(FLCN_WINDOW)) {
        if (!FLCN_PAUSED)
            flcn_render();
        glfwPollEvents();
    }

    exitGame();
    return 0;
}
