

/*  Example for different sending methods   
 http://code.google.com/p/rc-switch/   
 Need help? http://forum.ardumote.com*/

#include <RCSwitch.h>
const int buttonPin = 3;
int buttonState = 0;
const int buttonPin2 = 2;
int buttonState2 = 0;
RCSwitch mySwitch = RCSwitch();
void setup() {
 pinMode(buttonPin, INPUT);
 pinMode(buttonPin2, INPUT);
  Serial.begin(9600);

  // Transmitter is connected to Arduino Pin #10  mySwitch.enableTransmit(10);

}
void loop() {
buttonState = digitalRead(buttonPin);
buttonState2 = digitalRead(buttonPin2);
if (buttonState == HIGH) {

  mySwitch.send(9, 24);
  delay(100);

}
else {
  if (buttonState2 == HIGH) {

  mySwitch.send(5, 24);
  delay(100);

// turn LED off:
  }
}
  delay(200);
}
