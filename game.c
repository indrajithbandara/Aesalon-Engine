#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#include "confloader.c"
#include "input.c"
#include "gameloop.c"
#include "render.c"

#define VERSION    "0.04"
#define GAME_TITLE "Falcon Test"

/* Globals */

int paused = 0;
int width, height;
float ratio;

GLFWwindow *win;

void exitGame() {
    glfwDestroyWindow(win);
    glfwTerminate();
    exit(0);
}

int main(int argc, char *argv[]) {
    printf("Falcon Game Engine %s\n", VERSION);
    if (readConf())
        puts("Failed to read conf file, using defaults");
    if (!glfwInit()) {
        puts("GLFW Init Failed, Exiting");
        return -1;
    }
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    win = glfwCreateWindow((*mode).width, (*mode).height, GAME_TITLE, glfwGetPrimaryMonitor(), NULL);
    if (win == NULL)
        return -1;
    glfwMakeContextCurrent(win);
    glfwSwapInterval(1);
    glfwSetKeyCallback(win, key_callback);
    glfwGetFramebufferSize(win, &width, &height);
    glViewport(0, 0, width, height);
    ratio = (float)width / (float)height;
    while(!glfwWindowShouldClose(win))
        gameloop();
    exitGame();
    return 0;
}
