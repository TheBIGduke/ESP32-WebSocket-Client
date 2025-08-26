markdown

# ESP32 WebSocket Client with PlatformIO

A professional implementation of a WebSocket client for ESP32 using PlatformIO, which connects to a WebSocket server running on a computer.

## Features

- WebSocket communication between ESP32 and computer
- PlatformIO project structure for easy development
- Automatic reconnection handling
- Event callbacks for connection status
- Minimal memory footprint

## Hardware Requirements

- ESP32 development board
- USB cable for programming and power

## Software Requirements

- PlatformIO IDE or CLI
- Python 3.7+ (for the server)

## Getting Started

1. Clone this repository
2. Open the project in PlatformIO
3. Update the WiFi credentials in `src/main.cpp`
4. Update the WebSocket server IP address
5. Upload to your ESP32
6. Run the Python server on your computer

## Project Structure

esp32-websocket-client/
├── src/
│ └── main.cpp # ESP32 client code
├── server/
│ └── websocket_server.py # Python WebSocket server
├── include/ # Header files (if needed)
├── lib/ # Custom libraries (if needed)
├── test/ # Test files (if needed)
├── platformio.ini # PlatformIO configuration
└── README.md # This file
text


## PlatformIO Commands

```bash
# Build project
pio run

# Upload to device
pio run -t upload

# Monitor serial output
pio device monitor

# Clean build files
pio run -t clean

Server Setup

    Install required Python package:
    bash

pip install websockets

Run the server:
bash

    python server/websocket_server.py

Configuration

Update these values in src/main.cpp for your setup:

    ssid: Your WiFi network name

    password: Your WiFi password

    websockets_server: Your computer's IP address
ESP32 WebSocket Client with PlatformIO

A professional implementation of a WebSocket client for ESP32 using PlatformIO, which connects to a WebSocket server running on a computer.
Features

    WebSocket communication between ESP32 and computer

    PlatformIO project structure for easy development

    Automatic reconnection handling

    Event callbacks for connection status

    Minimal memory footprint

    Comprehensive documentation for easy replication

Table of Contents

    Hardware Requirements

    Software Requirements

    Installation Guide

    Project Setup

    Configuration

    Usage

    Troubleshooting

    License

Hardware Requirements

    ESP32 development board (e.g., ESP32 DevKitC, NodeMCU-32S)

    USB cable for programming and power

    Computer with available USB port

Software Requirements
For ESP32 Development:

    Visual Studio Code (recommended)

    PlatformIO IDE extension

    Alternatively, PlatformIO Core CLI

For WebSocket Server:

    Python 3.7 or higher

    websockets Python library

Installation Guide
Step 1: Install Visual Studio Code

    Download and install Visual Studio Code from https://code.visualstudio.com/

    Launch VS Code after installation

Step 2: Install PlatformIO Extension

    Open VS Code

    Go to the Extensions view (Ctrl+Shift+X or Cmd+Shift+X on Mac)

    Search for "PlatformIO IDE"

    Click "Install" on the PlatformIO IDE extension

    Wait for the installation to complete (this may take several minutes)

    Restart VS Code if prompted

Step 3: Install Python and WebSocket Server Dependencies

    Download and install Python from https://www.python.org/downloads/

        During installation, check "Add Python to PATH"

    Verify Python installation by opening a command prompt/terminal and typing:
    bash

python --version

Install the websockets library:
bash

    pip install websockets

Project Setup
Step 1: Clone or Download the Project

    Download the project files from GitHub

    Extract the files to a folder on your computer

Step 2: Open the Project in PlatformIO

    Open VS Code

    Click on "File" > "Open Folder"

    Navigate to the folder where you extracted the project files

    Select the folder and click "Open"

Step 3: Install Project Dependencies

    PlatformIO will automatically detect the project and install required dependencies

    Wait for the installation to complete (check the PlatformIO terminal at the bottom of VS Code)

    If automatic installation doesn't occur, open the PlatformIO Home (click on the PlatformIO icon in the left sidebar)

    Open the project and wait for dependencies to install

Configuration
Step 1: Configure WiFi Settings

    Open the src/main.cpp file

    Locate the following lines:
    cpp

    // WiFi credentials
    const char* ssid = "ESP32";
    const char* password = "12345678";

    Change these values to match your WiFi network credentials

Step 2: Configure WebSocket Server Address

    Find your computer's IP address:

        Windows: Open Command Prompt and type ipconfig

        Mac/Linux: Open Terminal and type ifconfig

    Look for your computer's IP address (usually something like 192.168.x.x)

    In src/main.cpp, update the WebSocket server address:
    cpp

    const char* websockets_server = "ws://YOUR_COMPUTER_IP:8765";

    Replace YOUR_COMPUTER_IP with your computer's actual IP address

Usage
Step 1: Upload Code to ESP32

    Connect your ESP32 to your computer via USB

    In VS Code, click on the "PlatformIO" icon in the left sidebar

    Expand "Project Tasks" > "esp32dev" > "General"

    Click "Upload" to compile and upload the code to your ESP32

    Wait for the upload to complete (you'll see a success message)

Step 2: Run the WebSocket Server

    Open a command prompt or terminal

    Navigate to the project folder

    Navigate to the server directory:
    bash

cd server

Run the Python server:
bash

    python websocket_server.py

    You should see the message: "WebSocket server started on ws://0.0.0.0:8765"

Step 3: Monitor Serial Output

    In VS Code, open the PlatformIO terminal (click on the PlatformIO icon in the status bar)

    Click "Monitor" to open the serial monitor

    You should see output indicating the ESP32 is connecting to WiFi and the WebSocket server

    Once connected, you'll see messages being sent and received every 5 seconds

Troubleshooting
Common Issues and Solutions

    PlatformIO not detecting board

        Check USB cable connection

        Install correct USB drivers for your ESP32

        Try specifying upload port in platformio.ini by uncommenting and setting upload_port

    Build errors

        Run pio run -t clean to clean build files

        Check all libraries are installed correctly

        Ensure you have the latest version of PlatformIO

    ESP32 can't connect to WiFi

        Verify WiFi credentials in src/main.cpp

        Check ESP32 is in range of the router

        Ensure your WiFi network is 2.4GHz (ESP32 doesn't support 5GHz)

    ESP32 can't connect to WebSocket server

        Verify server IP address in client code

        Ensure server is running before connecting ESP32

        Check firewall settings on computer (allow connections on port 8765)

        Ensure both devices are on the same network

    No output in Serial Monitor

        Verify baud rate is set to 9600

        Check USB cable connection

        Try resetting the ESP32

        Ensure the correct port is selected in PlatformIO Monitor

    Python server not working

        Verify Python is installed correctly

        Check websockets library is installed: pip show websockets

        Ensure no other application is using port 8765

    PlatformIO Useful Commands
    bash

    # List connected devices
    pio device list

    # Update PlatformIO core
    pio upgrade

    # List installed platforms
    pio platform list

    # List installed libraries
    pio lib list

Getting Additional Help

If you're still having issues:

    Check the PlatformIO documentation

    Search for similar issues on Stack Overflow

    Check the ESP32 forum

    Create an issue in this repository's GitHub issue tracker