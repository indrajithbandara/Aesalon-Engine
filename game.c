#include <stdio.h>
#include <GLFW/glfw3.h>

#define VERSION "0.03"

int main(int argc, char *argv[]) {
    printf("Falcon Game Engine %s\n", VERSION);
    if (!glfwInit()) {
        puts("GLFW Init Failed, Exiting");
        return -1;
    }
    while(1) {
        ;
    }
    glfwTerminate();
    return 0;
}
