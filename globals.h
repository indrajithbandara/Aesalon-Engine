#define VERSION    "0.095"
#define GAME_TITLE "Aesalon Engine Test"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#define ASLN_MAX_AUDIO_BUFS 100
#define ASLN_MAX_AUDIO_SRCS 100

static GLFWwindow *ASLN_WINDOW;
static ALCdevice  *ASLN_AUDIO_DEV;
static ALCcontext *ASLN_AUDIO_CONTEXT;
static ALuint      ASLN_AUDIO_BUFS[ASLN_MAX_AUDIO_BUFS];
static ALuint      ASLN_AUDIO_SRCS[ASLN_MAX_AUDIO_SRCS];

static int ASLN_MAX_LINE_LEN,
           ASLN_GLFW_SAMPLES,
           ASLN_AA,
           ASLN_VSYNC,
           ASLN_WIN_WIDTH,
           ASLN_WIN_HEIGHT,
           ASLN_PAUSED,
           ASLN_DEBUG;

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
