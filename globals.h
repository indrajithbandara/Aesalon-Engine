#define VERSION    "0.06"
#define GAME_TITLE "Falcon Engine Test"

static GLFWwindow *FLCN_WINDOW;
static int FLCN_MAX_LINE_LEN,
           FLCN_GLFW_SAMPLES,
           FLCN_AA,
           FLCN_WIN_WIDTH,
           FLCN_WIN_HEIGHT,
           FLCN_PAUSED;

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
