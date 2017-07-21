/* input.c - This file is part of Aesalon, a simple, lightweight 3D game engine written in ANSI C.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Aesalon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Aesalon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Aesalon.  If not, see <http://www.gnu.org/licenses/>.
 */

void asln_input_init(void);

void key_callback(GLFWwindow*, int, int, int, int);
void mouse_btn_callback(GLFWwindow*, int, int, int);

int asln_bind_key(char, char*);
int asln_bind_mbutton(int, char*);

void key_callback(GLFWwindow *win, int key, int scancode, int action, int mods) {
    switch (key) {
        case GLFW_KEY_Q :
            switch (action) {
                case GLFW_PRESS :
                    glfwSetWindowShouldClose(asln_state->window, 1);
                    break;
            } break;
        case GLFW_KEY_P :
            switch (action) {
                case GLFW_PRESS :
                    asln_state->paused = !(asln_state->paused);
                    break;
            } break;
        case GLFW_KEY_R :
            switch (action) {
                case GLFW_PRESS :
                    /*weapon_reload()*/;
                    break;
            } break;
    }
}

void mouse_btn_callback(GLFWwindow *win, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        /*weapon_fire()*/;
    }
}

void asln_input_init() {
    puts("Initializing Input...");
    puts("  Setting Key Callback...");
    glfwSetKeyCallback(asln_state->window, key_callback);
    puts("  Setting Mouse Callback...");
    glfwSetMouseButtonCallback(asln_state->window, mouse_btn_callback);
    puts("  Done Initializing Input\n");
}

int asln_bind_key(char key, char *action) {
    /* TODO */
    return 0;
}

int asln_bind_mbutton(int btn, char *action) {
    /* TODO */
    return 0;
}
