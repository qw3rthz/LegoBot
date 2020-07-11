/* Control del XJ-LegoBot
Funcions disponibles:
  anarEndavant(velocitat):  Posa en marxa els dos motors i fa anar el vehicle endavant a la velocitat indicada.
  anarEnrere(velocitat):    Posa en marxa els dos motors i fa anar el vehicle enrere a la velocitat indicada.
  accelerarEndavant():      Posa en marxa els dos motors i fa anar el vehicle endavant, accelerant el vehícle poc a poc fins a la velocitat màxima.
  accelerarEnrere():        Posa en marxa els dos motors i fa anar el vehicle enrere, accelerant el vehícle poc a poc fins a la velocitat màxima.
  aturar():                 Atura els dos motors. Para el vehicle.
  aturarMotorA():           Atura el motor A.
  anarEndavantA(velocitat): Posa en marxa el motor A endavant a la velocitat indicada.
  anarEnrereA(velocitat):   Posa en marxa el motor A enrere a la velocitat indicada.
  aturarMotorB():           Atura el motor B.
  anarEndavantB(velocitat): Posa en marxa el motor B endavant a la velocitat indicada. 
  anarEnrereB(velocitat):   Posa en marxa el motor B enrere a la velocitat indicada.
  girarXXDreta():           Gira XX graus cap a la dreta. XX pot ser 30, 90.
  girarXXEsquerra()         Gira XX graus cap a l'esquerra. XX pot ser 30, 90.
  llegirRadarDavant():      Retorna la lectura de distància del radar davanter. Si no detecta res retorna 0.
  llegirRadarDarrere():     Retorna la lectura de distància der radar del darrere. Si no detecta res retorna 0.
*/
#include <NewPing.h>            //Llibreria de control dels sensors ultrasònics.
#include <millisDelay.h>        //Llibreria per generar temporitzadors

#define NUM_RADAR           2   // Nombre de radars utilitzats.
#define DISTANCIA_MAX_RADAR 7  // Distància màxima de detecció en cm per cada radar.
#define RADAR_DAVANT 9         //Pin del radar davanter
#define RADAR_DARRERE 10        //Pin del radar del darrere

#define VELOCITAT_MAX 255       //Velocitat màxima dels motors
#define VELOCITAT_MIN 150       //Velocitat mínima dels motors
#define mAturat 0              //Estat del motor: atura
#define mEndavant 1            //Estat del motor: en marxa endavant
#define mEnrere 2
#define mDreta 3
#define mEsquerra 4//Estat del motor: en marxa enrere
#define TEMPS_GIR 150           //Temps que ha de girar el vehícle a maxima velocitat per fer un gir de 30º

byte mAVelocitat =    5;
byte mAEndavant =     8;
byte mAEnrere =       7;

byte mBVelocitat =    6;
byte mBEndavant =     2;
byte mBEnrere =       4;

byte estatMotor =    0;
byte estatMotorAnterior = 0;

byte dis[NUM_RADAR] = {0, 0}; //Variables de distància: 0-radar davanter, 1- radar del darrere

byte delayTime0 = 50;
unsigned long delayStart0 = 0;
bool delayRunning0 = false;
byte delayTime1 = 70;
unsigned long delayStart1 = 0;
bool delayRunning1 = false;
//unsigned long pingTimer;      //

/* Definició dels radars.
      radar[0]: radar frontal.
      radar[1]: radar del darrere.
 */
NewPing radar[NUM_RADAR] = {   // Definició de les instàncies dels radars instal.lats.
  NewPing(RADAR_DAVANT, RADAR_DAVANT, DISTANCIA_MAX_RADAR), // Per cada radar s'ha de definir el pin de trigger, el d'echo i la distància màxima de detecció.
  NewPing(RADAR_DARRERE, RADAR_DARRERE, DISTANCIA_MAX_RADAR)
};

//millisDelay pingTimer0;  //Timer de control de les lectures de radar
//millisDelay pingTimer1;
millisDelay timerPausa;      //Timer per les pauses

void setup() {
  pinMode(mAVelocitat,  OUTPUT);
  pinMode(mAEndavant,   OUTPUT);
  pinMode(mAEnrere,     OUTPUT);
  
  pinMode(mBVelocitat,  OUTPUT);
  pinMode(mBEndavant,   OUTPUT);
  pinMode(mBEnrere,     OUTPUT);

  Serial.begin(115200); //Per controlar la detecció. Eliminar en la versió final

  //delay(2000); //5 segons de espera abans de començar
  //pingTimer0.start(pingSpeed);
  //pingTimer1.start(pingSpeed - 5);
  //anarEnrere(255);
  delayStart0 = millis();
  delayStart1 = millis();
  delayRunning0 = true;
  delayRunning1 = true;
}

void loop() {
  if (delayRunning0 && ((millis() - delayStart0) >= delayTime0)) {
    delayStart0 += delayTime0;
    radar[0].ping_timer(echoCheck0);
  }
  if (delayRunning1 && ((millis() - delayStart1) >= delayTime1)) {
    delayStart1 += delayTime1;
    radar[1].ping_timer(echoCheck1);
  }

  switch (estatMotor) {
    case mAturat:
      switch (estatMotorAnterior) {
        case mEndavant:
          girar90Dreta();
        break;
        case mEnrere:
          girar90Esquerra();
        break;
        case mAturat:
          if (dis[0] == 0) {
            anarEndavant(255);
          }
        break;
      }
    break;
    case mEndavant:
      if (dis[0] > 0) {
        aturar();
      }
    break;
    case mEnrere:
      if (dis[1] > 0) {
        aturar();
      }
    break;
    case mDreta:
    break;
    case mEsquerra:
    break;
  }
  /*switch (dis[0]) {
    case 0:
      //no detecta nada
    break;
    default:
      aturar();
      //girar90Dreta();
      //pausa(1000);
    break;
  }
    switch (dis[1]) {
    case 0:
      //no detecta nada
    break;
    default:
      aturar();
      //girar90Dreta();
      //pausa(1000);
    break;
  }*/
  /*if (dis[0] > 0) {
    aturar();
  } else {
    anarEndavant(255);
  }*/
}
