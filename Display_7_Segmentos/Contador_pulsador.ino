
//PINES BOTON
const int botonPin = 2;

//PINES DISPLAY
const int displayPins[] = {3, 4, 5, 6, 7, 8, 9, 10};

int buttonState = 0;
int lastButtonState = 0;

int contador = 0;

//Función que contiene la codificación del display

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

void setup() {
  	
  //Inicializar pines display
  
  for (int i = 0; i < 7; i++) {
    pinMode(displayPins[i], OUTPUT);
  }
  
  //Inicializar boton e imprimir primer valor display
  pinMode(botonPin, INPUT);
  actualizarDisplay();
}

void loop() {
  
buttonState = digitalRead(botonPin); //Leer estado del botón
  
  //Incrementar contados si se pulsa el botón
  if (buttonState != lastButtonState) 
  {
    if (buttonState == HIGH) {
 
      contador++;
      if (contador > 9) {
        contador = 0;
      }
      actualizarDisplay();
      delay(250);
    }
    lastButtonState = buttonState;
  }

}
