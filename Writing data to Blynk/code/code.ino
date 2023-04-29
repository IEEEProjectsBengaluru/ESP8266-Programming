/* Program to write to Blynk app
 * 
 * Hardware Component :  
 *      ESP8266
 * 
 * Steps: 
 *      - Login to Blynk website
 *      - Go to Templates and click on New Template
 *      - Add Name, Hardware, Connection Type and click Done
 *      - Go to Datastreams and add two Virtual Datastreams V0 and V1.
 *      - Go to Web Dashboard and add widgets and set them to V0 and V1 
 *      - Save the Template
 *      - Go to Devices and add a device from the template
 *      
 *
 * Author : IEEE Projects Bengaluru
 * 
 * Contact us: 
 *     Website: https://ieeeprojectsbengaluru.godaddysites.com/ 
 *     Youtube Channel: https://www.youtube.com/channel/UCKEkm5M_eVhb_NLZtv-M8MA 
 *
 */


/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "XXXXXXXXXXXXX"
#define BLYNK_TEMPLATE_NAME "XXXXXXXXXXXXXXX"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXXXXXXXXXXXXXx"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
char ssid[] = "XXXXXX";
char pass[] = "XXXXXX";

BlynkTimer timer;

void setup()
{
  // Start serial with 115200 baud rate
  Serial.begin(115200);

  // Connect to Blynk server
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set intervals for the callbacks
  timer.setInterval(500L, myfunc1);
  timer.setInterval(500L, myfunc2);
}

void loop()
{
  //Run the Blynk library
  Blynk.run();

  //Run the Blynk timer
  timer.run(); 
}

void myfunc1()
{
  // Send data to Blynk using V0 virtual pin
  int myData = random(1024);
  Blynk.virtualWrite(V0, myData);
}

void myfunc2()
{
  // Send data to Blynk using V1 virtual pin
  int myData = random(100);
  Blynk.virtualWrite(V1, myData); 
}
