int asln_init_al(void);
int asln_play_theme(void);

int asln_init_al() {
    asln_cli_info("Initialising OpenAL...");
    if ((ASLN_AUDIO_DEV = alcOpenDevice(NULL))) {
        WAV *wav;
        printf(" | Using Audio Device %s\n", alcGetString(ASLN_AUDIO_DEV, ALC_DEVICE_SPECIFIER));
        ASLN_AUDIO_CONTEXT = alcCreateContext(ASLN_AUDIO_DEV, NULL);
        alcMakeContextCurrent(ASLN_AUDIO_CONTEXT);
        alGenBuffers(5, ASLN_AUDIO_BUFS);
        alGenSources(5, ASLN_AUDIO_SRCS);
        
        if ((wav = sfd_import_wav("res/snd/fire.wav")) != NULL) {
            alBufferData(ASLN_AUDIO_BUFS[1], AL_FORMAT_STEREO16, wav->data, wav->size, wav->freq);
            free(wav->data);
            free(wav);
        } else
            asln_cli_info("Failed to Load fire.wav");
        
        if ((wav = sfd_import_wav("res/snd/shell_falls.wav")) != NULL) {
            alBufferData(ASLN_AUDIO_BUFS[2], AL_FORMAT_STEREO16, wav->data, wav->size, wav->freq);
            sfd_free_wav(wav);
        } else
            asln_cli_info("Failed to Load shell_falls.wav");
        
        if ((wav = sfd_import_wav("res/snd/reload.wav")) != NULL) {
            alBufferData(ASLN_AUDIO_BUFS[3], AL_FORMAT_STEREO16, wav->data, wav->size, wav->freq);
            sfd_free_wav(wav);
        } else
            asln_cli_info("Failed to Load reload.wav");
        
        if ((wav = sfd_import_wav("res/snd/lock_and_load.wav")) != NULL) {
            alBufferData(ASLN_AUDIO_BUFS[4], AL_FORMAT_STEREO16, wav->data, wav->size, wav->freq);
            sfd_free_wav(wav);
        } else
            asln_cli_info("Failed to Load lock_and_load.wav");
    }
    return 0;
}

int asln_play_theme() {
    WAV *wav = sfd_import_wav("res/snd/menu_theme.wav");
    if (wav != NULL) {
        alBufferData(ASLN_AUDIO_BUFS[0], AL_FORMAT_STEREO16, wav->data, wav->size, wav->freq);
        sfd_free_wav(wav);
        alSourcei(ASLN_AUDIO_SRCS[0], AL_BUFFER, (ALint)ASLN_AUDIO_BUFS[0]);
        alSourcei(ASLN_AUDIO_SRCS[0], AL_LOOPING, AL_TRUE);
        alSourcePlay(ASLN_AUDIO_SRCS[0]);
    } else
        asln_cli_info("Failed to Load menu_theme.wav");
    return 0;
}

void asln_fire_sound() {
    alSourcei(ASLN_AUDIO_SRCS[1], AL_BUFFER, (ALint)ASLN_AUDIO_BUFS[1]);
    alSourcePlay(ASLN_AUDIO_SRCS[1]);
    alSourcei(ASLN_AUDIO_SRCS[2], AL_BUFFER, (ALint)ASLN_AUDIO_BUFS[2]);
    alSourcePlay(ASLN_AUDIO_SRCS[2]);
}

void asln_reload_sound() {
    alSourcei(ASLN_AUDIO_SRCS[3], AL_BUFFER, (ALint)ASLN_AUDIO_BUFS[3]);
    alSourcePlay(ASLN_AUDIO_SRCS[3]);
    alSourcei(ASLN_AUDIO_SRCS[4], AL_BUFFER, (ALint)ASLN_AUDIO_BUFS[4]);
    alSourcePlay(ASLN_AUDIO_SRCS[4]);
}
