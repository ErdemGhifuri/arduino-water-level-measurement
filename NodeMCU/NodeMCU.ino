#include "ESP8266WiFi.h"
#include <SPI.h>
#include "functions/sendPayload.h"

// WiFi parameters to be configured
const char* ssid = "WIFI_SSID"; // Write here your router's username
const char* password = "WIFI_PASSWORD"; // Write here your router's password

void setup() {
  Serial.begin(9600);
  // Connect to WiFi
  Serial.print("Try to connect to WiFi \nSSID: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);
  WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // read data from Main Board
  String data = "";
  // while serial data is available, append to data variable
  while (Serial.available()) {
    data += char(Serial.read());
  };

  // print to check data value
  Serial.println(data);

  // if data is not empty string, send the data payload to designated API
  if (data != "") {
    // get data at the first line
    int positionOfNewLine = data.indexOf("\r\n");
    String cleanData = data;
    if (positionOfNewLine >= 0) {
        cleanData = data.substring(0, positionOfNewLine);
    };

    // send payload to Api
    sendPayloadToApi(cleanData);
  };
}
