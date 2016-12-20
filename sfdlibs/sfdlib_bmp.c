typedef struct BMP {
    int width, height;
    short depth;
    unsigned char **pix_data;
} BMP;

BMP *sfd_import_bmp(char *fname) {
    FILE *f = fopen(fname, "rb");
    if (f != NULL) {
        BMP *bmp = malloc(sizeof(BMP));
        char *s = malloc(3);
        fgets(s, 3, f);
        if (strcmp("BM", s) == 0) {
            int offset, i;
            free(s);
            fseek(f, 8, SEEK_CUR);
            fread(&offset, 4, 1, f);
            fseek(f, 4, SEEK_CUR);
            fread(&(bmp->width), 4, 1, f);
            fread(&(bmp->height), 4, 1, f);
            fseek(f, 2, SEEK_CUR);
            fread(&(bmp->depth), 2, 1, f);
            fread(&i, 4, 1, f);
            if (bmp->depth == 24 && i == 0) {
                fseek(f, offset, SEEK_SET);
                bmp->pix_data = malloc(bmp->height * sizeof(unsigned char*));
                row_size = (((bmp->depth * bmp->width) + 31) / 32) * 4;
                for (i = bmp->height - 1; i >= 0; i--) {
                    unsigned char *row = malloc(bmp->width * 3);
                    fread(row, 1, bmp->width * 3, f);
                    fseek(f, row_size - (bmp->width * 3), SEEK_CUR);
                    bmp->pix_data[i] = row;
                }
                fclose(f);
                return bmp;
            } else
                puts("sfdlib_bmp: Not 24-bit Uncompressed BMP");
        } else
            puts("sfdlib_bmp: Invalid BMP Header");
        free(s);
        fclose(f);
    }
    return NULL;
}

void sfd_free_bmp(BMP *bmp) {
    int i;
    for (i = 0; i < bmp->height; i++)
        free(bmp->pix_data[i]);
    free(bmp->pix_data);
    free(bmp);
}
