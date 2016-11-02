int asln_init_gl(void);
static int build_shaders(void);
static int check_gl_info();

static int check_gl_info() {
    printf("\n | OpenGL Version Info: %s\n", glGetString(GL_VERSION));
    printf("\n | GLSL Version Info: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    asln_cli_info("Checking for OpenGL 3.3 Support...");
    if (glewIsSupported("GL_VERSION_3_3")) puts("Yes");
    else puts("No");
    asln_cli_info("Checking for Tessalation Support... ");
    if (glewIsSupported("GL_ARB_tessellation_shader")) puts("Yes");
    else puts("No");
    return 0;
}

static int build_shaders() {
    /* Do Shit */
}

int asln_init_gl(void) {
    const GLFWvidmode *mode;
    if (!glfwInit()) {
        asln_cli_error("GLFW Initialisation Failed");
        exit(-1);
    }
/*
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
*/
    if(ASLN_AA)
        glfwWindowHint(GLFW_SAMPLES, ASLN_GLFW_SAMPLES);

    if (!ASLN_WIN_WIDTH || !ASLN_WIN_HEIGHT) {
        mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        ASLN_WIN_WIDTH  = mode->width;
        ASLN_WIN_HEIGHT = mode->height;
    }

    ASLN_WINDOW = glfwCreateWindow(ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT, GAME_TITLE, glfwGetPrimaryMonitor(), NULL);
    glfwMakeContextCurrent(ASLN_WINDOW);
    glfwSwapInterval(ASLN_VSYNC);
    glfwGetFramebufferSize(ASLN_WINDOW, &ASLN_WIN_WIDTH, &ASLN_WIN_HEIGHT);
    glViewport(0, 0, ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT);

/*
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
*/
    if (ASLN_AA)
        glEnable(GL_MULTISAMPLE);

    glewExperimental = GL_TRUE;

    if (!(glewInit() == GLEW_OK)) {
        asln_cli_error("GLEW Initialisation Failed");
        exit(-1);
    }

    check_gl_info();
    build_shaders();
    return 0;
}
