#include <GLFW/glfw3.h>

void exitGame(void);

void key_callback(GLFWwindow *win, int key, int scancode, int action, int mods) {
    extern int ASLN_PAUSED;
    switch (key) {
        case GLFW_KEY_Q :
            switch (action) {
                case GLFW_PRESS :
                    exitGame();
                    break;
            } break;

        case GLFW_KEY_P :
            switch (action) {
                case GLFW_PRESS :
                    ASLN_PAUSED = !ASLN_PAUSED;
                    break;
            } break;
    }
}
