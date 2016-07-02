#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <GLFW/glfw3.h>

#include "globals.h"

#include "input.c"
#include "renderloop.c"

void exitGame(void) {
    extern GLFWwindow *win;
    glfwDestroyWindow(win);
    glfwTerminate();
    exit(0);
}

int main(int argc, char *argv[]) {
    extern int width, height, paused;
    extern GLFWwindow *win;
    const GLFWvidmode *mode;
    printf("Falcon Game Engine %s\n", VERSION);

    if (!glfwInit())
        return -1;

    mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    width  = (*mode).width;
    height = (*mode).height;

    if (argv[1] != NULL && !strcmp(argv[1], "--windowed") && argv[2] != NULL && argv[3] != NULL) {
        width  = atoi(argv[2]);
        height = atoi(argv[3]);
        printf("Using User Defined Resolution: %dx%d\n", width, height);
    }

    win = glfwCreateWindow(width, height, GAME_TITLE, glfwGetPrimaryMonitor(), NULL);

    if (win == NULL)
        return -1;

    glfwMakeContextCurrent(win);
    glfwSwapInterval(1);
    glfwSetKeyCallback(win, key_callback);
    glfwGetFramebufferSize(win, &width, &height);

    glViewport(0, 0, width, height);
    ratio = (float)width / (float)height;

    /* buildShaders(); */

    gameloop();

    exitGame();
    return 0;
}
