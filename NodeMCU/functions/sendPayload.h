//Web/Server address to read/write from
const int port = 443;  // HTTPS= 443 and HTTP = 80
const String host = "iotghifari.herokuapp.com";
const String path = "/post/data";
const String field = "Elevation"; // field name of the measured data
const char fingerprint[] PROGMEM = "0c39355a614b026a75c61c86438e6186078d64ae"; // Site SSL thumbprint

WiFiClientSecure client;

// function to create querystring
String setField(String payload) {
  return "?field=" + field + "&value=" + payload;
}

void sendPayloadToApi(String payload) {
  Serial.print("Connecting");
  // Necessary if the port use HTTPS
  client.setFingerprint(fingerprint);
  // try to connect to the host
  int r = 0; //retry counter
  while ((!client.connect(host, port)) && (r < 30)) {
    delay(100);
    Serial.print(".");
    r++;
  }

  Serial.println();

  if (r == 30) {
    Serial.println("Connection failed");
  }

  // if connected to the host, then create a GET request to send the data payload to API
  if (client.connected()) {
    Serial.println("Connected to server");
    Serial.println("GET " + path + setField(payload) + " HTTP/1.1");
    Serial.println("Host: " + host);
    // Make a HTTP request:
    client.println("GET " + path + setField(payload) + " HTTP/1.1");
    client.println("Host: " + host);
    client.println("Connection: close");
    client.println();
    Serial.println("Request sent");
  }

  // if the server send response, print the response
  if (client.connected()) {
    Serial.println("Content:");
    delay(2000);
    while (client.available()) {
      char c = client.read();
      Serial.print(c);
    }
    Serial.println();
    Serial.println("disconnecting from server.");
    // disconnect from the client
    client.stop();
  }
}
