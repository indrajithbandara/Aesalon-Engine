#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <GLFW/glfw3.h>

#include "globals.h"

#include "input.c"
#include "renderloop.c"
#include "logger.c"
#include "config.c"

void exitGame(void) {
    extern GLFWwindow *FLCN_WINDOW;
    glfwDestroyWindow(FLCN_WINDOW);
    glfwTerminate();
    exit(0);
}

int main(int argc, char *argv[]) {
    extern int FLCN_WIDTH, FLCN_HEIGHT, FLCN_DEBUG, FLCN_PAUSED;
    extern GLFWwindow *FLCN_WINDOW;
    const GLFWvidmode *mode;
    printf("Falcon Game Engine %s\n", VERSION);

    if (!glfwInit())
        return -1;

    puts("Reading Config...");
    flcn_load_config();

    flcn_clear_log();
    flcn_log("This is a Test");

    if (FLCN_DEBUG)
        puts("***DEBUGGING IS ENABLED***");

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

    printf("Using Resolution: %d x %d\n", FLCN_WIN_WIDTH, FLCN_WIN_HEIGHT);

    glfwMakeContextCurrent(FLCN_WINDOW);
    glfwSwapInterval(1);
    glfwSetKeyCallback(FLCN_WINDOW, key_callback);


    glfwGetFramebufferSize(FLCN_WINDOW, &FLCN_WIN_WIDTH, &FLCN_WIN_HEIGHT);

    glViewport(0, 0, FLCN_WIN_WIDTH, FLCN_WIN_HEIGHT);

    if (FLCN_AA)
        glEnable(GL_MULTISAMPLE);

    /* buildShaders(); */

    gameloop();

    exitGame();
    return 0;
}
