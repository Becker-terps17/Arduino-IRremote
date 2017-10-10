/*
 * Code demo for receiving IR message and decoding it
 */

#include <IRremote.h>

int RECV_PIN = 11;
int result = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
//  Serial.println(decode_message(0x45));
  if (irrecv.decode(&results)) {
    Serial.print(decode_message(results.value));
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

char decode_message(int mess){
  int mask = 0xff;
  int message= mess & mask;
  return char(message);
}

