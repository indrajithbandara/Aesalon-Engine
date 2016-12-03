int asln_cli_error(char *msg);
int asln_cli_info(char *msg);
void asln_opts_menu(void);
void asln_main_menu(void);

int asln_cli_error(char *msg) {
    printf("\n | %s%s%s ", RED, msg, RESET);
    return 0;
}

int asln_cli_info(char *msg) {
    printf(" | %s\n", msg);
    return 0;
}
