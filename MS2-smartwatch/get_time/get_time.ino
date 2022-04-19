#include <WiFi.h>
#include "time.h"

struct tm timenow;  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Wifi - Connecting");
  WiFi.begin("realme8", "12345678");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  //configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  configTime(19800, 0, "pool.ntp.org");
  if(!getLocalTime(&timenow))
  {
    Serial.println("Failed to obtain time");
    return;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!getLocalTime(&timenow))
    {
      Serial.println("Failed to obtain time");
      return;
    }
   Serial.println(&timenow, "%A, %B %d %Y %H:%M:%S");
   delay(1000);
}
