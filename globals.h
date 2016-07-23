#define VERSION    "0.08"
#define GAME_TITLE "Falcon Engine Test"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

static GLFWwindow *FLCN_WINDOW;
static int FLCN_MAX_LINE_LEN,
           FLCN_GLFW_SAMPLES,
           FLCN_AA,
           FLCN_VSYNC,
           FLCN_WIN_WIDTH,
           FLCN_WIN_HEIGHT,
           FLCN_PAUSED,
           FLCN_DEBUG;

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
