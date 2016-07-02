#include <GLFW/glfw3.h>

void exitGame(void);

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    extern int paused;
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        exitGame();
    else if (key == GLFW_KEY_P && action == GLFW_PRESS)
        paused = !paused;
}
