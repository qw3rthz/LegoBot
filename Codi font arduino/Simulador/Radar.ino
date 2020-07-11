/* Funcions de control dels radars*/

void echoCheck0() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
    if (radar[0].check_timer()) {
      dis[0] = radar[0].ping_result / US_ROUNDTRIP_CM;
      Serial.print("Obstacle davant: ");
      Serial.println(dis[0]);
    } else {
      //dis[0] = 0;
      dis[0] =  0;
    }
  // Don't do anything here!
}

void echoCheck1() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
    if (radar[1].check_timer()) {
      dis[1] = radar[1].ping_result / US_ROUNDTRIP_CM;
      Serial.print("Obstacle darrere: ");
      Serial.println(dis[1]);
    } else {
      //dis[1] = 0;
      dis[1] =  0;
    }
  // Don't do anything here!
}

/*void llegirRadar() {
  dis[0] = llegirRadarDavant();
  dis[1] = llegirRadarDarrere();
}
int llegirRadarDavant () {
  return radar[0].ping_cm();  
}

int llegirRadarDarrere () {
  return radar[1].ping_cm();
}*/
