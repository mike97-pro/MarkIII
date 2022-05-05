#include <Mark.h>
int leggiIntero(int times)
{
  int incomingByte;
  char Data[8];
  int i = 0;
  unsigned long Tempo;
  do {
    if (Serial1.available()) {
      Data[i] = Serial1.read();
      i++;
    }
    if (i < 1)Tempo = millis();
  } while (i < 5 && (millis() - Tempo) < times);

  Data[i] = 0;
  incomingByte = atoi(Data);

  return incomingByte;
};
Mark jarvis;
char scelta = ' ';
void setup()
{
  jarvis.waiting();
  jarvis.waiting();
  jarvis.eyesOn();
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop()
{
  if (Serial1.available())
  {
    scelta = Serial1.read();
    Serial.write(scelta);
  }
  if (scelta == 'c')
  {
    jarvis.clap();
    scelta = ' ';
  }
  if (scelta == 'r')
  {
    jarvis.waiting();
    jarvis.waiting();
    scelta = ' ';
  }
  if (scelta == 'h')
  {
    jarvis.handsUp();
    jarvis.handsUp();
    scelta = ' ';
  }
  if (scelta == 'w')
  {
    jarvis.walkForward();
    scelta = ' ';
  }
  // feader mode
  if (scelta == 'f')
  {
    int sceltaFeader = leggiIntero(300);
    jarvis.feaderMode(sceltaFeader);
    scelta = ' ';
  }
  //handshake joke
  if(scelta == 'j')
  {
    jarvis.handshakeJoke();
    scelta = ' ';
  }

  if(scelta == 'H')
  {
    jarvis.handShake();
    scelta = ' ';
  }
  if (scelta == 'o')
  {
    jarvis.objectDistance();
    scelta = ' ';
  }
  //delay(30);
}
