/* audio.c - This file is part of Aesalon, a simple, lightweight 3D game engine written in ANSI C.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Aesalon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Aesalon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Aesalon.  If not, see <http://www.gnu.org/licenses/>.
 */

#define ASLN_MAX_AUDIO_BUFS 100
#define ASLN_MAX_AUDIO_SRCS 100

int asln_audio_init(void);
void asln_audio_play(WAV*, ALuint);
void asln_audio_self_test(void);

int asln_audio_init() {
    puts("Initialising Audio...");
    puts("  Allocating Memory...");
    asln_audio = malloc(sizeof(ASLN_AUDIO));
    asln_audio->buffers = malloc(ASLN_MAX_AUDIO_BUFS * sizeof(int));
    asln_audio->sources = malloc(ASLN_MAX_AUDIO_SRCS * sizeof(int));
    printf("  Opening Audio Device... ");
    if ((asln_audio->device = alcOpenDevice(NULL))) {
        WAV *wav;
        printf("Success (Using Device %s)\n  Creating Audio Context... ", alcGetString(asln_audio->device, ALC_DEVICE_SPECIFIER));
        asln_audio->context = alcCreateContext(asln_audio->device, NULL);
        alcMakeContextCurrent(asln_audio->context);
        printf("Success\n  Generating Buffers... ");
        alGenBuffers(ASLN_MAX_AUDIO_BUFS, asln_audio->buffers);
        alGenSources(ASLN_MAX_AUDIO_SRCS, asln_audio->sources);
        asln_audio->buffer_count = 0;
        puts("Success");
        asln_audio_self_test();
        puts("  Opening Main Music File...");
        wav = import_wav("sound/menu_theme.wav");
        if (wav != NULL) {
            puts("  Playing Main Music...");
            asln_audio_play(wav, 1);
            free_wav(wav);
        } else
            puts("  Failed to Load Menu Music");
    } else
        puts("  Failed");
    puts("  Done Initializing Audio");
    return 0;
}

void asln_audio_play(WAV *wav, ALuint loop) {
    alBufferData(asln_audio->buffers[asln_audio->buffer_count], AL_FORMAT_STEREO16, wav->data, wav->size, wav->freq);
    alSourcei(asln_audio->sources[asln_audio->buffer_count], AL_BUFFER, (ALint)asln_audio->buffers[asln_audio->buffer_count]);
    alSourcei(asln_audio->sources[asln_audio->buffer_count], AL_LOOPING, loop);
    alSourcePlay(asln_audio->sources[asln_audio->buffer_count]);
    asln_audio->buffer_count++;
}

void asln_audio_self_test() {
    WAV *wav;
    printf("  Performing Audio Test... ");
    wav = import_wav("sound/test.wav");
    if (wav != NULL) {
        asln_audio_play(wav, 0);
        free_wav(wav);
        printf("%s\n", alGetString(alGetError()));
    } else
        puts("Failed");
    sleep(1);
}
