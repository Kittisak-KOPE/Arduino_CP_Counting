#include <ArduinoMqttClient.h>
#include <Ethernet.h>

EthernetClient ethClient;
MqttClient mqttClient(ethClient);

int sensor1 = 2;
int sensor2 = 3;
int inputValue1 = 1;
int inputValue2 = 1;
int checkShowValue1 = 1;
int checkShowValue2 = 1;
int count = 20;
const long interval = 8000;
unsigned long previousMillis = 0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 100, 100);
IPAddress myDns(192, 168, 100, 1);

void setup() {
  pinMode(sensor1, INPUT);

  Serial.begin(9600);
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1);
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    Ethernet.begin(mac, ip, myDns);
  } else {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  delay(1000);

  if (!mqttClient.connect("broker.hivemq.com", 1883)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());
    while (1);
  }
  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
}

void loop() {
  mqttClient.poll();
  //  unsigned long currentMillis = millis();
  inputValue1 = digitalRead(sensor1);
  inputValue2 = digitalRead(sensor2);

  mqttClient.beginMessage("real_unique_topic");

  if (inputValue1 != checkShowValue1) {
    checkShowValue1 = inputValue1;
    if (checkShowValue1 == 0) {
      count--;
      mqttClient.print(Ethernet.localIP());
      mqttClient.print(", Sensor1");
      Serial.print("Sensor1");
    }
  }

  if (inputValue2 != checkShowValue2) {
    checkShowValue2 = inputValue2;
    if (checkShowValue2 == 0) {
      count++;
      mqttClient.print(Ethernet.localIP());
      mqttClient.print(", Sensor2");
      Serial.print("Sensor2");
    }
  }
  mqttClient.endMessage();
  delay(500);
}
