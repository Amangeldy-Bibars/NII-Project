#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include<IRremoteESP8266.h>
 IRsend irsend(D12);
  IRsend irsend2(D11);
const char* ssid = "LAB121";
const char* password = "niiadmin123!";
 boolean newInfo = 0; //переменная для новой информации 
int ledPin1 = D12;
int ledPin2 =D11; 
WiFiServer server(80);

            /*-------------1 - ЧАСТЬ---------------*/
           
void setup() {
  Serial.begin(115200);
  delay(10);

  
 
 
  pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, LOW);
  
    pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
             /*-------------2 - ЧАСТЬ---------------*/
             
void loop() {
  int value1;
  int value2;
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
 
  if (request.indexOf("/LED1111=ON") != -1) {
    //digitalWrite(ledPin1, HIGH);
    value1 = HIGH;
    
          int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8350,4100, 600,1550, 550,500, 600,500, 650,450, 600,1550, 600,450, 650,450, 650,450, 600,500, 600,500, 600,500, 600,450, 600,500, 600,1550, 600,500, 600,500, 600,1500, 600,500, 600,1550, 600,500, 550,500, 600,1550, 600,500, 600,1550, 550,500, 650,450, 600,1550, 600,1500, 600}; //AnalysIR Batch Export (IRremote) - RAW
          irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10); //In this example, the signal will be repeated every 5 seconds, approximately.
          
  }
  if (request.indexOf("/LED1111=OFF") != -1){
    //digitalWrite(ledPin1, LOW);
    value1 = LOW;
     int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8300,3850, 500,1450, 450,500, 450,500, 450,450, 500,450, 450,1500, 450,1450, 450,500, 450,1450, 500,1450, 400,500, 450,500, 450,500, 450,500, 450,450, 500,450, 500,450, 450,500, 500,450, 450,500, 450,500, 450,1450, 450,500, 500,1450, 400,500, 450,500, 450,500, 450,1450, 450}; //AnalysIR Batch Export (IRremote) - RAW
          irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10); //In this example, the signal will be repeated every 5 seconds, approximately.
  }
 if (request.indexOf("/LED1111=UP") != -1){
    //digitalWrite(ledPin1, LOW);
    int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8350,4100, 600,1500, 600,500, 600,450, 600,450, 600,1500, 600,500, 550,500, 600,450, 600,500, 550,500, 550,500, 600,450, 600,500, 550,1550, 550,500, 600,500, 600,1500, 550,500, 600,1500, 600,450, 600,500, 550,1550, 550,500, 600,1500, 600,450, 600,500, 600,1500, 550,1550, 550}; //AnalysIR Batch Export (IRremote) - RAW
          irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10);
  }
  if (request.indexOf("/LED1111=LOWW") != -1){
    //digitalWrite(ledPin1, LOW);
    int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {9500,4400, 550,1600, 550,550, 550,550, 550,500, 600,1600, 550,550, 550,500, 600,500, 550,1650, 550,1600, 600,500, 550,550, 550,500, 550,550, 550,500, 600,500, 550,550, 550,500, 600,500, 550,550, 550,500, 550,1650, 550,550, 550,1600, 600,500, 550,550, 550,500, 600,1600, 550}; //AnalysIR Batch Export (IRremote) - RAW
          irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10);
  }


 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  if (request.indexOf("/LED2222=ON") != -1) {
    //digitalWrite(ledPin1, HIGH);
    value2 = HIGH;
    
          int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8350,4100, 600,1550, 550,500, 600,500, 650,450, 600,1550, 600,450, 650,450, 650,450, 600,500, 600,500, 600,500, 600,450, 600,500, 600,1550, 600,500, 600,500, 600,1500, 600,500, 600,1550, 600,500, 550,500, 600,1550, 600,500, 600,1550, 550,500, 650,450, 600,1550, 600,1500, 600}; //AnalysIR Batch Export (IRremote) - RAW
          irsend2.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10); //In this example, the signal will be repeated every 5 seconds, approximately.
          
  }
  if (request.indexOf("/LED2222=OFF") != -1){
    //digitalWrite(ledPin1, LOW);
    value2 = LOW;
     int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8300,3850, 500,1450, 450,500, 450,500, 450,450, 500,450, 450,1500, 450,1450, 450,500, 450,1450, 500,1450, 400,500, 450,500, 450,500, 450,500, 450,450, 500,450, 500,450, 450,500, 500,450, 450,500, 450,500, 450,1450, 450,500, 500,1450, 400,500, 450,500, 450,500, 450,1450, 450}; //AnalysIR Batch Export (IRremote) - RAW
          irsend2.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10); //In this example, the signal will be repeated every 5 seconds, approximately.
  }
 if (request.indexOf("/LED2222=UP") != -1){
    //digitalWrite(ledPin1, LOW);
    int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {8350,4100, 600,1500, 600,500, 600,450, 600,450, 600,1500, 600,500, 550,500, 600,450, 600,500, 550,500, 550,500, 600,450, 600,500, 550,1550, 550,500, 600,500, 600,1500, 550,500, 600,1500, 600,450, 600,500, 550,1550, 550,500, 600,1500, 600,450, 600,500, 600,1500, 550,1550, 550}; //AnalysIR Batch Export (IRremote) - RAW
          irsend2.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10);
  }
  if (request.indexOf("/LED2222=LOWW") != -1){
    //digitalWrite(ledPin1, LOW);
    int khz = 38; // 38kHz carrier frequency for the NEC protocol
          unsigned int irSignal[] = {9500,4400, 550,1600, 550,550, 550,550, 550,500, 600,1600, 550,550, 550,500, 600,500, 550,1650, 550,1600, 600,500, 550,550, 550,500, 550,550, 550,500, 600,500, 550,550, 550,500, 600,500, 550,550, 550,500, 550,1650, 550,550, 550,1600, 600,500, 550,550, 550,500, 600,1600, 550}; //AnalysIR Batch Export (IRremote) - RAW
          irsend2.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
          delay(10);
  }
 
               /*-------------3 - ЧАСТЬ---------------*/
               
  // Return the response


  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
   client. println ("<head> "); //открытие тега Head 
      client. println ("<meta http-equiv='Content-Type' content='text/html ; charset=utf-8'/> "); 
      client. print ("<title>Air Conditioner Control</title>"); //название страницы 
      client. println ("</head>"); //заголовочная информация 
      client. println ("<body>"); 
      client. print ("<H1>AC Control</H1>"); //заголовк на странице 
 
  client.print("CONDITIONER1 is now: ");
 
  if(value1 == HIGH) {
    client.print("ON");  
  } else {
    client.print("OFF");
  }
  
  client.println("<br><br>");
      client. print ("<a href=\"/LED1111=ON\"><button style=\"height:100px;width:100px;\">Включить</button></a>"); 
      //кнопка включить 
 
 client. print ("<a href=\"/LED1111=OFF\"><button style=\"height:100px;width:100px;\">Выключить</button></a>"); 
      //кнопка включить 
       client. print ("<a href=\"/LED1111=UP\"><button style=\"height:100px;width:100px;\">Temp++</button></a>"); 
      //кнопка включить 
       client. print ("<a href=\"/LED1111=LOWW\"><button style=\"height:100px;width:100px;\">Temp--</button></a>"); 
      //кнопка включить 
  client.println("</html>");

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Return the response
 // client.println("HTTP/1.1 200 OK");
 // client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<br><br>");
  
  client.print("CONDITIONER2  is now: ");
 
  if(value2 == HIGH) {
    client.print("ON");  
  } else {
    client.print("OOFF");
  }
  
  client.println("<br><br>");
      client. print ("<a href=\"/LED2222=ON\"><button style=\"height:100px;width:100px;\">Включить</button></a>"); 
      //кнопка включить 
 
 client. print ("<a href=\"/LED2222=OFF\"><button style=\"height:100px;width:100px;\">Выключить</button></a>"); 
      //кнопка включить 
       client. print ("<a href=\"/LED2222=UP\"><button style=\"height:100px;width:100px;\">Temp++</button></a>"); 
      //кнопка включить 
       client. print ("<a href=\"/LED2222=LOWW\"><button style=\"height:100px;width:100px;\">Temp--</button></a>"); 
      //кнопка включить 
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
 
}
