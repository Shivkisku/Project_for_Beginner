#include <stdio.h>
#include <espeak-ng/speak_lib.h>

#define MAX_TEXT_LENGTH 200

int main() {
    char text[MAX_TEXT_LENGTH];

    printf("Enter the text to speak: ");
    fgets(text, sizeof(text), stdin);

    espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, NULL, 0);
    espeak_Synth(text, strlen(text) + 1, 0, POS_CHARACTER, 0, espeakCHARS_AUTO, NULL, NULL);
    espeak_Synchronize();

    return 0;
}
