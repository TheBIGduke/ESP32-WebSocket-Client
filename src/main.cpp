/**
 * ESP32 WebSocket Client
 * 
 * A basic WebSocket implementation for ESP32 that connects
 * to a WebSocket server running on a local computer.
 * 
 * Features:
 * - WebSocket communication
 * - Automatic reconnection logic
 * - Event callbacks
 * 
 * @author Kaléin Tamaríz - TheBIGduke
 * @version 1.0.0
 *
 */

#include <Arduino.h>            // Arduino core functions for PlatformIO
#include <WiFi.h>               // ESP32 WiFi functionality
#include <ArduinoWebsockets.h>  // WEbSocket client library (verified)

using namespace websockets;

// ============= CONFIGURATION SECTION =============
// Update these values for your specific setup

// WiFi credentials
const char* ssid = "ESP32";
const char* password = "12345678";

// WebSocket server (replace with your computer's IP)
const char* websockets_server = "ws://192.168.0.102:8765"; 

WebsocketsClient client;



void setup() {
  Serial.begin(9600);
  
  // Connect to WiFi network
  WiFi.begin(ssid, password);


  // Verify connection and return state
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());


  // Connect to WebSocket server
  bool connected = client.connect(websockets_server);

  // Verify connection to server and return state
  if (connected) {
    Serial.println("Connected to WebSocket server!");
    client.send("Hello from ESP32");
  } else {
    Serial.println("Failed to connect!");
    return;
  }


  // Set up callback functions for incoming messages
  client.onMessage([&](WebsocketsMessage message) {
    Serial.print("Received: ");
    Serial.println(message.data());
  });

  client.onEvent([&](WebsocketsEvent event, String data) {
    if (event == WebsocketsEvent::ConnectionOpened) {
      Serial.println("Connection Opened");
    } else if (event == WebsocketsEvent::ConnectionClosed) {
      Serial.println("Connection Closed");
    } else if (event == WebsocketsEvent::GotPing) {
      Serial.println("Got a Ping!");
    } else if (event == WebsocketsEvent::GotPong) {
      Serial.println("Got a Pong!");
    }
  });
}

void loop() {
  if (client.available()) {
    client.poll();
  }
  
  // Send a message every 5 seconds
  static unsigned long lastMsg = 0;
  if (millis() - lastMsg > 5000) {
    lastMsg = millis();
    String message = "ESP32 time: " + String(millis());
    client.send(message);
    Serial.println("Sent: " + message);
  }
  
  delay(10); // Prevent watchdog triggers
}