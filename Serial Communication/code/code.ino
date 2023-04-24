/* Serial programming for ESP8266

   Hardware Component :
        ESP8266

   Author : IEEE Projects Bengaluru

   Contact us:
       Website: https://ieeeprojectsbengaluru.godaddysites.com/
       Youtube Channel: https://www.youtube.com/channel/UCKEkm5M_eVhb_NLZtv-M8MA

*/

// Define baud rates
const int baudRates = 4800; //{4800, 9600, 19200, 115200};

void setup()
{
  // Do nothing
}

void loop()
{

    Serial.begin(baudRates);
    Serial.flush();
    Serial.print("Hello World! BaudRate =");
    Serial.println(baudRates);

    delay(3000);

}
