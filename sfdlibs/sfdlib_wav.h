#include <stdlib.h>

typedef struct WAV {
    int fsize, size, freq;
    short channels, bits;
    void *data;
} WAV;

WAV *sfd_import_wav(char*);

WAV *sfd_import_wav(char *fname) {
    FILE *f = fopen(fname, "r");
    WAV *wav = malloc(sizeof(WAV));
    if (f != NULL) {
        int x;
        short y;
        char *s = malloc(5);
        fgets(s, 5, f);
        fread(&(wav->fsize), 1, 4, f);
        fgets(s, 5, f);
        fgets(s, 5, f);
        fread(&x, 1, 4, f);
        fread(&y, 1, 2, f);
        fread(&(wav->channels), 1, 2, f);
        fread(&(wav->freq), 1, 4, f);
        fread(&x, 1, 4, f);
        fread(&y, 1, 2, f);
        fread(&(wav->bits), 1, 2, f);
        fgets(s, 5, f);
        fread(&(wav->size), 1, 4, f); 
        wav->data = malloc((unsigned long)wav->size - 44);
        fread(wav->data, 1, (size_t)wav->size - 44, f);
        fclose(f);
        return wav;
    }
    return NULL;
}
