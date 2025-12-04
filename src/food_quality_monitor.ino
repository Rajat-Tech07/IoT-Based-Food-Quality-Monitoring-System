#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#define Gas_Pin A0
#define DHTPIN D4 

const char *myWriteAPIKey = "Your_Thingspeak_API_Key"; // Replace with your Thingspeak API Key
unsigned long myChannelNumber = Your_channel ID; // Replace with your channel ID
const char *ssid = "Your_SSID";  // Replace with your WiFi Name
const char *password = "Your_PASSWORD"; // Replace with your Password
DHT dht(DHTPIN, DHT11);
WiFiClient client;
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() 
{
Serial.begin(9600);
dht.begin();
lcd.init();
lcd.backlight();
ThingSpeak.begin(client);
WiFi.begin(ssid, password);
Serial.println();
Serial.println("Connecting to WiFi");
lcd.setCursor(0, 0);
lcd.print("Connecting WiFi");
while (WiFi.status() != WL_CONNECTED) 
{
delay(200);
Serial.print(".");
}
Serial.println("\nWiFi connected");
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("WiFi Connected");
}
int readGasValue()
{
int sensorValue = analogRead(Gas_Pin); 
return sensorValue;
}
void loop() 
{
float t = dht.readTemperature();
float h = dht.readHumidity();
int gas = readGasValue();
if (isnan(t) || isnan(h) || isnan(gas)) 
{
Serial.println("Failed to read from sensors!");
lcd.setCursor(0, 0);
lcd.print("Sensor Error");
return;
}
Serial.print("Temp: ");
Serial.print(t);
Serial.println(" C");
Serial.print("Humidity: ");
Serial.print(h);
Serial.println(" %");
Serial.print("Gas Value: ");
Serial.println(gas);

String status;
if (gas < 70) 
{
status = "Good";
} else if (gas > 70 && gas <= 100) 
{
status = "Rotten";
} else {
status = "Severely Rotten";
}
Serial.print("Food Status: ");
Serial.println(status);

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Temp:");
lcd.print(t);
lcd.print("C");
lcd.setCursor(0, 1);
lcd.print("Humidity:");
lcd.print(h);
lcd.print("%");
delay(3000); 
  
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Gas:");
lcd.print(gas);
lcd.setCursor(0, 1);
lcd.print("Status:");
lcd.print(status);
delay(3000); 
ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
ThingSpeak.writeField(myChannelNumber, 3, gas, myWriteAPIKey);
delay(2000);
}
