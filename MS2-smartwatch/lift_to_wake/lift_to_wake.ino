#include <U8g2lib.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define lift_threshold 12.0
#define timeout 3000

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
Adafruit_MPU6050 mpu;

sensors_event_t a, g, temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if (!mpu.begin()) 
    Serial.println("Failed to find MPU6050 chip");
  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  
  u8g2.begin();   
  u8g2.setFontPosCenter();
}

void loop() {
  // put your main code here, to run repeatedly:
  u8g2.clear();
  if(lift_check())
  {
    u8g2.drawBox(0,0,127,63);
    u8g2.sendBuffer();
    delay(timeout);
  }
}

int lift_check()
{
  mpu.getEvent(&a, &g, &temp);
  float a_mag = sqrt(pow(a.acceleration.x,2)+pow(a.acceleration.y,2)+pow(a.acceleration.z,2));
  Serial.println(a_mag);
  if(a_mag > lift_threshold)
    return 1;
  return 0;
}
