

#include "pitches.h"

#define BUZZER_PIN 9 // The Arduino pin connected to the buzzer

// notes in the melody:
int melody[] = {
  E4, E4, E4, B4, A4, B4, G4, A4, C4, B4, RST,
  E4, E4, E4, B4, A4, B4, G4, A4, G4, FS4, RST,
  E4, FS4, D4, E4, FS4, D4, E4, G4, FS4, RST, RST,
  E4, FS4, D4, E4, FS4, D4, E4, G4, FS4, RST, RST
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,4,4,4,4,4,4,4,4,4,2,
  4,4,4,4,4,4,4,4,4,4,2,
  4,4,4,4,4,4,4,4,4,4,2,
  4,4,4,4,4,4,4,4,4,4,2

};

void setup() {
  
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER_PIN);
  }
}

void loop() {
  
}
