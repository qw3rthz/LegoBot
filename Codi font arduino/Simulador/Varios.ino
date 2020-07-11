// Altres funcions

void pausa(int duracio) {
  if (!timerPausa.isRunning()) {
    timerPausa.start(duracio);
    while (!timerPausa.justFinished()) {
    //digitalWrite(led, HIGH);
    }  
  }
}
