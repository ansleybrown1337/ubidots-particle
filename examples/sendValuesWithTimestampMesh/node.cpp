/****************************************
 * Include Libraries
 ****************************************/

#include "Ubidots.h"

/****************************************
 * Define Instances and Constants
 ****************************************/

#ifndef UBIDOTS_TOKEN
#define UBIDOTS_TOKEN "..."  // Put here your Ubidots TOKEN
#endif

Ubidots ubidots(UBIDOTS_TOKEN, UBI_INDUSTRIAL, UBI_MESH);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  Serial.begin(115200);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
}

void loop() {
  float value1 = analogRead(A0);
  unsigned long timestamp_seconds = 1553126110L;

  ubidots.add("temperature", value1, NULL,
              timestamp_seconds);  // Change for your variable name

  /* Will send data to a device label that matches the device ID */
  ubidots.meshPublishToUbidots();
  Serial.println("finished");

  delay(5000);
}
