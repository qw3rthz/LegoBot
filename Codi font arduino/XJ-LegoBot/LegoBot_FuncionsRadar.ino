/* Funcions de control dels radars*/

int llegirRadarDavant () {
  return radar[0].ping_cm();  
}

int llegirRadarDarrere () {
  return radar[1].ping_cm();
}
