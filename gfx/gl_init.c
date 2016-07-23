int asln_init_gl(void);
static int build_shaders(void);

int asln_init_gl(void) {
    extern int ASLN_AA, ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT;
    glViewport(0, 0, ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT);

    /*glEnable(GL_DEPTH_TEST);*/

    if (ASLN_AA)
        glEnable(GL_MULTISAMPLE);

    /* build_shaders(); */
    return 0;
}
