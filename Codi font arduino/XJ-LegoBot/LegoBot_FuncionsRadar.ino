/* Funcions de control dels radars*/

void llegirRadarDavant () {
  distDavant = radar[0].ping_cm();  
}

void llegirRadarDarrere () {
  distDavant = radar[1].ping_cm();  
}

void llegirRadars () {
  llegirRadarDavant();
  delay(50);
  llegirRadarDarrere();
}
