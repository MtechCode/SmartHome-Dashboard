# SmartHome-Dashboard

SmartHome-Dashboard is a real-time monitoring system for a smart home, allowing users to track temperature and humidity data and control devices. It uses an ESP32, Flask for the backend, and Chart.js for data visualization.

## Features
- Real-time temperature and humidity data tracking
- Responsive web dashboard with live charts
- Easily extensible for other sensors or controls

## Technologies
- **ESP32** for sensor data
- **Flask** for backend data handling
- **Chart.js** for live data visualization on the web interface


## Setup Instructions
Hardware Setup: Connect a DHT11 sensor to ESP32.
Configure WiFi: Update main.ino with your WiFi credentials.


## Backend Setup:
Install dependencies: pip install -r requirements.txt
Run the server: python app.py
Frontend: Open index.html in a browser to view the dashboard.
