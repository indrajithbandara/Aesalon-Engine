int asln_logger_write(char*);
int asln_logger_clear(void);

int asln_logger_write(char *line) {
    FILE *log = fopen("aesalon.log", "a");
    fputs(line, stderr);
    if (log) {
        fputs(line, log);
        fclose(log);
        return 0;
    }
    return -1;
}

int asln_logger_clear() {
    FILE *log;
    remove("aesalon.log");
    log = fopen("aesalon.log", "w");
    if (log) {
        fputs("Aesalon Game Engine Log File\n===========================\n\n", log);
        fclose(log);
        return 0;
    }
    return -1;
}
