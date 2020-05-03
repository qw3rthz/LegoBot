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

  llegirRadarDavant():      Llegeix la distància al objecte detectat pel radar davanter a la variable distDavant. Si no detecta res retorna 0.
  llegirRadarDarrere():     Llegeix la distància al objecte detectat per radar del darrere a la variable distDarrere. Si no detecta res retorna 0.
  llegirRadars():           Retorna la lectura de distància de tots els radars a les seves variables.
*/
#include <NewPing.h> //Llibreria de control dels sensors ultrasònics.

#define NUM_RADAR           2   // Nombre de radars utilitzats.
#define DISTANCIA_MAX_RADAR 30  // Distància màxima de detecció en cm per cada radar.
#define RADAR_DAVANT 13         //Pin del radar davanter
#define RADAR_DARRERE 12        //Pin del radar del darrere

#define VELOCITAT_MAX 255 //Velocitat màxima dels motors
#define VELOCITAT_MIN 100 //Velocitat mínima dels motors

//int distDavant =      0;  //Distància a la que es troba un objecte del radar davanter.
//int distDarrere =     0;  //Distància a la que es troba un objecte del radar del darrere.

byte mAVelocitat =     5;
byte mAEndavant =      8;
byte mAEnrere =        7;

byte mBVelocitat =     3;
byte mBEndavant =      2;
byte mBEnrere =        4;

byte dis[NUM_RADAR] = {0, 0}; //Variables de distància: 0-radar davanter, 1- radar del darrere

unsigned int pingSpeed = 50;  //Frecuència a la que enviarem un ping (ms). 50ms són 20 vegades per segon.
unsigned long pingTimer;      //

/* Definició dels radars.
      radar[0]: radar frontal.
      radar[1]: radar del darrere.
 */
NewPing radar[NUM_RADAR] = {   // Definició de les instàncies dels radars instal.lats.
  NewPing(RADAR_DAVANT, RADAR_DAVANT, DISTANCIA_MAX_RADAR), // Per cada radar s'ha de definir el pin de trigger, el d'echo i la distància màxima de detecció.
  NewPing(RADAR_DARRERE, RADAR_DARRERE, DISTANCIA_MAX_RADAR)
};

void setup() {
  pinMode(mAVelocitat,  OUTPUT);
  pinMode(mAEndavant,   OUTPUT);
  pinMode(mAEnrere,     OUTPUT);
  
  pinMode(mBVelocitat,  OUTPUT);
  pinMode(mBEndavant,   OUTPUT);
  pinMode(mBEnrere,     OUTPUT);

  Serial.begin(115200);

  delay(5000); //5 segons de espera abans de començar
  pingTimer = millis(); // Comença a contar.
}

void loop() {
  if (millis() >= pingTimer) {
    pingTimer += pingSpeed;    
    radar[0].ping_timer(echoCheck0);
    radar[1].ping_timer(echoCheck1);
  }
  anarEndavant(200);
  if (dis[0] > 0) {
    aturar();
  }
}

void echoCheck0() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
    if (radar[0].check_timer()) {
      dis[0] = radar[0].ping_result / US_ROUNDTRIP_CM;
    } else {
      dis[0] = 0;
    }
  // Don't do anything here!
}

void echoCheck1() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
    if (radar[1].check_timer()) {
      dis[1] = radar[1].ping_result / US_ROUNDTRIP_CM;
    } else {
      dis[1] = 0;
    }
  // Don't do anything here!
}
