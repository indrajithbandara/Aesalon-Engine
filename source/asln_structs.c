typedef struct {
    GLFWwindow *window;
    int paused;
} ASLN_STATE;

typedef struct {
    ALCdevice  *device;
    ALCcontext *context;
    ALuint     *buffers,
               *sources,
               buffer_count;
} ASLN_AUDIO;

typedef struct {
    int api,
        debug,
        max_shader_length,
        max_audio_buffers,
        max_audio_sources,
        max_line_length,
        samples,
        antialiasing,
        vsync,
        win_width,
        win_height;
} ASLN_CONFIG;

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
