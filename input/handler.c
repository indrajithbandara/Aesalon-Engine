#include <GLFW/glfw3.h>

void exitGame(void);

void key_callback(GLFWwindow *win, int key, int scancode, int action, int mods) {
    extern int ASLN_PAUSED;
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        exitGame();
    else if (key == GLFW_KEY_P && action == GLFW_PRESS)
        ASLN_PAUSED = !ASLN_PAUSED;
}
