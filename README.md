# ESP32 WebSocket Client with PlatformIO

[![PlatformIO](https://img.shields.io/badge/PlatformIO-Compatible-orange.svg)](https://platformio.org/)
[![ESP32](https://img.shields.io/badge/ESP32-Compatible-blue.svg)](https://www.espressif.com/en/products/socs/esp32)
[![Python](https://img.shields.io/badge/Python-3.7%2B-green.svg)](https://www.python.org/)

A simple WebSocket client implementation for ESP32 using PlatformIO that enables real-time bidirectional communication between your ESP32 device and a Python WebSocket server.

## Features

- Real-time WebSocket communication between ESP32 and Python server
- PlatformIO project structure
- Event-driven callbacks for connection status monitoring
- Simple message sending and receiving
- JSON-based server responses
- Easy configuration and deployment

## Table of Contents

- [Requirements](#requirements)
- [Quick Start](#quick-start)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [API Reference](#api-reference)
- [Contributing](#contributing)

## Requirements

### Hardware
- **ESP32 Development Board** (ESP32 DevKitC, NodeMCU-32S, or compatible)
- **USB Cable** (micro-USB or USB-C depending on your board)
- **Computer** with available USB port

### Software
- **Visual Studio Code** (recommended) or any text editor
- **PlatformIO IDE** extension for VS Code
- **Python 3.7+** for the WebSocket server
- **Git** (optional, for cloning the repository)

## Quick Start

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/esp32-websocket-client.git
   cd esp32-websocket-client
   ```

2. **Install dependencies**
   ```bash
   pip install websockets
   ```

3. **Configure WiFi credentials** in `src/main.cpp`

4. **Upload to ESP32** using PlatformIO

5. **Run the server**
   ```bash
   python server/server.py
   ```

## Installation

### Step 1: Install Development Environment

#### Option A: Visual Studio Code + PlatformIO (Recommended)

1. **Download and install [Visual Studio Code](https://code.visualstudio.com/)**

2. **Install PlatformIO IDE extension:**
   - Open VS Code
   - Go to Extensions (`Ctrl+Shift+X` / `Cmd+Shift+X`)
   - Search for "PlatformIO IDE"
   - Click "Install"
   - Restart VS Code when prompted

#### Option B: PlatformIO Core CLI

```bash
# Install PlatformIO Core
pip install platformio

# Verify installation
pio --version
```

### Step 2: Install Python Dependencies

```bash
# Verify Python installation
python --version

# Install WebSocket server dependencies
pip install websockets
```

### Step 3: Setup the Project

1. **Clone or download the project:**
   ```bash
   git clone https://github.com/your-username/esp32-websocket-client.git
   cd esp32-websocket-client
   ```

2. **Open in VS Code:**
   - Launch VS Code
   - File → Open Folder
   - Select the project directory

3. **Wait for PlatformIO to initialize:**
   - PlatformIO will automatically detect the project
   - Dependencies will be installed automatically
   - Check the PlatformIO terminal for completion

## Configuration

### WiFi Configuration

Edit `src/main.cpp` and update your network credentials:

```cpp
// WiFi Configuration
const char* ssid = "ESP32";
const char* password = "12345678";
```

### WebSocket Server Configuration

1. **Find your computer's IP address:**

   **Windows:**
   ```cmd
   ipconfig
   ```
   
   **macOS/Linux:**
   ```bash
   ifconfig
   # or
   ip addr show
   ```

2. **Update the server address in `src/main.cpp`:**
   ```cpp
   const char* websockets_server = "ws://192.168.0.102:8765";
   ```
   Replace `192.168.0.102` with your computer's IP address.

### Advanced Configuration

You can modify these settings in `src/main.cpp`:

```cpp
// Serial Configuration (currently set to 9600)
Serial.begin(9600);

// Message sending interval (currently 5 seconds)
if (millis() - lastMsg > 5000) {
  // Send message logic
}
```

## Usage

### 1. Upload Code to ESP32

#### Using VS Code + PlatformIO:
1. Connect ESP32 via USB
2. Click PlatformIO icon in sidebar
3. Project Tasks → esp32dev → General → Upload
4. Monitor progress in terminal

#### Using PlatformIO CLI:
```bash
# Build the project
pio run

# Upload to device
pio run -t upload

# Monitor serial output
pio device monitor -b 9600
```

### 2. Start the WebSocket Server

```bash
# Navigate to server directory
cd server

# Run the server
python server.py
```

Expected output:
```
WebSocket server started on ws://0.0.0.0:8765
Waiting for connections...
```

### 3. Monitor Communication

#### Serial Monitor (ESP32):
```bash
pio device monitor -b 9600
```

Expected ESP32 output:
```
Connecting to WiFi...
Connected to WiFi
IP address: 192.168.0.101
Connected to WebSocket server!
Connection Opened
Received: {"type":"status","message":"Connected to server"}
Sent: ESP32 time: 5000
Received: {"type":"echo","received":"ESP32 time: 5000","status":"OK"}
```

#### Server Console:
```
WebSocket server started on ws://0.0.0.0:8765
Client connected
Received: ESP32 time: 5000
```

## Project Structure

```
ESP32-WebSocket-Client/
├── src/
│   └── main.cpp                 # ESP32 WebSocket client code
├── server/
│   └── server.py                # Python WebSocket server
├── include/                     # (empty directory)
├── lib/                         # (empty directory)
├── test/                        # (empty directory)
├── platformio.ini               # PlatformIO configuration
├── .gitignore                   # Git ignore file
└── README.md                    # This file
```

## API Reference

### ESP32 Client Functions

The main code uses the ArduinoWebsockets library with these key components:

```cpp
// WebSocket client instance
WebsocketsClient client;

// Connection
bool connected = client.connect(websockets_server);

// Send message
client.send(message);

// Message callback
client.onMessage([&](WebsocketsMessage message) {
    // Handle received message
});

// Event callback
client.onEvent([&](WebsocketsEvent event, String data) {
    // Handle connection events
});

// Poll for messages
client.poll();
```

### WebSocket Events

| Event | Description |
|-------|-------------|
| `WebsocketsEvent::ConnectionOpened` | Successfully connected to server |
| `WebsocketsEvent::ConnectionClosed` | Disconnected from server |
| `WebsocketsEvent::GotPing` | Ping received from server |
| `WebsocketsEvent::GotPong` | Pong received from server |

### Server API

The Python server supports these message types:

```python
# Message format
{
    "type": "message_type",
    "data": "message_content",
    "timestamp": "2024-01-01T12:00:00Z"
}
```

## PlatformIO Commands

### Development Commands
```bash
# Build project
pio run

# Build and upload
pio run -t upload

# Clean build files
pio run -t clean

# Monitor serial output
pio device monitor

# List connected devices
pio device list

# Update platforms and libraries
pio update
```

### Library Management
```bash
# Install library
pio lib install "library_name"

# List installed libraries  
pio lib list

# Search for libraries
pio lib search "websocket"
```

## Troubleshooting

### Common Issues

#### ESP32 Won't Connect to WiFi
**Symptoms:** ESP32 continuously attempts WiFi connection
- Verify WiFi credentials in `src/main.cpp`
- Ensure WiFi network is 2.4GHz (ESP32 doesn't support 5GHz)
- Check ESP32 is within range of router
- Try different WiFi network for testing

#### WebSocket Connection Failed
**Symptoms:** WiFi connected but WebSocket connection fails
- Verify server IP address in client code
- Ensure WebSocket server is running
- Check firewall settings (allow port 8765)
- Confirm both devices are on same network
- Test server accessibility: `telnet YOUR_IP 8765`

#### Upload/Build Errors
**Symptoms:** PlatformIO compilation or upload errors
```bash
# Clean and rebuild
pio run -t clean
pio run

# Update PlatformIO
pio upgrade --dev

# Check device connection
pio device list
```

#### Serial Monitor Shows Nothing
**Symptoms:** No output in serial monitor
- Verify baud rate (9600 - as set in the code)
- Check USB cable and connection
- Try different USB port
- Press ESP32 reset button
- Verify correct COM port selection

#### Python Server Issues
**Symptoms:** Server won't start or crashes
```bash
# Check Python installation
python --version

# Verify dependencies
pip show websockets

# Test port availability
netstat -an | grep 8765

# Run the server
python server.py
```

### Performance Optimization

For better performance:
- Increase WiFi TX power: `WiFi.setTxPower(WIFI_POWER_19_5dBm)`
- Adjust message sending frequency (currently 5 seconds)
- Optimize message content size

## Contributing

We welcome contributions!

### Development Setup
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Submit a pull request
---

**Made with care for the ESP32 community**