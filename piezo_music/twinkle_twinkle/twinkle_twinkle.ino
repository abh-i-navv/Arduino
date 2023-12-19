

#include "pitches.h"

#define BUZZER_PIN 9 // The Arduino pin connected to the buzzer

// notes in the melody:
int melody[] = {
  C4, C4, G4, G4, A4 , A4, G4, F4, F4, E4, E4, D4, D4, C4,
  G4, G4, F4, F4, E4, E4, D4, G4, G4, F4, F4, E4, E4, D4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4  , 4  , 4 ,  4 , 4, 4, 2, 4 ,4 , 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4 , 4, 2, 4, 4, 4, 4, 4, 4, 2

};

void setup() {
  
}

void loop() {
  
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = noteDuration * 1.40;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER_PIN);
  }
}
