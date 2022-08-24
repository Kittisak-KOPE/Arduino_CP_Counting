#

t01_countEntrance.ino

```
int input01 = 2;
int inputValue01 = 1;
int checkShowValue = 1;
boolean car;
int count;

void setup() {
  Serial.begin(9600);
  pinMode(input01, INPUT);
}

void loop() {
  inputValue01 = digitalRead(input01);  //Trig : 0
  if(inputValue01 != checkShowValue){
     checkShowValue = inputValue01;     //0
     if(checkShowValue == 0){
      count++;
      Serial.println(count);
     }
  }
}
```

## ENC28J60

Link : [https://create.arduino.cc/projecthub/Sourcery/how-to-connect-the-enc28j60-to-an-arduino-efd0dd]
Arduino IDE choose menubar Sketch --> Include Library --> Manage Libraries and search "EtherCard" and Install
