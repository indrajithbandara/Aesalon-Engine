int readConf() {
    puts("Reading falcon.conf...");
    FILE *config = fopen("falcon.conf", "r");
    if (config == NULL)
        return -1;
    return 0;
}
