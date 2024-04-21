

/*
  Simple example for receiving
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/

#include <RCSwitch.h>


int led = 13;
RCSwitch mySwitch = RCSwitch();
#define pressed1 9   //defines incoming data set by user which is transmitted
#define pressed2 5


void setup() {
  Serial.begin(9600);
 mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2 pinMode(led,OUTPUT);
}
void loop() {


  digitalWrite(led,LOW);
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      //  used for checking received data      
         /*Serial.print("Received ");       
          Serial.print( mySwitch.getReceivedValue() );      
          Serial.print(" / ");     
          Serial.print( mySwitch.getReceivedBitlength() );      
          Serial.print("bit ");      
          Serial.print("Protocol: ");     
          Serial.println( mySwitch.getReceivedProtocol() );*/    }
if (mySwitch.getReceivedValue())

{
    process();



}

mySwitch.resetAvailable();


Serial.println("  ");  
}
  digitalWrite(led,LOW);
  
  delay(100);
  
}
void process()
{
  unsigned long res = mySwitch.getReceivedValue();
  
  switch (res){
    case pressed1:
     Serial.println("pressed 1");
     break;
     case pressed2:
     Serial.println("pressed 2");
     break;
     
  }
}

