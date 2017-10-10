/*
 *ENES 100 send demo. Messages for ENES, 
 */


#include <IRremote.h>

enum messages {ENES, KEYSTONE, OSV};
messages message = ENES;
int dt = 100;
IRsend irsend;

void setup()
{
  Serial.begin(9600);
  message =  random(0,3);
}

void loop() {
  message =  random(0,3);
  switch(message){
  case(ENES):
//  Serial.print("ENES\n");
  for (int i = 0; i < 3; i++) {
    irsend.sendSony(0x45, 12);
    delay(dt);
    irsend.sendSony(0x4e, 12);
    delay(dt);
    irsend.sendSony(0x45, 12);
    delay(dt);
    irsend.sendSony(0x53, 12);
    delay(dt);
    irsend.sendSony(0x0a, 12);
    delay(dt);
  }
  delay(500);
  break; 
  case(KEYSTONE):
//  Serial.print("KEYSTONE\n");
  for (int i = 0; i < 3; i++) {
    irsend.sendSony(0x4b, 12);
    delay(dt);
    irsend.sendSony(0x45, 12);
    delay(dt);
    irsend.sendSony(0x59, 12);
    delay(dt);
    irsend.sendSony(0x53, 12);
    delay(dt);
    irsend.sendSony(0x54, 12);
    delay(dt);
    irsend.sendSony(0x4f, 12);
    delay(dt);
    irsend.sendSony(0x4e, 12);
    delay(dt);
    irsend.sendSony(0x45, 12);
    delay(dt);
    irsend.sendSony(0x0a, 12);
    delay(dt);
  }
  delay(500);
  break; 
  case(OSV):
//  Serial.print("OSV\n");
  for (int i = 0; i < 3; i++) {
    irsend.sendSony(0x4f, 12);
    delay(dt);
    irsend.sendSony(0x53, 12);
    delay(dt);
    irsend.sendSony(0x56, 12);
    delay(dt);
    irsend.sendSony(0x0a, 12);
    delay(dt);
  }
  delay(500);
  break; 
  }
}
