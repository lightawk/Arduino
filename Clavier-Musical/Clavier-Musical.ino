// Notes qui correspondent aux fréquences (ex: do => 262 Hz)
int notes[] = {262, 294, 330, 349};

void setup() {
  // Initialiser la liaison série
  Serial.begin(9600);
}

void loop() {
  // Lecture de la valeur de la broche analogique A0
  int keyVal = analogRead(A0);
  // Afficher la valeur
  Serial.println(keyVal);
  // Jouer la note correspondante en fonction de la valeur lue via la broche analogique
  if(keyVal == 1023) {
    tone(8, notes[0]);
  } else if(keyVal >= 960 && keyVal <= 1010) {
    tone(8, notes[1]);
  } else if(keyVal >= 505 && keyVal <= 515) {
    tone(8, notes[2]);
  } else if(keyVal >= 5 && keyVal <= 10) {
    tone(8, notes[3]);
  } else {
    noTone(8);
  }
}