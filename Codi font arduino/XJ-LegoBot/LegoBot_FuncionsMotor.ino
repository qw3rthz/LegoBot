/* Funcions dels motors */

//Atura els dos motors. Para el vehicle.
void aturar() {
  AturarMotorA();
  AturarMotorB();
  delay(500);
}

//Atura el motor A.
void AturarMotorA() {
  analogWrite(mAVelocitat, 0);
  digitalWrite(mAEndavant, LOW);
  digitalWrite(mAEnrere, LOW);
}

//Atura el motor B.
void AturarMotorB() {
  analogWrite(mBVelocitat, 0);
  digitalWrite(mBEndavant, LOW);
  digitalWrite(mBEnrere, LOW);
}

//Posa en marxa els dos motors i fa anar el vehicle endavant a la velocitat indicada.
void anarEndavant(int velocitat) {
  anarEndavantA(velocitat);
  anarEndavantB(velocitat);
}

//Posa en marxa el motor A endavant a la velocitat indicada.
void anarEndavantA(int velocitat) {
  digitalWrite(mAEndavant, HIGH);
  digitalWrite(mAEnrere, LOW);
  analogWrite(mAVelocitat, velocitat);
}

//Posa en marxa el motor B endavant a la velocitat indicada.
void anarEndavantB(int velocitat) {
  digitalWrite(mBEndavant, HIGH);
  digitalWrite(mBEnrere, LOW);
  analogWrite(mBVelocitat, velocitat);
}

//Posa en marxa els dos motors i fa anar el vehicle enrere a la velocitat indicada.
void anarEnrere(int velocitat) {
  anarEnrereA(velocitat);
  anarEnrereB(velocitat);
}

//Posa en marxa el motor A enrere a la velocitat indicada.
void anarEnrereA(int velocitat) {
  digitalWrite(mAEndavant, LOW);
  digitalWrite(mAEnrere, HIGH);
  analogWrite(mAVelocitat, velocitat);
}

//Posa en marxa el motor B enrere a la velocitat indicada.
void anarEnrereB(int velocitat) {
  digitalWrite(mBEndavant, LOW);
  digitalWrite(mBEnrere, HIGH);
  analogWrite(mBVelocitat, velocitat);
}

//Posa en marxa els dos motors i fa anar el vehicle endavant, accelerant el vehícle poc a poc fins a la velocitat màxima.
void accelerarEndavant() {
  for (byte i = VELOCITAT_MIN; i < VELOCITAT_MAX; i++) {
    anarEndavant(i);
  }
}

//Posa en marxa els dos motors i fa anar el vehicle enrere, accelerant el vehícle poc a poc fins a la velocitat màxima.
void accelerarEnrere() {
  for (byte i = VELOCITAT_MIN; i < VELOCITAT_MAX; i++) {
    anarEnrere(i);
  }
}

//Gira a la dreta
void girarDreta () {  
  anarEndavantA(200);
  anarEnrereB(200);
}

//Gira a la esquerra
void girarEsquerra () {  
  anarEndavantB(200);
  anarEnrereA(200);
}

void girarDretaRadar() {
  girarDreta ();
  while (llegirRadarDavant != 0) {
    girarDreta();
  }
  aturar();
}
