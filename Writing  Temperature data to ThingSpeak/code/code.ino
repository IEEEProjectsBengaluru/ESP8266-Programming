/* Interfacing TMP102 Temperature Sensor to ESP8266 and uploading data to ThingSpeak
 *
 *  Hardware used
 *      ESP8266MOD
 *      TMP102
 *
 *  Connections
 *    - Connect TMP102 VCC to ESP8266MOD 3V
 *    - Connect TMP102 GND to ESP8266MOD G
 *    - Connect TMP102 SCL to ESP8266MOD D1(GPIO5)
 *    - Connect TMP102 SDA to ESP8266MOD D2(GPIO4)
 *    
 *  Dependencies
 *    - SparkFun TMP102 library:  http://librarymanager/All#SparkFun_TMP102
 *    - ThingSpeak library
 *
 * Author : IEEE Projects Bengaluru
 * 
 * Contact us: 
 *     Website: https://ieeeprojectsbengaluru.godaddysites.com/ 
 *     Youtube Channel: https://www.youtube.com/channel/UCKEkm5M_eVhb_NLZtv-M8MA 
 *
 */

// Include the SparkFun TMP102 library.
#include <Wire.h>
#include <SparkFunTMP102.h> 
#include <ESP8266WiFi.h>

// Header file where SECRET_SSID, SECRET_PASS, SECRET_CH_ID and SECRET_WRITE_APIKEY
#include "secrets.h"

 // always include thingspeak header file after other header files and custom macros
#include "ThingSpeak.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0;
WiFiClient  client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

int number = 0;
float temperature;

// Create a TMP102 object
TMP102 sensor0;

unsigned long long int lastTime = -20000;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  Wire.begin(); //Join I2C Bus

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  if (!sensor0.begin())
  {
    Serial.println("Cannot connect to TMP102.");
    Serial.println("Is the board connected? Is the device ID correct?");
    while (1);
  }

  Serial.println("Connected to TMP102!");
  delay(100);

  // Initialize sensor0 settings
  // set the Conversion Rate (how quickly the sensor gets a new reading)
  //0-3: 0:0.25Hz, 1:1Hz, 2:4Hz, 3:8Hz
  sensor0.setConversionRate(2);

  //set Extended Mode.
  //0:12-bit Temperature(-55C to +128C) 1:13-bit Temperature(-55C to +150C)
  sensor0.setExtendedMode(0);

}

void loop()
{

  if (millis() - lastTime > 20000) {
    // read temperature data
    //temperature = sensor0.readTempF();
    temperature = sensor0.readTempC();

    // Print temperature and alarm state
    Serial.print("Temperature: ");
    Serial.println(temperature);

    int x = ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
    if (x == 200) // success
    {
      Serial.println("Channel update successful.");
    }
    else 
    {
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }

    lastTime = millis();
  }
}
