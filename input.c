/* This file defines the callback functions to be called by GLFW */

int paused;
void exitGame();

void key_callback(GLFWwindow *win, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        exitGame();
    else if (key == GLFW_KEY_P && action == GLFW_PRESS)
        paused = !paused;
}
