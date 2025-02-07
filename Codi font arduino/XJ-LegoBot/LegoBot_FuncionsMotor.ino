/* Funcions dels motors */

//Atura els dos motors. Para el vehicle.
void aturar() {
  AturarMotorA();
  AturarMotorB();
  eVehicleAnterior = eVehicle;
  eVehicle = mAturat;
  dis[0] = 0;
  dis[1] = 0;
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
  eVehicleAnterior = eVehicle;
  eVehicle = mEndavant;
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
  eVehicleAnterior = eVehicle;
  eVehicle = mEnrere;
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
    delay(50);
    anarEndavant(i);
  }
}

//Posa en marxa els dos motors i fa anar el vehicle enrere, accelerant el vehícle poc a poc fins a la velocitat màxima.
void accelerarEnrere() {
  for (byte i = VELOCITAT_MIN; i < VELOCITAT_MAX; i++) {
    anarEnrere(i);
    delay(50);
  }
}

//Gira a la dreta
void girarEsquerra () {  
  anarEndavantA(VELOCITAT_MAX);
  anarEnrereB(VELOCITAT_MAX);
}

//Gira a la esquerra
void girarDreta () {  
  anarEndavantB(VELOCITAT_MAX);
  anarEnrereA(VELOCITAT_MAX);
}

//Gira a la esquerra 30º
void girar30Esquerra () {  
  anarEndavantA(VELOCITAT_MAX);
  anarEnrereB(VELOCITAT_MAX);
  delay(TEMPS_GIR);
  eVehicleAnterior = eVehicle;
  eVehicle = mEsquerra;
}

//Gira a la dreta 30º
void girar30Dreta () {  
  anarEndavantB(VELOCITAT_MAX);
  anarEnrereA(VELOCITAT_MAX);
  delay(TEMPS_GIR);
  eVehicleAnterior = eVehicle;
  eVehicle = mDreta;
}

//Gira a la esquerra 90º
void girar90Esquerra () {  
  for ( byte i = 0; i < 3; i++ ) {
    anarEndavantA(VELOCITAT_MAX);
    anarEnrereB(VELOCITAT_MAX);
    delay(TEMPS_GIR);
  }
  aturar();
}

//Gira a la dreta 90º
void girar90Dreta () {
  for ( byte i = 0; i < 3; i++ ) {
    anarEndavantB(VELOCITAT_MAX);
    anarEnrereA(VELOCITAT_MAX);
    delay(TEMPS_GIR);
    llegirRadar();
  }
  aturar();
}
