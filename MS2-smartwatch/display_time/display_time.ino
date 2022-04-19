#include <WiFi.h>
#include "time.h"
#include <U8g2lib.h>  
#include <Wire.h>

struct tm timenow;  

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,SCL,SDA,U8X8_PIN_NONE); 

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
  u8g2.begin();  
  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!getLocalTime(&timenow))
    {
      Serial.println("Failed to obtain time");
      return;
    }
   
   u8g2.clearBuffer();
   u8g2.setFontPosCenter();
   u8g2.setDrawColor(1);
   u8g2.setFont(u8g2_font_logisoso20_tn);
   u8g2.drawStr(0,31,u8x8_u8toa(timenow.tm_hour, 2));
   u8g2.drawStr(35,31,":");
   u8g2.drawStr(50,31,u8x8_u8toa(timenow.tm_min, 2));
   u8g2.drawStr(85,31,":");
   u8g2.drawStr(100,31,u8x8_u8toa(timenow.tm_sec, 2));
   u8g2.sendBuffer();
   delay(1000);
}
