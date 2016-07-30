#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "globals.h"

#include "input/handler.c"
#include "gfx/gl_init.c"
#include "gfx/renderer.c"
#include "logger.c"
#include "loaders/cfg_loader.c"

void exitGame(void) {
    glfwDestroyWindow(ASLN_WINDOW);
    glfwTerminate();
    exit(0);
}

int main(int argc, char *argv[]) {
    const GLFWvidmode *mode;

    printf("%sAesalon Game Engine %s%s\n", RED, VERSION, RESET);
    asln_clear_log();
    asln_load_config();

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if(ASLN_AA) glfwWindowHint(GLFW_SAMPLES, ASLN_GLFW_SAMPLES);

    if (!ASLN_WIN_WIDTH || !ASLN_WIN_HEIGHT) {
        mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        ASLN_WIN_WIDTH  = (*mode).width;
        ASLN_WIN_HEIGHT = (*mode).height;
    }

    ASLN_WINDOW = glfwCreateWindow(ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT, GAME_TITLE, glfwGetPrimaryMonitor(), NULL);
    printf("\n | Debugging:\t\t%d\n | Anti-Aliasing:\t%d\n | V-Sync:\t\t%d\n | Resolution:\t\t%d x %d\n", ASLN_DEBUG, ASLN_AA, ASLN_VSYNC, ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT);

    glfwMakeContextCurrent(ASLN_WINDOW);
    glfwSwapInterval(ASLN_VSYNC);
    glfwSetKeyCallback(ASLN_WINDOW, key_callback);
    glfwGetFramebufferSize(ASLN_WINDOW, &ASLN_WIN_WIDTH, &ASLN_WIN_HEIGHT);

    glewExperimental = GL_TRUE;
    glewInit();

    asln_init_gl();

    while (!glfwWindowShouldClose(ASLN_WINDOW)) {
        if (!ASLN_PAUSED)
            asln_render();
        glfwPollEvents();
    }

    exitGame();
    return 0;
}
