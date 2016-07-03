#include <stdio.h>
#include "obj_loader.c"

int main(int argc, char *argv[]) {
    int i, j;
    extern obj model;
    if (argv[1] != NULL) {
        model = load_model(argv[1]);
        puts("\n");
        printf("%s\n", model.name);
        puts("\n");
        for (i = 0; i < model.vertc; i++)
            printf("Vertex: %f, %f, %f\n", model.verts[i].x, model.verts[i].y, model.verts[i].z);
        puts("\n");
        for (i = 0; i < model.normc; i++)
            printf("Normal: %f, %f, %f\n", model.norms[i].x, model.norms[i].y, model.norms[i].z);
        puts("\n");
        for (i = 0; i < model.textc; i++)
            printf("Texture: %f, %f\n", model.texts[i].x, model.texts[i].y);
        puts("\n");
        for (i = 0; i < model.facec; i++) {
            printf("Face: ");
            for (j = 0; j < model.faces[i].vertc; j++)
                printf("%f/%f/%f  ", model.faces[i].verts[j].x, model.faces[i].verts[j].y, model.faces[i].verts[j].z);
            puts("");
        }
        return 0;
    }
    puts("No Model to Load");
    return -1;
}
