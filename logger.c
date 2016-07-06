#include <stdio.h>

int flcn_log(char *line) {
    FILE *log = fopen("flcn.log", "a");
    if (log) {
        fputs(line, log);
        fclose(log);
        return 0;
    }
    return -1;
}

int flcn_clear_log() {
    FILE *log;
    remove("logs/flcn.log");
    log = fopen("flcn.log", "w");
    if (log) {
        fputs("Falcon Game Engine Log File\n===========================\n\n", log);
        fclose(log);
        return 0;
    }
    return -1;
}
