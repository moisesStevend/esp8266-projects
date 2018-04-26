#include "FS.h"

void setup() {
  Serial.begin(115200);

  bool result = SPIFFS.begin();
  Serial.println("SPIFFS opened: " + result);
  File f = SPIFFS.open("/database.txt", "r");
  
  if (!f) {
    Serial.println("File doesn't exist yet. Creating it");
    File f = SPIFFS.open("/database.txt", "w");
    if (!f) {
      Serial.println("file creation failed");
    }
    f.println("ssid=jicamarca");
    f.println("password=radioobsevatory");
  } else {
    while(f.available()) {
      String line = f.readStringUntil('\n');
      Serial.println(line);
    }
  }
  file.close();
}

void loop() {
  // nothing to do for now, this is just a simple test

}
