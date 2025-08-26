"""
WebSocket Server for ESP32 Client

This Python script creates a WebSocket server that listens for connections
from ESP32 clients, echoes received messages, and sends acknowledgments.
"""


import asyncio		# For asynchronous programming
import websockets	# WebSocket implementation for Python
import json		# For JSON data serialization/deserialization

async def handle_client(websocket, path):
    print("Client connected")
    
    try:
        # Send welcome message using JSON format for structured data exchange
        await websocket.send(json.dumps({
        	"type": "status",
        	"message": "Connected to server"
        }))
        
        # Handle incoming messages from this client
        async for message in websocket:
            print(f"Received: {message}")
            
            # Echo back with acknowledgment
            response = {
            "type": "echo",
            "received": message,
            "status": "OK"
            }
            #Serialize the response to JSON and send it back to the client
            await websocket.send(json.dumps(response))
            
    except websockets.exceptions.ConnectionClosed:
        print("Client disconnected")


# Create a WebSocket server instance
# - listen on all available network interfaces (0.0.0.0)
# - use port 8765 for communication
start_server = websockets.serve(handle_client, "0.0.0.0", 8765)

asyncio.get_event_loop().run_until_complete(start_server)
print("WebSocket server started on ws://0.0.0.0:8765")
asyncio.get_event_loop().run_forever()
