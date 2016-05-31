GLFWwindow *win;

void draw3D();

void gameloop() {
    draw3D();
    glfwSwapBuffers(win);
    glfwPollEvents();
}
