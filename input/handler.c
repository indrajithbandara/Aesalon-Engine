void weapon_fire(void);
void key_callback(GLFWwindow*, int, int, int, int);
void mouse_btn_callback(GLFWwindow*, int, int, int);
void input_init(void);
void asln_fire_sound(void);
void asln_reload_sound(void);

void weapon_fire() {
    asln_fire_sound();
}

void weapon_reload() {
    asln_reload_sound();
}

void key_callback(GLFWwindow *win, int key, int scancode, int action, int mods) {
    extern int ASLN_PAUSED;
    switch (key) {
        case GLFW_KEY_Q :
            switch (action) {
                case GLFW_PRESS :
                    glfwSetWindowShouldClose(ASLN_WINDOW, 1);
                    break;
            } break;
        case GLFW_KEY_P :
            switch (action) {
                case GLFW_PRESS :
                    ASLN_PAUSED = !ASLN_PAUSED;
                    break;
            } break;
        case GLFW_KEY_R :
            switch (action) {
                case GLFW_PRESS :
                    weapon_reload();
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
