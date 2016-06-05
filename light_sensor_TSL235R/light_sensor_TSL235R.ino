/*
 *    FILE: demo01.pde
 *  AUTHOR: Rob Tillaart
 *    DATE: 2011 05 16
 *
 * PURPOSE: prototype TSL235R monitoring  
 * http://playground.arduino.cc/Main/TSL235R
 *
 * Digital Pin layout ARDUINO
 * =============================
 *  2     IRQ 0    - to TSL235R
 * A1     TEMP     - to LM35
 * 
 * TSL235R
 * PIN 1 - GND
 * PIN 2 - VDD - 5V
 * PIN 3 - SIGNAL
 * 
 * LM35
 * PIN 1 - VDD
 * PIN 2 - SIGNAL
 * PIN 3 - GND
 */
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 0, 1, 2);

EthernetServer server(80);

volatile unsigned long cnt = 0;
unsigned long oldcnt = 0;
unsigned long t = 0;
unsigned long last;

int val;
int tempPin = 1;

void irq1()
{
  cnt++;
}

///////////////////////////////////////////////////////////////////
//
// SETUP
//
void setup() 
{
  Serial.begin(9600);
  Serial.println("START");
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  attachInterrupt(0, irq1, RISING);
  
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

///////////////////////////////////////////////////////////////////
//
// MAIN LOOP
//
void loop() 
{
//  if (millis() - last >= 1000)
//  {
//    // LIGHT
//    last = millis();
//    t = cnt;
//    unsigned long hz = t - oldcnt;
//    Serial.print("FREQ: "); 
//    Serial.print(hz);
//    Serial.print("\t = "); 
//    Serial.print((hz+50)/100);  // +50 == rounding last digit
//    Serial.println(" mW/m2");
//    oldcnt = t;
//    
//    // TEMP
//    val = analogRead(tempPin);
//    float mv = ( val/1024.0)*5000;
//    float cel = mv/10;
//    float farh = (cel*9)/5 + 32;
//    
//    Serial.print("TEMPRATURE = ");
//    Serial.print(cel);
//    Serial.print("*C");
//    Serial.println();
//  }
EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin
          
            int val = analogRead(tempPin);
            float mv = ( val/1024.0)*5000;  
            float cel = mv/10;
            float farh = (cel*9)/5 + 32;
            Serial.print("TEMPRATURE = ");
            Serial.print(cel);
            Serial.print("*C");
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(cel);
            client.println("<br />");
          
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
