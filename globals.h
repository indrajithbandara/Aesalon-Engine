#define VERSION    "0.06"
#define GAME_TITLE "Falcon Engine Test"

#define MAX_LINE_LEN 509

static int width, height, a, paused;
static float ratio;
static GLFWwindow *win;

typedef struct {
    float x, y, z, w;
} vec4;

typedef struct {
    int vertc;
    vec4 *verts;
} face;

typedef struct {
    char *name;
    int facec, normc, textc, vertc;
    face *faces;
    vec4 *norms, *texts, *verts;
} obj;
