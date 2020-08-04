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

void initPin()
{
  autoServo.attach(autoservoPin);
  humServo.attach(humservoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  autoServo.write(0);
  delay(100);
}

void setup()
{
  Serial.begin(9600);
  initPin();
  Serial.println("Smart-Bin")
}

void loop()
{
  humVal = readHum();
  disVal = readDisAvg();

  if (humVal > 50)
  {
    humServoOn();
  }
  if (humVal <= 50)
  {
    humServoOff();
  }
  if (disVal < 50)
  {
    autoServoOn();
  }
  if (disVal >= 50)
  {
    autoServoOff();
  }

  delay(5000);
}

int readHum()
{
  int humVals = analogRead(humPin);
  Serial.println("Nilai Kelembaban: " + String(humVals));
  return (1023 - humVals);
}

void readDis()
{
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

void readDisAvg()
{
  int disVals = 0;
  int totaldisVal = 0;
  for (int i = 0; i < 3; i++)
  {
    disVals = readDis();
    totaldisVal += disVals;
  }
  disVals = totaldisVal / 3;
  return (disVals);
}

void humServoOn()
{
  humServo.write(180);
  delay(1000);
  humServo.write(90);
}

void humServoOff()
{
  humServo.write(0);
  delay(1000);
  humServo.write(90);
}

void autoServoOn()
{
  autoServo.write(0);
  delay(3000);
  autoServo.write(180);
}

void autoServoOff()
{
  autoServo.write(0);
}