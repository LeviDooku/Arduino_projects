int contador = 0;
int botonPin = 2; // Cambia esto al número de tu pin de botón
int displayPins[] = {3, 4, 5, 6, 7, 8, 9, 10}; // Cambia estos pines a tus conexiones de display

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(displayPins[i], OUTPUT);
  }
  pinMode(botonPin, INPUT_PULLUP);
  actualizarDisplay();
}

void loop() {
  if (digitalRead(botonPin) == LOW) {
    contador++;
    if (contador > 9) {
      contador = 0;
    }
    actualizarDisplay();
    delay(250); // Para evitar rebotes en el botón
  }
}

void actualizarDisplay() {
  int numeros[10][7] = {
  //{a, b, c, d, e, f, g}
    {0, 0, 0, 0, 0, 0, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0}, // 2
    {0, 0, 0, 0, 1, 1, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0}, // 4
    {0, 1, 0, 0, 1, 0, 0}, // 5
    {1, 1, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 1, 1, 0, 0}, // 9
  };

  for (int i = 0; i < 7; i++) {
    digitalWrite(displayPins[i], numeros[contador][i]);
  }
}