#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../globals.h"

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
        } else if (buffer[0] == 'f' && buffer[1] == ' ') {
            face f;
            vec4 v;
            f.verts = NULL;
            f.vertc = 0;
            char *verts[4];
            char *token;
            int i = 0;
            strtok(buffer, " ");
            for (; i < 4; i++)
                if ((token = (strtok(NULL, " "))))
                    verts[i] = token;
            for (i = 0; i < 4; i++) {
                token = strdup(verts[i]);
                v.x = (float)atof(strtok(token, "/"));
                if (strstr(verts[i], "//"))
                    v.z = (float)atof(strtok(NULL, "/"));
                else {
                    v.x = (float)atof(strtok(NULL, "/"));
                    v.z = (float)atof(strtok(NULL, "\0"));
                }
                f.verts = realloc(f.verts, ++f.vertc * sizeof(vec4));
                f.verts[f.vertc - 1] = v;
            }
            model.faces = realloc(model.faces, ++model.facec * sizeof(face));
            model.faces[model.facec - 1] = f;
        }
        else
            puts(buffer);
    }
    return 0;
}

obj load_model(char *name) {
    extern obj model;
    model.name = "";
    model.verts = model.norms = NULL;
    model.faces = NULL;
    char *buffer = malloc(MAX_LINE_LEN + 1);
    FILE *file = fopen(name, "r");
    int i, c;
    i = c = 0;
    if (file != NULL) {
        while (c != EOF) {
            while ((c = fgetc(file)) != '\n' && c != EOF)
                buffer[i++] = c;
            if (i < MAX_LINE_LEN) {
                buffer[i] = '\0';
                parse_buffer(buffer);
                i = 0;
            } else {
                fclose(file);
                break;
            }
        }
        fclose(file);
    }
    free(buffer);
    return model;
}
