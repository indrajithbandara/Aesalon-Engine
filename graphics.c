int asln_graphics_init(void);
void asln_graphics_render(void);
void asln_graphics_splash(void);

static int build_shaders(void);
static int check_gl_info();
static void check_gl_features();


void asln_graphics_render(void) {
    /*glClear(GL_COLOR_BUFFER_BIT);*/
    glfwSwapBuffers(ASLN_WINDOW);
}

static int check_gl_info() {
    printf(" | OpenGL Version Info:\t%s\n", glGetString(GL_VERSION));
    printf(" | GLSL Version Info:\t%s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    check_gl_features();
    return 0;
}

static int build_shaders() {
    return 0;
}

void asln_graphics_splash() {
    ;
}

void check_gl_features() {
    asln_cli_info("");
    asln_cli_info("Checking for OpenGL 3.3 Support...");
    if (glewIsSupported("GL_VERSION_3_3"))
        asln_cli_info("OpenGL 3.3 is Supported");
    else
        asln_cli_info("OpenGL 3.3 is NOT Supported");
    asln_cli_info("");
    asln_cli_info("Checking for Tessalation Support... ");
    if (glewIsSupported("GL_ARB_tessellation_shader"))
        asln_cli_info("Tessalation is Supported");
    else
        asln_cli_info("Tessalation is NOT Supported");
    asln_cli_info("");
}

int asln_graphics_init(void) {
    const GLFWvidmode *mode;
    asln_cli_info("Initialising GLFW...");
    if (!glfwInit()) {
        asln_cli_error("GLFW Initialisation Failed");
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
    printf(" | Using Resolution %d x %d\n", ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT);
    glViewport(0, 0, ASLN_WIN_WIDTH, ASLN_WIN_HEIGHT);

/*
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
*/
    if (ASLN_AA)
        glEnable(GL_MULTISAMPLE);

    glewExperimental = GL_TRUE;

    asln_cli_info("Initialising GLEW...");
    if (!(glewInit() == GLEW_OK)) {
        asln_cli_error("GLEW Initialisation Failed");
        exit(-1);
    }

    check_gl_info();
    build_shaders();
    asln_graphics_splash();
    return 0;
}
