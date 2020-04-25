int m1Velocitat = 3;
int m1Endavant =  7;
int m1Enrere =    8;

int m2Velocitat = 5;
int m2Endavant =  12;
int m2Enrere =    13;

int pausa =       1000;


void setup() {
  pinMode(m1Velocitat,  OUTPUT);
  pinMode(m1Endavant,   OUTPUT);
  pinMode(m1Enrere,     OUTPUT);
  
  pinMode(m2Velocitat,  OUTPUT);
  pinMode(m2Endavant,   OUTPUT);
  pinMode(m2Enrere,     OUTPUT);

}

void loop() {
  anarEndavant(255);
  delay(pausa);
  pararMotors();
  delay(pausa);
  anarEnrere(255);
  delay(pausa);
  pararMotors();
  delay(pausa);
}

void pararMotors() {
  analogWrite(m1Velocitat, 0);
  digitalWrite(m1Endavant, LOW);
  digitalWrite(m1Enrere, LOW);
}

void anarEndavant(int velocitat) {
  digitalWrite(m1Endavant, HIGH);
  digitalWrite(m1Enrere, LOW);
  analogWrite(m1Velocitat, velocitat);
}

void anarEnrere(int velocitat) {
  digitalWrite(m1Endavant, LOW);
  digitalWrite(m1Enrere, HIGH);
  analogWrite(m1Velocitat, velocitat);
}
