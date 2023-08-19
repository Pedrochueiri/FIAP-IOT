const int analogPin = A0;   
const int ledPin = 3;      

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(analogPin);  
  int delayTime = map(sensorValue, 0, 1023, 1000, 100);  
  
  digitalWrite(ledPin, HIGH); 
  delay(delayTime);           
  digitalWrite(ledPin, LOW);  
  delay(delayTime);            
  
}
