/* This file defines the callback functions to be called by GLFW */

void exitGame();

void key_callback(GLFWwindow *win, int key, int scancode, int action, int mods) {
    printf("Key Pressed, keycode: %d\n", key);
    fflush(stdout);
    if (key == 81)
        exitGame();
}
