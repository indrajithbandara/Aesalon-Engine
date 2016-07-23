#include <stdio.h>

int asln_log(char *line);
int asln_clear_log(void);

int asln_log(char *line) {
    FILE *log = fopen("aesalon.log", "a");
    fputs(line, stderr);
    if (log) {
        fputs(line, log);
        fclose(log);
        return 0;
    }
    return -1;
}

int flcn_clear_log() {
    FILE *log;
    remove("logs/aesalon.log");
    log = fopen("aesalon.log", "w");
    if (log) {
        fputs("Aesalon Game Engine Log File\n===========================\n\n", log);
        fclose(log);
        return 0;
    }
    return -1;
}
