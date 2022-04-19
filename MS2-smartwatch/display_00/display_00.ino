#include <U8g2lib.h>  
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,SCL,SDA,U8X8_PIN_NONE); 

void setup()
{
  u8g2.begin();   
}

void loop() {
  // put your main code here, to run repeatedly:
  u8g2.clearBuffer();
  u8g2.setFontPosCenter();
  u8g2.setDrawColor(1);
  u8g2.setFont(u8g2_font_logisoso30_tn);
  u8g2.drawStr(20,31,"00");
  u8g2.drawStr(55,31,":");
  u8g2.drawStr(65,31,"00");
  u8g2.sendBuffer();
  delay(1000);
}
