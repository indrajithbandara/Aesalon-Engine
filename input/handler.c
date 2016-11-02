void weapon_fire() {
    puts("BANG");
}

void key_callback(GLFWwindow *win, int key, int scancode, int action, int mods) {
    extern int ASLN_PAUSED;
    switch (key) {
        case GLFW_KEY_Q :
            switch (action) {
                case GLFW_PRESS :
                    /* ADD GLFW WINDOW SHOULD CLOSE HERE */
                    exit(0);
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

void mouse_btn_callback(GLFWwindow *win, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        weapon_fire();
}

void input_init() {
    glfwSetKeyCallback(ASLN_WINDOW, key_callback);
    glfwSetMouseButtonCallback(ASLN_WINDOW, mouse_btn_callback);
}
