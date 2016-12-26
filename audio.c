#define ASLN_MAX_AUDIO_BUFS 10
#define ASLN_MAX_AUDIO_SRCS 10

static ALCdevice  *ASLN_AUDIO_DEV;
static ALCcontext *ASLN_AUDIO_CONTEXT;
static ALuint     ASLN_AUDIO_BUFS[ASLN_MAX_AUDIO_BUFS];
static ALuint     ASLN_AUDIO_SRCS[ASLN_MAX_AUDIO_SRCS];
static ALuint     ASLN_BUFFER_COUNT;

int asln_audio_init(void);
void asln_audio_play(WAV*, ALuint);
void asln_audio_self_test(void);

int asln_audio_init() {
    asln_cli_info("Initialising OpenAL...");
    if ((ASLN_AUDIO_DEV = alcOpenDevice(NULL))) {
        WAV *wav;
        int i;
        printf(" | Using Audio Device %s\n", alcGetString(ASLN_AUDIO_DEV, ALC_DEVICE_SPECIFIER));
        ASLN_AUDIO_CONTEXT = alcCreateContext(ASLN_AUDIO_DEV, NULL);
        alcMakeContextCurrent(ASLN_AUDIO_CONTEXT);
        alGenBuffers(ASLN_MAX_AUDIO_BUFS, ASLN_AUDIO_BUFS);
        alGenSources(ASLN_MAX_AUDIO_SRCS, ASLN_AUDIO_SRCS);
        ASLN_BUFFER_COUNT = 0;
        asln_audio_self_test();
        wav = sfd_import_wav("res/snd/menu_theme.wav");
        asln_audio_play(wav, 1);
        sfd_free_wav(wav);
    }
    return 0;
}

void asln_audio_play(WAV *wav, ALuint loop) {
    if (wav != NULL) {
        alBufferData(ASLN_AUDIO_BUFS[ASLN_BUFFER_COUNT], AL_FORMAT_STEREO16, wav->data, wav->size, wav->freq);
        alSourcei(ASLN_AUDIO_SRCS[ASLN_BUFFER_COUNT], AL_BUFFER, (ALint)ASLN_AUDIO_BUFS[ASLN_BUFFER_COUNT]);
        alSourcei(ASLN_AUDIO_SRCS[ASLN_BUFFER_COUNT], AL_LOOPING, loop);
        alSourcePlay(ASLN_AUDIO_SRCS[ASLN_BUFFER_COUNT]);
        ASLN_BUFFER_COUNT++;
    } else
        asln_cli_info("Failed to Load menu_theme.wav");
}

void asln_audio_self_test() {
    WAV *wav;
    asln_cli_info("Starting Audio Self-Test...");
    wav = sfd_import_wav("res/snd/test/1.wav");
    asln_audio_play(wav, 0);
    sfd_free_wav(wav);
    printf(" | 1. %s\n", alGetString(alGetError()));
    sleep(1);
    wav = sfd_import_wav("res/snd/test/2.wav");
    asln_audio_play(wav, 0);
    sfd_free_wav(wav);
    sleep(1);
    printf(" | 2. %s\n", alGetString(alGetError()));
    wav = sfd_import_wav("res/snd/test/3.wav");
    asln_audio_play(wav, 0);
    sfd_free_wav(wav);
    sleep(1);
    printf(" | 3. %s\n", alGetString(alGetError()));
    wav = sfd_import_wav("res/snd/test/4.wav");
    asln_audio_play(wav, 0);
    sfd_free_wav(wav);
    sleep(1);
    printf(" | 4. %s\n", alGetString(alGetError()));
    wav = sfd_import_wav("res/snd/test/5.wav");
    asln_audio_play(wav, 0);
    sfd_free_wav(wav);
    sleep(1);
    printf(" | 5. %s\n", alGetString(alGetError()));
    asln_cli_info("Audio Test Complete");
}
