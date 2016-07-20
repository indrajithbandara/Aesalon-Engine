#include <GLFW/glfw3.h>

static int a = 0;
void flcn_render(void);

void flcn_render(void) {
    extern GLFWwindow *FLCN_WINDOW;
    extern int FLCN_WIN_WIDTH, FLCN_WIN_HEIGHT;
    float ratio = FLCN_WIN_WIDTH / FLCN_WIN_HEIGHT;
    /* Copypasta example code, to be replaced */
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* gluPerspective(fov, aspect, near, far); */
    glOrtho((GLdouble)-ratio, (GLdouble)ratio, (GLdouble)-1.f, (GLdouble)1.f, (GLdouble)1.f, (GLdouble)-1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(a++, 1.f, 1.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.764f, 0.2f, 0.2f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    glfwSwapBuffers(FLCN_WINDOW);
}
