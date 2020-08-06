#include <Servo.h>

Servo autoServo;
Servo humServo;

int humPin = A0;
int echoPin = 4;
int trigPin = 5;
int autoservoPin = 7;
int humservoPin = 9;
int led = 10;

int humVal = 0;
int disVal = 0;

bool onStatus = false;

void initPin() {
  autoServo.attach(autoservoPin);
  humServo.attach(humservoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  autoServo.write(0);
  humServo.write(90);
  delay(100);
}

void setup() {
  Serial.begin(9600);
  initPin();
  Serial.println("Smart-Bin");
}

void loop() {
  disVal = readDisAvg();
  if (disVal < 50) {
    autoServoOn();
    onStatus = true;
  }

  if (onStatus) {
    humVal = readHum();
    if (humVal > 50) {
      humServoRight();
    } else {
      humServoLeft();
    }
    onStatus = false;
  }

  Serial.println("Menunggu....");
  delay(5000);
}

int readHum() {
  int humVals = analogRead(humPin);
  humVals = 1023 - humVals;
  Serial.println("Nilai Kelembaban: " + String(humVals));
  return humVals;
}

int readDis() {
  int duration;
  int distance;

  digitalWrite(10, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  return (distance);
}

int readDisAvg() {
  int disVals = 0;
  int totaldisVal = 0;
  for (int i = 0; i < 3; i++) {
    disVals = readDis();
    totaldisVal += disVals;
  }
  disVals = totaldisVal / 3;
  Serial.println("Nilai Ultrasonic: " + String(disVals));
  return (disVals);
}

void humServoRight() {
  Serial.println("Servo Hum ON");
  humServo.write(180);
  delay(1000);
  humServo.write(90);
}

void humServoLeft() {
  Serial.println("Servo Hum OFF");
  humServo.write(0);
  delay(1000);
  humServo.write(90);
}

void autoServoOn() {
  Serial.println("Servo Auto ON");
  autoServo.write(0);
  delay(3000);
  humServo.write(180);
}

void autoServoOff() {
  Serial.println("Servo Auto OFF");
  autoServo.write(180);
  delay(1000);
}