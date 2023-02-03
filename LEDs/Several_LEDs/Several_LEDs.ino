int LedPin_1 = 13;
int LedPin_2 = 12;


void setup() {  //Parte del programa que se repetirá una vez

pinMode(LedPin_1, OUTPUT);
pinMode(LedPin_2, OUTPUT);

}

void loop() {   //Parte del programa que se repetirá en bucle

digitalWrite(LedPin_1, HIGH);
digitalWrite(LedPin_2, HIGH);

}
