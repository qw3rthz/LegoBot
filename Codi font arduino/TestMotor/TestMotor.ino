/* Test del circuit dels motors del XJ-LegoBot
Funcions disponibles:
  anarEndavant(velocitat): Posa en marxa els dos motors i fa anar el vehicle endavant a la velocitat indicada.
  anarEnrere(velocitat): Posa en marxa els dos motors i fa anar el vehicle enrere a la velocitat indicada.
  aturar(): Atura els dos motors. Para el vehicle.

  AturarMotorA(): Atura el motor A.
  AturarMotorB(): Atura el motor B.
  anarEndavantA(velocitat): Posa en marxa el motor A endavant a la velocitat indicada.
  anarEndavantB(velocitat): Posa en marxa el motor B endavant a la velocitat indicada.
  anarEnrereA(velocitat): Posa en marxa el motor A enrere a la velocitat indicada.
  anarEnrereA(velocitat): Posa en marxa el motor B enrere a la velocitat indicada.
*/

int mAVelocitat =     5;
int mAEndavant =      8;
int mAEnrere =        7;

int mBVelocitat =     3;
int mBEndavant =      2;
int mBEnrere =        4;

int pausa =           1000;
int velocitatMotor =  255;


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
  anarEndavant(velocitatMotor);
  aturaPausa();
  //Motors enrere
  anarEnrere(velocitatMotor);
  aturaPausa();
  //Motor A endavant. Motor B aturat
  anarEndavantA(velocitatMotor);
  aturaPausa();
  //Motor A endavant. Motor B enrere
  anarEndavantA(velocitatMotor);
  anarEnrereB(velocitatMotor);
  aturaPausa();
  //Motor A aturat. Motor B endavant
  anarEndavantB(velocitatMotor);
  aturaPausa();
  //Motor A enrere. Motor B endavant
  anarEnrereA(velocitatMotor);
  anarEndavantB(velocitatMotor);
  aturaPausa();
}
