int sensor1 = 2;
int sensor2 = 3;
int inputValue1 = 1;
int inputValue2 = 1;
int checkShowValue1 = 1;
int checkShowValue2 = 1;
int count = 20;
bool p = 1;

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
}

//S/N 0or1
void loop() {
  inputValue1 = digitalRead(sensor1);
  inputValue2 = digitalRead(sensor2);

  if (inputValue1 != checkShowValue1) {
    checkShowValue1 = inputValue1;
    if (checkShowValue1 == 0) {
      count--;
//      Serial.println(count);
      Serial.print("Sensor1 : ");
      Serial.println(1);
    }
  }

  if (inputValue2 != checkShowValue2) {
    checkShowValue2 = inputValue2;
    if (checkShowValue2 == 0) {
      count++;
//      Serial.println(count);
      Serial.print("Sensor2 : ");
      Serial.println(1);
    }
  }

}
