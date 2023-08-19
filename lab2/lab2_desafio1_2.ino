const int buttonPin = 2;   // Pino do botão
const int ledPin = 13;
int lastButtonState = HIGH; // Último estado do botão
int buttonState;            // Estado atual do botão
unsigned long lastDebounceTime = 0;  // Último tempo de debounce
unsigned long debounceDelay = 50;    // Tempo de debounce de 50ms

int ledState = LOW; 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int leBotao = digitalRead(buttonPin);

  if (leBotao != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    Serial.println(ledState);
    if (leBotao != buttonState) {
      buttonState = leBotao;

      if (buttonState == LOW) {
        Serial.println("PEGUEI O ESQUEMA");
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      } else {
        Serial.println("PEGUEI a PORRA DO ESQUEMA");
        digitalWrite(ledPin, ledState);
      }
    }
  }

  lastButtonState = leBotao;
}
