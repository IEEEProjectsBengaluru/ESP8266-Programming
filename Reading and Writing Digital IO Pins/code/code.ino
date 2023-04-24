/* This program demonstrates the usage of Digital IO operations
 * 
 * Hardware Component :  
 *      ESP8266
 * 
 * Circuit info: 
 *      D0 and D1 of ESP8266 module connected in a loop
 *
 * Author : IEEE Projects Bengaluru
 * 
 * Contact us: 
 *     Website: https://ieeeprojectsbengaluru.godaddysites.com/ 
 *     Youtube Channel: https://www.youtube.com/channel/UCKEkm5M_eVhb_NLZtv-M8MA 
 *
 */


const int INPUTPIN = D0;
const int OUTPUTPIN = D1;

void setup() 
{
  // Configure input pin to INPUT mode
  pinMode(INPUTPIN,INPUT);

  // Configure output pin to OUTPUT mode
  pinMode(OUTPUTPIN, OUTPUT);

  // Configure serial
  Serial.begin(9600);
  Serial.flush();
  
  // Write HIGH value and read
  digitalWrite(OUTPUTPIN,HIGH);
  Serial.println("Writing data -> 1");
  Serial.print(" Reading data <- ");
  Serial.println(digitalRead(INPUTPIN));

  delay(2000);

  // Write LOW value and read
  digitalWrite(OUTPUTPIN,LOW);
  Serial.println("Writing data -> 0");
  Serial.print(" Reading data <- ");
  Serial.println(digitalRead(INPUTPIN));
}

void loop() 
{
   // Write HIGH value and read
  digitalWrite(OUTPUTPIN,HIGH);
  Serial.println("Writing data -> 1");
  Serial.print("Reading data <- ");
  Serial.println(digitalRead(INPUTPIN));

  delay(2000);

  // Write LOW value and read
  digitalWrite(OUTPUTPIN,LOW);
  Serial.println("Writing data -> 0");
  Serial.print("Reading data <- ");
  Serial.println(digitalRead(INPUTPIN));

  delay(2000);

}
