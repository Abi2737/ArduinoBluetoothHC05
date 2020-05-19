#include <SoftwareSerial.h>

#define RX 0
#define TX 1

#define LED_PIN 13


SoftwareSerial HM10(RX, TX); // RX = 0, TX = 1

char ch;  
String inData = "";

void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  
  pinMode(LED_PIN, OUTPUT); // onboard LED
  digitalWrite(LED_PIN, HIGH); // switch OFF LED
}

void loop()
{
  HM10.listen();  // listen the HM10 port
  while (HM10.available() > 0) {   // if HM10 sends something then read
    ch = HM10.read();
    inData = String(ch);  // save the data in string format
    Serial.write(ch);
  }

 
  if (Serial.available()) {           // Read user input if available.
    delay(10);
    HM10.write(Serial.read());
  }
  
  if (inData == "0") {
    Serial.println("LED OFF");
    
    digitalWrite(LED_PIN, LOW); // switch OFF LED
    delay(500);
  }
  
  if ( inData == "1") {
    Serial.println("LED ON");
    
    digitalWrite(LED_PIN, HIGH); // switch OFF LED
    delay(500);
    digitalWrite(LED_PIN, LOW); // switch OFF LED
    delay(500);
  }
}
