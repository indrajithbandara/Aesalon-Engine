/* sfdlib_wav.c - This file is part of sfdlibs, the Userland C Libraries of the
 * Sandford Operating System.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * sfdlibs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * sfdlibs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with sfdlibs.  If not, see <http://www.gnu.org/licenses/>.
 */

typedef struct WAV {
    int fsize, size, freq;
    short channels, bits;
    void *data;
} WAV;

WAV *import_wav(char*);

WAV *import_wav(char *fname) {
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

void free_wav(WAV *wav) {
    free(wav->data);
    free(wav);
}
