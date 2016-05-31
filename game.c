#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#include "input.c"

#define VERSION    "0.04"
#define GAME_TITLE "Falcon Test"

/* Globals */

int width, height;
float ratio;

GLFWwindow *win;

void exitGame() {
    glfwDestroyWindow(win);
    glfwTerminate();
    exit(0);
}

void draw3D() {

    /* Copypasta example code, to be replaced */

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
}

void gameloop() {
    draw3D();
    glfwSwapBuffers(win);
    glfwPollEvents();
}

int readConf() {
    puts("Reading falcon.conf...");
    FILE *config = fopen("falcon.conf", "r");
    if (config == NULL)
        return -1;
    return 0;
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
