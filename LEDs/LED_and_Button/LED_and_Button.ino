int ledPin = 13;
int buttonPin = 2;

int buttonState = 0;
int lastButtonState = 0;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) 
  {
    if (buttonState == HIGH) 
    {
      digitalWrite(ledPin, !digitalRead(ledPin));
    }
    lastButtonState = buttonState;
  }

}
