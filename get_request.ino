#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

 //const char* ssid = "ansaramman";
//const char* password = "123456789";

 const char* ssid = "lalargagar";
const char* password = "lalar12345";

//const char* ssid = "TP-LINK_710580";
//const char* password = "ansar94140";

 
void setup () {
 
Serial.begin(115200);
WiFi.begin(ssid, password);
   pinMode(LED_BUILTIN, OUTPUT);
    while (WiFi.status() != WL_CONNECTED) {
           
          delay(1000);
          Serial.print("Connecting..");
          Serial.println();
           
          }
 
}
 
void loop() {
 
      if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
       
      HTTPClient http;  //Declare an object of class HTTPClient
       
      http.begin("http://autodevice.ir/test/21");  //Specify request destination
      int httpCode = http.GET();                                                                  //Send the request
       
          if (httpCode > 0) { //Check the returning code
       
              String payload = http.getString();   //Get the request response payload
                 Serial.println(payload);              

              if(payload=="ok"){
                
                digitalWrite(LED_BUILTIN, LOW);
                
                }else{
                  digitalWrite(LED_BUILTIN, HIGH);
                  }
            }
       
          http.end();   //Close connection
       
          }
 
delay(1000);    //Send a request every 3 seconds
 
}
