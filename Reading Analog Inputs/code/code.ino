/* Program for interfacing Potentiometer
 * 
 * Hardware Component :  
 *      ESP8266
 *      Potentiometer
 * 
 * Circuit info: 
 *      Connect Potentiometer pin to A0 of ESP8266 module
 *
 * Author : IEEE Projects Bengaluru
 * 
 * Contact us: 
 *     Website: https://ieeeprojectsbengaluru.godaddysites.com/ 
 *     Youtube Channel: https://www.youtube.com/channel/UCKEkm5M_eVhb_NLZtv-M8MA 
 *
 */


const int POTPIN = A0;

// Variable to store the value coming from the potentiometer  
float potValue = 0;  

void setup() 
{
  // Configure serial
  Serial.begin(9600);
  Serial.flush();
}

void loop() 
{
  // Read the value from the pot:
  potValue = analogRead(POTPIN);

  // Display the value in serial terminal
  Serial.print("Value = ");
  Serial.println(potValue);
}
