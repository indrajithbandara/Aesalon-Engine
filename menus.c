void asln_main_menu(void) {
    char c, *gameLogo = GAME_TITLE;
    printf(" |========================\n |\n |  %s\n |\n |  %s[%s1%s]%s Start Game %s-%s>%s\n |  %s[%s2%s]%s Settings   %s-%s>%s\n |  %s[%s3%s]%s Exit       %s-%s>%s\n |\n|========================\n | Enter Section: ", gameLogo, RED, GREEN, RED, RESET, RED, GREEN, RESET, RED, GREEN, RED, RESET, RED, GREEN, RESET, RED, GREEN, RED, RESET, RED, GREEN, RESET);
    c = getchar();
    switch (c) {
        case '1' :
            asln_init_gl();
            input_init();
            asln_gameloop();
            return;
        case '2' :
            asln_opts_menu();
            break;
        case '3' :
            return;
        default :
            asln_main_menu();
    }
}

void asln_opts_menu(void) {
    char c = getchar();
    printf("[1] Back to Main Menu\n");
    c = getchar();
    switch (c) {
        case '1' :
            getchar();
            asln_main_menu();
            break;
        default :
            asln_opts_menu();
    }
}
