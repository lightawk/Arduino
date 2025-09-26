int switchState = 0;

void setup() {
  // Pin(s) 3, 4 & 5 en sortie
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  // Pin 2 en entree
  pinMode(2, INPUT);
}

void loop() {
  // Lire les donnees sur la broche 2
  switchState = digitalRead(2);
  // Si pas d'appui sur le bouton
  if(switchState == LOW) {
    // Allumer la LED verte
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    // Allumer la LED rouge
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    // Attente
    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }
}