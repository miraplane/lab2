const int buzzerPin = 6;
const int echoPin = 8;
const int trigPin = 9;

const int minTone = 31;
const int duration = 500;

void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  
  tone(buzzerPin, minTone, duration);
}

void loop() {
  float distance = readDistance();
  delay(1000);

  int frequency = round(distance) + minTone;
  tone(buzzerPin, frequency, duration);
}

float readDistance()
{
  const float speedOfSoundMPerSec = 340.0;
  const float speedOfSoundCmPerUs = speedOfSoundMPerSec / 10000.0;
  return readPulse() * speedOfSoundCmPerUs / 2.0;    
}

float readPulse()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  return duration;
}
