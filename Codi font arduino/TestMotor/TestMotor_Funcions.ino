/* Funcions dels motors */
//Parar el vehicle
void aturar() {
  AturarMotorA();
  AturarMotorB();
}

void aturaPausa() {
  if (!timerPausa.isRunning()) {
    timerPausa.start(temps * 2);
      while (!timerPausa.justFinished()) {
        if (timerPausa.remaining() <= temps) {
          aturar();
        }
      }
  } else {
   
  }
}

void AturarMotorA() {
  analogWrite(mAVelocitat, 0);
  digitalWrite(mAEndavant, LOW);
  digitalWrite(mAEnrere, LOW);
}

void AturarMotorB() {
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
