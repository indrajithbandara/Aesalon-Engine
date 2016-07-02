#include <GLFW/glfw3.h>

void draw3D(void);

void gameloop() {
    extern float ratio;
    extern int paused, a;
    extern GLFWwindow *win;

    paused = a = 0;

    while (!glfwWindowShouldClose(win)) {
        if (!paused) {
            /* Copypasta example code, to be replaced */
            glClear(GL_COLOR_BUFFER_BIT);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            /* gluPerspective(fov, aspect, near, far); */
            glOrtho((GLdouble)-ratio, (GLdouble)ratio, (GLdouble)-1.f, (GLdouble)1.f, (GLdouble)1.f, (GLdouble)-1.f);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glRotatef(a++, 0.f, 0.f, 1.f);
            glBegin(GL_TRIANGLES);
            glColor3f(0.764f, 0.2f, 0.2f);
            glVertex3f(-0.6f, -0.4f, 0.f);
            glVertex3f(0.6f, -0.4f, 0.f);
            glVertex3f(0.f, 0.6f, 0.f);
            glEnd();
            glfwSwapBuffers(win);
        }
        glfwPollEvents();
    }
}
