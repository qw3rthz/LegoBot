#include <NewPing.h>
#include <millisDelay.h>

#define NUM_RADAR     2   // Nombre de sensors utilitzats.
#define DISTANCIA_MAX 10 // Distància màxima de detecció en cm.

byte ledDavant =   12;
byte ledDarrere =  13;

byte dis[NUM_RADAR] = {0, 0}; //Variables de distància: 0-davant, 1-darrere

NewPing sonar[NUM_RADAR] = {   // Sensor object array.
  NewPing(4, 4, DISTANCIA_MAX), // Per cada sensor s'ha de definir el pin de trigger, el de echo i la distància màxima de detecció.
  NewPing(7, 7, DISTANCIA_MAX)
};

millisDelay pingDelay;

void setup() {
  //Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  pinMode (ledDavant, OUTPUT);
  pinMode (ledDarrere, OUTPUT);
  pingDelay.start(50);
}

void loop() {
  if (pingDelay.justFinished()) {
    pingDelay.repeat();
    sonar[0].ping_timer(echoCheck0);
    sonar[1].ping_timer(echoCheck1);
  }
  // Do other stuff here, really. Think of it as multi-tasking.
  /*for (int i = 0; i < NUM_RADAR; i++) {
    Serial.print("Radar nº ");
    Serial.print(i);
    Serial.print(" Mesurat: ");
    Serial.print(dis[i]);
    Serial.print("cm ");
    Serial.println("  /  ");    
  }
  delay(250);*/
  
}

void echoCheck0() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
    if (sonar[0].check_timer()) {
      dis[0] = sonar[0].ping_result / US_ROUNDTRIP_CM;
      digitalWrite(ledDavant, HIGH);
    } else {
      digitalWrite(ledDavant, LOW);
      dis[0] = 0;
    }
  // Don't do anything here!
}

void echoCheck1() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
    if (sonar[1].check_timer()) {
      dis[1] = sonar[1].ping_result / US_ROUNDTRIP_CM;
      digitalWrite(ledDarrere, HIGH);
    } else {
      dis[1] = 0;
      digitalWrite(ledDarrere, LOW);
    }
  // Don't do anything here!
}
