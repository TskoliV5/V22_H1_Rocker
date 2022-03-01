#include <Servo.h>
#include <VexMotor.h>

Servo munnur;
Servo haus;
VexMotor likami(10);

int pos = 110;

int ledPin = 13;                // choose the pin for the LED
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input


  munnur.attach(9);
  haus.attach(11);

  likami.set(10);
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value

  if (val == HIGH)  // check if the input is HIGH
  {
    digitalWrite(ledPin, HIGH);  // turn LED ON

    if (pirState == LOW) 
  {
      Serial.println("Motion detected!"); // print on output change
      pirState = HIGH;

      likami.set(57);
      delay(4510);
      likami.set(0);
      delay(500);
    
      
      // Hreyfing á stóra servo til að hreyfa hausinn til hliðar
    
      for (pos = 100; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
        haus.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 60; pos <= 130; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        haus.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 130; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
        haus.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 60; pos <= 130; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        haus.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 130; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
        haus.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 60; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        haus.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);  
      }
      delay(500);
    
    
        // Hreyfing á litla bláa servo til að opna og loka munn
    
      for (pos = 110; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 150; pos >= 110; pos -= 1) { // goes from 180 degrees to 0 degrees
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 110; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 150; pos >= 110; pos -= 1) { // goes from 180 degrees to 0 degrees
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 110; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 150; pos >= 110; pos -= 1) { // goes from 180 degrees to 0 degrees
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 110; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 150; pos >= 110; pos -= 1) { // goes from 180 degrees to 0 degrees
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 110; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
       for (pos = 150; pos >= 110; pos -= 1) { // goes from 180 degrees to 0 degrees
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 110; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        munnur.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    }
  } 
  else 
  {
    digitalWrite(ledPin, LOW); // turn LED OFF

    if (pirState == HIGH)
  {
      Serial.println("Motion ended!");  // print on output change
      pirState = LOW;
    }
  }
}
