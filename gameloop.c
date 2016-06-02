GLFWwindow *win;

int paused;
void draw3D();

void gameloop() {
    if (!paused) {
        draw3D();
        glfwSwapBuffers(win);
    }
    glfwPollEvents();
}
