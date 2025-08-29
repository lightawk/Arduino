/* 
 * Variables
 */

// => 1. Broches numériques & analogiques

const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
// Broche de contrôle de la direction du moteur
const int directionSwitchPin = 4;
// Broche de démarrage / arrêt du moteur
const int onOffSwitchStateSwitchPin = 5;
// Broche analogique pour le réglage de la vitesse du moteur
const int potPin = A0;

// => 2. Variables pour le stockage des valeurs provenant des capteurs

// Etat ON/OFF
int onOffSwitchState = 0;
// Etat precedent ON/OFF
int previousOnOffSwitchState = 0;

// Direction
int directionSwitchState = 0;
// Direction precedente
int previousDirectionSwitchState = 0;

// Moteur
int motorEnabled = 0;   // Actif
int motorSpeed = 0;     // Vitesse
int motorDirection = 1; // Direction

/* 
 * Setup : Attribution des I/O
 */
void setup() {
  Serial.begin(9600);
  // Interrupteurs en entree (Interrupteurs => Arduino)
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  // Broches du pont en H en sortie (Arduino => Pont H)
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  // Mettre la broche 9 (mise en route du pont en H) a l'etat bas ; le moteur ne tourne pas
  digitalWrite(enablePin, LOW);
}

/* 
 * Boucle principale
 */
void loop() {
  // Lire l'etat de l'interrupteur ON/OFF
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  //Serial.println(onOffSwitchState);
  // Attente
  delay(1);
  // Lire l'etat de l'interrupteur de direction
  directionSwitchState = digitalRead(directionSwitchPin);
  //Serial.println(directionSwitchState);
  // Vitesse du moteur (lecture de la broche analogique puis on divise par 4)
  motorSpeed = analogRead(potPin)/4;

  Serial.println(motorSpeed);
  // Verifier si l'etat du capteur ON/OFF a change (comparer l'etat avant / apres de l'interrupteur ON/OFF)
  if(onOffSwitchState != previousOnOffSwitchState) {
    // Si l'interrupteur ON/OFF est a l'etat haut on demarre le moteur sinon on l'arrete
    if(onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }
  // Verifier si la direction a change (comparer l'etat avant / apres de l'interrupteur de direction)
  if(directionSwitchState != previousDirectionSwitchState) {
    // Si l'interrupteur de direction est a l'etat haut on change le sens de rotation du moteur
    if(directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }
  // Sens de rotation du moteur
  if(motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  // Controle du moteur en PWM
  if(motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);
  }
  // L'etat de direction courant devient l'etat precedent
  previousDirectionSwitchState = directionSwitchState;
  // L'etat courant ON/OFF devient l'etat precedent
  previousOnOffSwitchState = onOffSwitchState;
}
