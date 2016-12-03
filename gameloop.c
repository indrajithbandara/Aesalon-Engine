int asln_gameloop(void);

int asln_gameloop() {
    while (!glfwWindowShouldClose(ASLN_WINDOW)) {
        if (!ASLN_PAUSED) asln_render();
        glfwPollEvents();
    }
    return 0;
}
