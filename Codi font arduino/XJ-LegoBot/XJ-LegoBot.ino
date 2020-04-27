/* Control del XJ-LegoBot
Funcions disponibles:
  anarEndavant(velocitat): Posa en marxa els dos motors i fa anar el vehicle endavant a la velocitat indicada.
  anarEnrere(velocitat): Posa en marxa els dos motors i fa anar el vehicle enrere a la velocitat indicada.
  accelerarEndavant(): Posa en marxa els dos motors i fa anar el vehicle endavant, accelerant el vehícle poc a poc fins a la velocitat màxima.
  accelerarEnrere(): Posa en marxa els dos motors i fa anar el vehicle enrere, accelerant el vehícle poc a poc fins a la velocitat màxima.
  aturar(): Atura els dos motors. Para el vehicle.
  aturarMotorA(): Atura el motor A.
  aturarMotorB(): Atura el motor B.
  anarEndavantA(velocitat): Posa en marxa el motor A endavant a la velocitat indicada.
  anarEndavantB(velocitat): Posa en marxa el motor B endavant a la velocitat indicada.
  anarEnrereA(velocitat): Posa en marxa el motor A enrere a la velocitat indicada.
  anarEnrereB(velocitat): Posa en marxa el motor B enrere a la velocitat indicada.

  llegirRadarDavant(): Llegeix la distància al objecte detectat pel radar davanter a la variable distDavant. Si no detecta res retorna 0.
  llegirRadarDarrere(): Llegeix la distància al objecte detectat per radar del darrere a la variable distDarrere. Si no detecta res retorna 0.
  llegirRadars(): Retorna la lectura de distància de tots els radars a les seves variables.
*/
#include <NewPing.h> //Llibreria de control dels sensors ultrasònics.

#define NUM_RADAR           2   // Nombre de radars utilitzats.
#define DISTANCIA_MAX_RADAR 10  // Distància màxima de detecció en cm per cada radar.

#define VELOCITAT_MAX 255 //Velocitat màxima dels motors
#define VELOCITAT_MIN 150 //Velocitat mínima dels motors

int distDavant =      0;  //Distància a la que es troba un objecte del radar davanter.
int distDarrere =     0;  //Distància a la que es troba un objecte del radar del darrere.

int mAVelocitat =     3;
int mAEndavant =      7;
int mAEnrere =        8;

int mBVelocitat =     5;
int mBEndavant =      12;
int mBEnrere =        13;

/* Definició dels radars.
      radar[0]: radar frontal.
      radar[1]: radar del darrere.
 */
NewPing radar[NUM_RADAR] = {   // Definició de les instàncies dels radars instal.lats.
  NewPing(4, 10, DISTANCIA_MAX_RADAR), // Per cada radar s'ha de definir el pin de trigger, el d'echo i la distància màxima de detecció.
  NewPing(2, 9, DISTANCIA_MAX_RADAR)
};

void setup() {
  pinMode(mAVelocitat,  OUTPUT);
  pinMode(mAEndavant,   OUTPUT);
  pinMode(mAEnrere,     OUTPUT);
  
  pinMode(mBVelocitat,  OUTPUT);
  pinMode(mBEndavant,   OUTPUT);
  pinMode(mBEnrere,     OUTPUT);

  accelerarEndavant();
}

void loop() {
  
}
