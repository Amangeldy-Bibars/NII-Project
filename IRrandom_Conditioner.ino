#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include<IRremoteESP8266.h>
const char* ssid = "FLATRON";
    const char* password = "1234567890123";
    const char* host = "95.161.225.76";
 IRsend irsend(D12);
  IRsend irsend2(D11);
int ledPin1 = D12;
int ledPin2 =D11; 
int k=0;

void get_s(String a, int b, int k2)
  {
    WiFiClient client;
     if (client.connect(host, 80))
      { 
          /*Serial.print("\n G  "+String(b)+":\n");
          Serial.println(a);                     
          Serial.println("GET start.");*/
          delay(100);
          client.println("GET /FPGAdev/api/Values/sendDatas?value="+String(a)+"&type=16&device="+String(b)+"&step="+k+" HTTP/1.1");
          client.println("Host: 95.161.225.76");
          client.println("User-Agent: arduino-ethernet");
          client.println("Connection: close");
          client.println();
          //Serial.println("GET end.");
          client.stop();                 
          //Serial.println("\n[Disconnected]\n\n");                  
       }                  
      else
       {
        //Serial.println("connection failed!]\n\n");
        client.stop();                
        }
        
  }
           
void setup() {
  Serial.begin(115200);
  delay(10);

 
  pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, LOW);
  
    pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, LOW);

  Serial.print("Connecting to ");
        Serial.println(ssid);        
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password);        
        while (WiFi.status() != WL_CONNECTED)
        {
          delay(500);
          Serial.print(".");
        }
        Serial.println("");
        Serial.println("WiFi connected");  
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
 
}
             /*-------------2 - ЧАСТЬ---------------*/
             
void loop() {
  k++;
  int value1;
  int value2;
  int a=random(1,5);
  if (a==1) {
  Serial.println("\n Conditioner111(ON)");
    value1 = HIGH;
    get_s("on",12,k);    
          int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8350,4100, 600,1550, 550,500, 600,500, 650,450, 600,1550, 600,450, 650,450, 650,450, 600,500, 600,500, 600,500, 600,450, 600,500, 600,1550, 600,500, 600,500, 600,1500, 600,500, 600,1550, 600,500, 550,500, 600,1550, 600,500, 600,1550, 550,500, 650,450, 600,1550, 600,1500, 600}; //AnalysIR Batch Export (IRremote) - RAW
          irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10); //In this example, the signal will be repeated every 5 seconds, approximately.
          
  }
  if (a==2){
    Serial.println("\n Conditioner111(OFF)");
    //digitalWrite(ledPin1, LOW);
    value1 = LOW;
    get_s("off",12,k);    
     int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8300,3850, 500,1450, 450,500, 450,500, 450,450, 500,450, 450,1500, 450,1450, 450,500, 450,1450, 500,1450, 400,500, 450,500, 450,500, 450,500, 450,450, 500,450, 500,450, 450,500, 500,450, 450,500, 450,500, 450,1450, 450,500, 500,1450, 400,500, 450,500, 450,500, 450,1450, 450}; //AnalysIR Batch Export (IRremote) - RAW
          irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10); //In this example, the signal will be repeated every 5 seconds, approximately.
  }



 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  if (a==3) {
    //digitalWrite(ledPin1, HIGH);
    value2 = HIGH;
    get_s("on",11,k);    
    Serial.println("\n Conditioner222(ON)");
          int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8350,4100, 600,1550, 550,500, 600,500, 650,450, 600,1550, 600,450, 650,450, 650,450, 600,500, 600,500, 600,500, 600,450, 600,500, 600,1550, 600,500, 600,500, 600,1500, 600,500, 600,1550, 600,500, 550,500, 600,1550, 600,500, 600,1550, 550,500, 650,450, 600,1550, 600,1500, 600}; //AnalysIR Batch Export (IRremote) - RAW
          irsend2.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10); //In this example, the signal will be repeated every 5 seconds, approximately.
          
  }
  if (a==4){
    Serial.println("\n Conditioner222(OFF)");
    //digitalWrite(ledPin1, LOW);
    value2 = LOW;
    get_s("off",11,k);    
     int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8300,3850, 500,1450, 450,500, 450,500, 450,450, 500,450, 450,1500, 450,1450, 450,500, 450,1450, 500,1450, 400,500, 450,500, 450,500, 450,500, 450,450, 500,450, 500,450, 450,500, 500,450, 450,500, 450,500, 450,1450, 450,500, 500,1450, 400,500, 450,500, 450,500, 450,1450, 450}; //AnalysIR Batch Export (IRremote) - RAW
          irsend2.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10); //In this example, the signal will be repeated every 5 seconds, approximately.
  }

 delay(1200000);
 
}
