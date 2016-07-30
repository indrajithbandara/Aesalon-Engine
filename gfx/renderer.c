#include <GLFW/glfw3.h>

void asln_render(void);

void asln_render(void) {
    extern GLFWwindow *ASLN_WINDOW;
    extern int ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT;

    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(ASLN_WINDOW);
}
