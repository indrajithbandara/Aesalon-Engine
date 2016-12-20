typedef struct WAV {
    int fsize, size, freq;
    short channels, bits;
    void *data;
} WAV;

WAV *sfd_import_wav(char*);

WAV *sfd_import_wav(char *fname) {
    FILE *f = fopen(fname, "rb");
    if (f != NULL) {
        char *s1 = malloc(5);
        char *s2 = malloc(8);
        int fsize;
        fgets(s1, 5, f);
        fread(&fsize, 1, 4, f);
        fgets(s2, 8, f);
        if (strcmp("RIFF", s1) == 0 && strcmp("WAVEfmt", s2) == 0) {
            WAV *wav;
            free(s1);
            free(s2);
            wav = malloc(sizeof(WAV));
            wav->fsize = fsize;
            fseek(f, 7, SEEK_CUR);
            fread(&(wav->channels), 1, 2, f);
            fread(&(wav->freq), 1, 4, f);
            fseek(f, 6, SEEK_CUR);
            fread(&(wav->bits), 1, 2, f);
            fseek(f, 4, SEEK_CUR);
            fread(&(wav->size), 1, 4, f);
            wav->data = malloc((unsigned long)wav->size - 44);
            fread(wav->data, 1, (size_t)wav->size - 44, f);
            fclose(f);
            return wav;
        } else {
            free(s1);
            free(s2);
            fclose(f);
            puts("sfdlib_wav: Invalid WAV Header");
        }
    }
    return NULL;
}

void sfd_free_wav(WAV *wav) {
    free(wav->data);
    free(wav);
}
