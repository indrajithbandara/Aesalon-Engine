int flcn_init_gl(void);
static int build_shaders(void);

int flcn_init_gl(void) {
    extern int FLCN_AA, FLCN_WIN_WIDTH, FLCN_WIN_HEIGHT;
    glViewport(0, 0, FLCN_WIN_WIDTH, FLCN_WIN_HEIGHT);

    /*glEnable(GL_DEPTH_TEST);*/

    if (FLCN_AA)
        glEnable(GL_MULTISAMPLE);

    /* build_shaders(); */
    return 0;
}
