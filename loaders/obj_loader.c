#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct vec4 {
    float x, y, z, w;
} vec4;

typedef struct mtl {
    vec4 *cols;
} mtl;

typedef struct obj {
    char *name;
    int vertc, normc;
    vec4 *verts, *norms;
} obj;

static obj model;

int parse_buffer(char *buffer) {
    extern obj model;
    if (buffer[0] != '#' && strlen(buffer) != 0) {
        if (buffer[0] == 'o' && buffer[1] == ' ') {
            char *name;
            strtok(buffer, " ");
            name = strtok(NULL, "\0");
            model.name = strdup(name);
        }
        else if (buffer[0] == 'v' && buffer[1] == ' ') {
            vec4 vert;
            strtok(buffer, " ");
            vert.x = (float)atof(strtok(NULL, " "));
            vert.y = (float)atof(strtok(NULL, " "));
            vert.z = (float)atof(strtok(NULL, " "));
            model.verts = realloc(model.verts, ++model.vertc * sizeof(vec4));
            model.verts[model.vertc - 1] = vert;
        }
        else if (buffer[0] == 'v' && buffer[1] == 'n' && buffer[2] == ' ') {
            vec4 norm;
            strtok(buffer, " ");
            norm.x = (float)atof(strtok(NULL, " "));
            norm.y = (float)atof(strtok(NULL, " "));
            norm.z = (float)atof(strtok(NULL, " "));
            model.norms = realloc(model.norms, ++model.normc * sizeof(vec4));
            model.norms[model.normc - 1] = norm;
        }
        else if (buffer[0] == 'f' && buffer[1] == ' ')
            puts("Found Face!");
        else
            puts(buffer);
    }
    return 0;
}

obj load_model(char *name) {
    extern obj model;
    char *buffer = malloc(510);
    FILE *file = fopen(name, "r");
    int i, c;
    i = c = 0;
    if (file != NULL) {
        model.vertc = 0;
        model.normc = 0;
        while (c != EOF) {
            while ((c = fgetc(file)) != '\n' && c != EOF)
                buffer[i++] = c;
            if (i < 509) {
                buffer[i] = '\0';
                parse_buffer(buffer);
                i = 0;
            } else {
                fclose(file);
                break;
            }
        }
    }
    fclose(file);
    free(buffer);
    return model;
}

int main() {
    int i;
    obj model = load_model("test.obj");
    puts("\n");
    printf("%s\n", model.name);
    puts("\n");
    for (i = 0; i < model.vertc; i++)
        printf("Vertex: %f, %f, %f\n", model.verts[i].x, model.verts[i].y, model.verts[i].z);
    puts("\n");
    for (i = 0; i < model.normc; i++)
        printf("Normal: %f, %f, %f\n", model.norms[i].x, model.norms[i].y, model.norms[i].z);
    return 0;
}
