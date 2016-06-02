int paused;
float ratio;

void draw3D() {

    /* Copypasta example code, to be replaced */
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* gluPerspective(fov, aspect, near, far); */
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
}
