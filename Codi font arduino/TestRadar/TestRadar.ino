#include <NewPing.h>

#define NUM_RADAR     2   // Nombre de sensors utilitzats.
#define DISTANCIA_MAX 10 // Distància màxima de detecció en cm.

byte ledDavant =   12;
byte ledDarrere =  13;

byte distancia;

NewPing sonar[NUM_RADAR] = {   // Sensor object array.
  NewPing(4, 10, DISTANCIA_MAX), // Per cada sensor s'ha de definir el pin de trigger, el de echo i la distància màxima de detecció.
  NewPing(2, 9, DISTANCIA_MAX)
};

void setup() {
  pinMode(ledDavant, OUTPUT);
  pinMode(ledDarrere, OUTPUT);
  
  Serial.begin(9600); // Obre el monitor sèrie per veure els resultats.
}

void loop() {
  for (int i = 0; i < NUM_RADAR; i++) { // Fa un cicle per tots els sensors i mostra el seu valor.
    delay(250); // Pausa de 250ms entre peticions. Aquest valor no hauría de ser menor de 29ms
    distancia = sonar[i].ping_cm();
    if (distancia != 0 && distancia <= DISTANCIA_MAX) {
      digitalWrite(ledDavant + i, HIGH);
    } else {
      digitalWrite(ledDavant + i, LOW);
    }
    Serial.print("Radar nº ");
    Serial.print(i);
    Serial.print(" Mesurat: ");
    Serial.print(distancia);
    Serial.print("cm ");
    Serial.print("  /  ");
  }
  Serial.println();
}
