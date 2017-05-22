#include <Servo.h>

int motor;
int lrJoy = 0;
int udJoy = 1;
int coin;
int upSwitch
int downSwitch;
int car;
int go;
int no;
int police;

void setup() {
    Serial.begin(9600);
}

void loop() {
  closeBooth();
  int carState = analogRead(car);
  
  if (carState > 100) {
    int coinState = analogRead(coin);
    if (coinState > 100) {
      green(1);
      openBooth();
    } else {
      red(1);
    }
    
  } 

  int lrState = analogRead(lrJoy);
  int udState = analogRead(udJoy)
  if (udState == 0) {
    openBooth();
  } else {
    closeBooth();
  }

  while (udState == 0 && lrState == 0) {
    
  }
  
}

void openBooth() {
  while (analogRead(openSwitch()) != 1) {
    analogWrite(motor, 120);
  }
}

void closeBooth() {
  while (analogRead(closeSwitch()) != 1) {
    analogWrite(motor, -120);
  }
}

void green (int input) { //go
  if (input == 1) {
    digitalWrite(go, HIGH);
  } else {
    digitalWrite(go, LOW);
  }
}

void red (int input) { //no
  if (input == 1) {
    digitalWrite(no, HIGH);
  } else {
    digitalWrite(no, LOW);
  }
}

void yellow (int input) { //police
  if (input == 1) {
    digitalWrite(police, HIGH);
  } else {
    digitalWrite(poliec, LOW);
  }
}

