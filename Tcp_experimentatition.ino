# define UART_BAUD 9600

#ifndef STASSID
#define STASSID "" // Name of your router
#define STAPSK  "" // Password of your router
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
const int port = 23034;


#include <ESP8266WiFi.h>
#include <WiFiClient.h>


WiFiServer server(port);
WiFiClient client;

uint8_t buf1[1024];
uint8_t i1 = 0;

uint8_t buf2[1024];
uint8_t i2 = 0;

#include <Keypad.h>
const byte ROW = 4;
const byte COL = 5;
char my_keys[ROW][COL] = {
  {'A', 'B', 'C', 'D', 'E'},
  {'F', 'G', 'H', 'I', 'J'},
  {'K', 'L', 'M', 'N', 'O'},
  {'P', 'Q', 'R', 'S', 'T'},
};

byte colPins[COL] = {5,4,0,2,14};
byte rowPins[ROW] = {12,13,10,3};

Keypad customKeypad = Keypad(makeKeymap(my_keys), rowPins, colPins, ROW, COL);


void setup() {
  // put your setup code here, to run once:

  delay(500);
  Serial.begin(UART_BAUD);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);

  Serial.println("");
  while(WiFi.status()!= WL_CONNECTED){
    Serial.print(".");
    delay(50);
  }

  // Configure static IP address

  IPAddress ip(192, 168, 16, 182);
  IPAddress gateway(192, 168, 1, 1);
  Serial.println("");
  Serial.print("Setting static IP Address to:");
  Serial.println(ip);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet);

  Serial.println("");
  Serial.println("Connected to ");
  Serial.println(ssid);
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
  server.begin(); // start tcp server


}

void loop() {
  int counter;
  char customKey = customKeypad.getKey();

  // Wait for a client to connect
    if (!client.connected()){
      client = server.available();
      return;
    }



    if(client.available()){
      while(client.available()){
        buf1[i1] = (uint8_t)client.read();
        if(i1<1023) i1++;
    }
    if(buf1[1] == '0'){
      Serial.write("Write key1");
      client.write("101");
    }

//    for(counter = 0; counter < i1; counter ++){
//      Serial.write(buf1[counter]);
//    }
 
    Serial.write(buf1, i1);
    i1 = 0;
    }

    if(customKey){
      Serial.print("This key has been pressed: ");
      Serial.println(customKey);  
      switch(customKey){
        case 'A':
          client.write("A", 1);
          break;        
        case 'B':
          client.write("B", 1);
          break;
        case 'C':
          client.write("C", 1);
          break;
        case 'D':
          client.write("D", 1);
          break;
        case 'E':
          client.write("E", 1);
          break;
        case 'F':
          client.write("F", 1);
          break;
        case 'G':
          client.write("G", 1);
          break;
        case 'H':
          client.write("H", 1);
          break;
        case 'I':
          client.write("I", 1);
          break;
        case 'J':
          client.write("J", 1);
          break;
        case 'K':
          client.write("K", 1);
          break;
        case 'L':
          client.write("L", 1);
          break;
        case 'M':
          client.write("M", 1);
          break;   
        case 'N':
          client.write("N", 1);
          break;
        case 'O':
          client.write("O", 1);
          break;
        case 'P':
          client.write("P", 1);
          break;   
        case 'Q':
          client.write("Q", 1);
          break;
        case 'R':
          client.write("R", 1);
          break;
        case 'S':
          client.write("S", 1);
          break;   
        case 'T':
          client.write("T", 1);
          break;
      }
    }
}
