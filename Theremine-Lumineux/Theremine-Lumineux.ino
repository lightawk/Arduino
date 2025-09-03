// Valeur du capteur
int sensorValue;
// Valeur la plus haute
int sensorLow = 1023;
// Valeur la plus basse
int sensorHigh = 0;
// Constante (built-in LED)
const int ledPin = 13;

// Pour calibrer le capteur
void setup() {
  // Définit la broche numérique 13 comme sortie
  pinMode(ledPin, OUTPUT);
  // Ecrire un état haut sur la broche 13 (=on)
  digitalWrite(ledPin, HIGH);
  // "millis()" renvoie le nombre de millisecondes écoulées depuis que la carte Arduino a commencé à exécuter le programme en cours
  // Ce nombre sera dépassé (reviendra à zéro) après environ 50 jours. / (5000 = 5 sec)
  while(millis() < 5000) {
    // Lire la valeur du capteur
    sensorValue = analogRead(A0);
    // Si la valeur du capteur est plus élevée que la valeur la plus haute
    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // Si la valeur du capteur est inférieure à la valeur la plus basse
    if(sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // Mettre la constante à l'état bas (=off)
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Lire la valeur du capteur
  sensorValue = analogRead(A0);
  // Pour re-mapper une variable à une échelle différente
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  // Jouer le son
  tone(8, pitch, 20);
  // Emettre un délai
  delay(10);
}