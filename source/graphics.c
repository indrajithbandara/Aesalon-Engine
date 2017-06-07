/* graphics.c - This file is part of Aesalon, a simple, lightweight 3D game engine written in ANSI C.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Aesalon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Aesalon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Aesalon.  If not, see <http://www.gnu.org/licenses/>.
 */

int asln_graphics_init(void);
void asln_graphics_render(void);


void asln_print_opengl_features() {
    if (glewIsSupported("GL_VERSION_3_3"))
        puts("  OpenGL 3.3 is Supported");
    else
        puts("  OpenGL 3.3 is NOT Supported");

    if (glewIsSupported("GL_ARB_tessellation_shader"))
        puts("  Tessalation is Supported");
    else
        puts("  Tessalation is NOT Supported");

    printf("  OpenGL Version Info: %s\n", glGetString(GL_VERSION));
    printf("  GLSL Version Info: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

int asln_graphics_init() {
    const GLFWvidmode *mode;

    printf("\nInitialising Graphics...\n  Initialising GLFW... ");

    if (!glfwInit()) {
        puts("Failed\nExiting...");
        exit(1);
    }

    puts("Checking for Vulkan Support...");
    if (glfwVulkanSupported()) {
        puts("Vulkan is Supported, Defaulting to Vulkan API");
        asln_config->api = 1;
    } else {
        puts("Vulkan NOT Supported, Falling Back to OpenGL");
        asln_config->api = 0;
    }

/*
    printf("Success\n  Setting OpenGL Version to 3.3 Core Profile... ");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
*/
    puts("Success");
    if(asln_config->antialiasing)
        glfwWindowHint(GLFW_SAMPLES, asln_config->samples);
    else
        puts("  Antialiasing Disabled in Config");

    if (asln_config->win_width <= 0 || asln_config->win_height <= 0) {
        puts("  Invalid Resolution in Config, Using Native Resolution Instead");
        mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        asln_config->win_width  = mode->width;
        asln_config->win_height = mode->height;
    }

    printf("  Creating GLFW Window... ");
    if ((asln_state->window = glfwCreateWindow(asln_config->win_width, asln_config->win_height, ASLN_GAME_TITLE, glfwGetPrimaryMonitor(), NULL)) == NULL) {
        puts("Failed\n  Exiting");
        exit(1);
    }
    puts("Success");
    glfwMakeContextCurrent(asln_state->window);
    glfwSwapInterval(asln_config->vsync);
    glfwGetFramebufferSize(asln_state->window, &(asln_config->win_width), &(asln_config->win_height));
    printf("  Using Resolution %d x %d\n", asln_config->win_width, asln_config->win_height);

    glViewport(0, 0, asln_config->win_width, asln_config->win_height);
    glewExperimental = GL_TRUE;

    /*
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    */
    if(asln_config->antialiasing)
        glEnable(GL_MULTISAMPLE);

    printf("  Initialising GLEW... ");
    if (!(glewInit() == GLEW_OK)) {
        puts("Failed");
        exit(-1);
    } else
        puts("Success");

    asln_print_opengl_features();
    puts("  Done Initializing Graphics\n");
    return 0;
}

void asln_graphics_render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(asln_state->window);
}
