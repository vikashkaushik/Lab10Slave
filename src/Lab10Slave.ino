/*
 * Project Lab10Second
 * Description: Slave
 * Author: Vikash Kaushik
 * Date: 7/7/21
 */
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#include <Wire.h>
// setup() runs once, when the device is first turned on.
void setup()
{
  pinMode(D7,OUTPUT); // led
  pinMode(D6,INPUT); // button
  // Put initialization like pinMode and begin functions here.
  Wire.begin(0x2A); // Initialize as a slave with address 0x2A
  Wire.onReceive(receiveEvent); // in setup
  Wire.onRequest(requestEvent); // in setup
}
char x;
char value; // button true or false
// revieves from master and lights up based on char value
void receiveEvent(int howMany)
{
  x = Wire.read();
  if(x == '0'){
    digitalWrite(D7,LOW);
  }

  if(x == '1'){
    digitalWrite(D7,HIGH);
  }
  
}
// reads the button state and sends back to master
void requestEvent() {
  
  value = digitalRead(D6);  // reads the button either true or false
  Serial.println(value); 
  Wire.write(value);
  
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  
  
}

