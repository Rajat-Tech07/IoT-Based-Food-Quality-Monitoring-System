IoT Based Food Quality Monitoring System
-- Overview
The IoT-Based Food Quality Monitoring System monitors critical environmental conditions such as temperature, humidity, and gas levels in real-time to prevent food spoilage during storage and transportation.
It uses sensors like MQ5 and DHT11 integrated with a NodeMCU (ESP8266) and uploads live data to ThingSpeak for cloud monitoring.
- Features
-- Real-time monitoring of temperature, humidity, and gas levels
  MQ5 gas detection for spoilage clues
  DHT11 for temperature & humidity
  LCD display for on-site monitoring
  ThingSpeak IoT cloud integration
  Spoilage alerts based on thresholds
  Low-cost & scalable IoT solution
-- Hardware Components
  NodeMCU ESP8266
  MQ5 Gas Sensor
  DHT11 Temperature & Humidity Sensor
  LCD Display (I2C)
  Connecting wires + power source
-- Software & Tools
  Arduino IDE
  Embedded C++
  ThingSpeak IoT Cloud
  Serial Monitor
-- Working Principle
  Sensors (DHT11, MQ5) collect environmental data
  NodeMCU reads & processes the values
  Data is shown locally on the LCD
  Data is uploaded to ThingSpeak for cloud monitoring
  Gas thresholds classify food as:
   Good
   Rotten
   Severely Rotten

Conclusion
This project provides a cost-effective, scalable, and accurate IoT solution for ensuring food quality during storage and transportation. It significantly reduces spoilage by enabling real-time monitoring and cloud insights.
