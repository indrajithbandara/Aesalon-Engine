void asln_render(void);

void asln_render(void) {
    /*glClear(GL_COLOR_BUFFER_BIT);*/
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3f(-1, 0, 0);
        glColor3f(0, 1, 0);
        glVertex3f(0, 1, 0);
        glColor3f(0, 0, 1);
        glVertex3f(1, 0, 0);
    glEnd();
    glfwSwapBuffers(ASLN_WINDOW);
}
