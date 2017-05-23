#include <Servo.h>
Servo myservo; 

int manualOverride = 8; //push Button for manual override
int udJoy = A1; //manual override input, ANALOG
int coin = A2; //pay toll booth, ANALOG
int upSwitch = 9; //toll booth top
int downSwitch = 2; //toll booth bottom
int car = 3; //is car there
int go = 5; //green LED
int no = 12; //red LED
int police = 6; //yellow LED


void setup() {
    Serial.begin(9600);
    myservo.attach(7);

    pinMode(no, OUTPUT);
    pinMode(go, OUTPUT);
    pinMode(police, OUTPUT);
    pinMode(upSwitch, INPUT);
    pinMode(downSwitch, INPUT);
    pinMode(car, INPUT);
    Serial.println("start");   
//    if (digitalRead(manualOverride) == 1) {
//      Serial.println("blah");
//    }
}

void loop() {

  

 while (digitalRead(manualOverride) != 1) {
  Serial.println("continung");
 
     while (digitalRead(car) == 1) { //limit switch 
      Serial.println("there is a car");
            closeBooth();
            red(1);
            int coinState = 0;
            Serial.println("You have 5 seconds to pay.");
            for (int i = 0; i < 5; i++) {
              coinState = analogRead(coin);
              if (coinState > 0) {
                green(1);
                openBooth();
                  break;
              } else {
                red(1);
              }
            }
          if (coinState < 100) {
            
            yellow(1);
            Serial.println("The cops are coming.");
          }    
        }

     openBooth();   

 } 

    //Serial.println("manual");
 
    int udState = analogRead(udJoy);
    //Serial.println(udState);
    
    if (udState < 495) {
      green(1);
      openBooth();
    } else {
      red(1);
      closeBooth();
    }
  
}

void openBooth() {
  while (digitalRead(upSwitch) != 1) {
    myservo.writeMicroseconds(2000);
  }
  myservo.writeMicroseconds(1500);
}

void closeBooth() {
   while (digitalRead(downSwitch) != 1) {
    myservo.writeMicroseconds(1000);
  }
  myservo.writeMicroseconds(1500);
}

void green(int input) { //go
  if (input == 1) {
    digitalWrite(go, HIGH);
    delay(3000);
    green(0);
  } else {
    digitalWrite(go, LOW);
  }
}

void red(int input) { //no
  if (input == 1) {
    delay(1);
    digitalWrite(no, HIGH);
    delay(3000);
    red(0);
  } else {
    digitalWrite(no, LOW);
  }
  
}

void yellow (int input) { //police
  if (input == 1) {
    digitalWrite(police, HIGH);
    delay(3000);
    yellow(0);
  } else {
    digitalWrite(police, LOW);
  }
}
