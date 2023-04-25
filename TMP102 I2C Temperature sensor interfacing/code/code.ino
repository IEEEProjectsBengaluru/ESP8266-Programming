/* TMP102 temperature sensor interfacing

   Hardware Component :
        ESP8266
        TMP102

   Circuit info:
        Connect VCC of TMP102 to 3V of ESP8266
        Connect GND of TMP102 to G of ESP8266
        Connect SCL of TMP102 to D1 of ESP8266
        Connect SDA of TMP102 to D2 of ESP8266

   Author : IEEE Projects Bengaluru

   Contact us:
       Website: https://ieeeprojectsbengaluru.godaddysites.com/
       Youtube Channel: https://www.youtube.com/channel/UCKEkm5M_eVhb_NLZtv-M8MA

*/

#include "Wire.h"

// This is the I2C address of the senso
#define TMP102_ADDRESS 72 

void setup()
{
  // Start the I2C library
  Wire.begin(); 

  //Start serial communication at 115200 baud
  Serial.begin(115200); 
  Serial.flush();
}

void loop()
{
  getTemperature();
  delay(5000);
}

void getTemperature()
{
  //These are the bytes we read from the TMP102 temperature registers
  byte firstbyte, secondbyte; 
  int val;
  float temperature;

  // Begin the transmission with the sensor address
  Wire.beginTransmission(TMP102_ADDRESS); 
  
  // Sends instruction byte
  Wire.write(0x00);

  // This ends transmission of data from the Arduino to the Temperature sensor
  Wire.endTransmission();

  // Request 2 bytes of data
  Wire.requestFrom(TMP102_ADDRESS, 2);
  Wire.endTransmission();

  // Read two bytes of data
  firstbyte      = (Wire.read());
  secondbyte     = (Wire.read());

  // Concat two bytes
  val = firstbyte;
  if ((firstbyte & 0x80) > 0)
  {
    val |= 0x0F00;
  }
  val <<= 4;
  val |= (secondbyte >> 4);

  // Get temperature 
  temperature = (val * 0.0625);

  // Print temperature
  Serial.print("Temp is ");
  Serial.print("\t");
  Serial.println(temperature);

}
