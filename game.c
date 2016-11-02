#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "globals.h"

#include "cli.c"
#include "logger.c"
#include "loaders/cfg_loader.c"
#include "input/handler.c"
#include "gfx/gl_init.c"
#include "gfx/renderer.c"
#include "gameloop.c"
#include "menus.c"

int main(int argc, char *argv[]) {
    printf("%sAesalon Game Engine %s%s\n", RED, VERSION, RESET);
    asln_clear_log();
    asln_load_config();
    asln_main_menu();
    glfwDestroyWindow(ASLN_WINDOW);
    glfwTerminate();
    return 0;
}
