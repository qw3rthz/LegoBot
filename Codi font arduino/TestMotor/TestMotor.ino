/* Test del circuit dels motors del XJ-LegoBot
Funcions disponibles:
  anarEndavant(velocitat): Posa en marxa els dos motors i fa anar el vehicle endavant a la velocitat indicada.
  anarEnrere(velocitat): Posa en marxa els dos motors i fa anar el vehicle enrere a la velocitat indicada.
  parar(): Atura els dos motors. Para el vehicle.

  pararMotorA(): Atura el motor A.
  pararMotorB(): Atuea el motor B.
  anarEndavantA(velocitat): Posa en marxa el motor A endavant a la velocitat indicada.
  anarEndavantB(velocitat): Posa en marxa el motor B endavant a la velocitat indicada.
  anarEnrereA(velocitat): Posa en marxa el motor A enrere a la velocitat indicada.
  anarEnrereA(velocitat): Posa en marxa el motor B enrere a la velocitat indicada.
*/

int mAVelocitat = 3;
int mAEndavant =  7;
int mAEnrere =    8;

int mBVelocitat = 5;
int mBEndavant =  12;
int mBEnrere =    13;

int pausa =       1000;


void setup() {
  pinMode(mAVelocitat,  OUTPUT);
  pinMode(mAEndavant,   OUTPUT);
  pinMode(mAEnrere,     OUTPUT);
  
  pinMode(mBVelocitat,  OUTPUT);
  pinMode(mBEndavant,   OUTPUT);
  pinMode(mBEnrere,     OUTPUT);

}

void loop() {
  //Motors endavant
  anarEndavant(255);
  aturaPausa();
  //Motors enrere
  anarEnrere(255);
  aturaPausa();
  //Motor A endavant. Motor B aturat
  anarEndavantA(255);
  aturaPausa();
  //Motor A endavant. Motor B enrere
  anarEndavantA(255);
  anarEnrereB(255);
  aturaPausa();
  //Motor A aturat. Motor B endavant
  anarEndavantB(255);
  aturaPausa();
  //Motor A enrere. Motor B endavant
  anarEnrereA(255);
  anarEndavantB(255);
  aturaPausa();
}
//Pràctica: Indicar quin motor afecta la funció (A, B, A i B)
//Parar el vehicle
void parar() {
  pararMotorA();
  pararMotorB();
}

void aturaPausa() {
  delay(pausa);
  parar();
  delay(pausa);
}

void pararMotorA() {
  analogWrite(mAVelocitat, 0);
  digitalWrite(mAEndavant, LOW);
  digitalWrite(mAEnrere, LOW);
}

void pararMotorB() {
  analogWrite(mBVelocitat, 0);
  digitalWrite(mBEndavant, LOW);
  digitalWrite(mBEnrere, LOW);
}

//Marxa endavant
void anarEndavant(int velocitat) {
  anarEndavantA(velocitat);
  anarEndavantB(velocitat);
}

void anarEndavantA(int velocitat) {
  digitalWrite(mAEndavant, HIGH);
  digitalWrite(mAEnrere, LOW);
  analogWrite(mAVelocitat, velocitat);
}

void anarEndavantB(int velocitat) {
  digitalWrite(mBEndavant, HIGH);
  digitalWrite(mBEnrere, LOW);
  analogWrite(mBVelocitat, velocitat);
}

//Marxa enrere
void anarEnrere(int velocitat) {
  anarEnrereA(velocitat);
  anarEnrereB(velocitat);
}

void anarEnrereA(int velocitat) {
  digitalWrite(mAEndavant, LOW);
  digitalWrite(mAEnrere, HIGH);
  analogWrite(mAVelocitat, velocitat);
}

void anarEnrereB(int velocitat) {
  digitalWrite(mBEndavant, LOW);
  digitalWrite(mBEnrere, HIGH);
  analogWrite(mBVelocitat, velocitat);
}
