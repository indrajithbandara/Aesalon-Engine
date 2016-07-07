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
    extern int FLCN_WIDTH, FLCN_HEIGHT, FLCN_PAUSED;
    extern GLFWwindow *FLCN_WINDOW;
    const GLFWvidmode *mode;
    printf("Falcon Game Engine %s\n", VERSION);
    flcn_clear_log();
    flcn_log("This is a Test");

    if (!glfwInit())
        return -1;

    flcn_load_config();

    if(FLCN_AA)
        glfwWindowHint(GLFW_SAMPLES, FLCN_GLFW_SAMPLES);

    mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    FLCN_WIDTH  = (*mode).width;
    FLCN_HEIGHT = (*mode).height;

    FLCN_WINDOW = glfwCreateWindow(FLCN_WIDTH, FLCN_HEIGHT, GAME_TITLE,
                                   glfwGetPrimaryMonitor(), NULL);

    if (FLCN_WINDOW == NULL)
        return -1;

    glfwMakeContextCurrent(FLCN_WINDOW);
    glfwSwapInterval(1);
    glfwSetKeyCallback(FLCN_WINDOW, key_callback);
    glfwGetFramebufferSize(FLCN_WINDOW, &FLCN_WIDTH, &FLCN_HEIGHT);

    glViewport(0, 0, FLCN_WIDTH, FLCN_HEIGHT);

    if (FLCN_AA)
        glEnable(GL_MULTISAMPLE);

    /* buildShaders(); */

    gameloop();

    exitGame();
    return 0;
}
