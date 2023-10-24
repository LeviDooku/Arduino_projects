#include <LiquidCrystal.h>

//PINES PANTALLA
const int rs = 13;
const int E = 11;
const int D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(rs,E,D4,D5,D6,D7);

//PIN BUZZER
const int buzz_pin = 7;

//VARIABLES LÓGICA PROGRAMA
int sesion = 0;
int tEstudio;
int tDescanso;
int contador = 5; //Aquí seleccionamos número de sesiones

//FUNCIÓN PARA ACCIONAR BUZZER
void accionarBuzzer(const int nVeces){
  
	int contBuzz = nVeces;
  	const int delayT = 300;
    const int buzz_delay = 100;

    while (contBuzz > 0){
      for (int j = 0; j < 2; j++){
        for (int i = 0; i < 1000; i++){
          digitalWrite(buzz_pin, HIGH);
          delayMicroseconds(buzz_delay);
          digitalWrite(buzz_pin, LOW);
          delayMicroseconds(buzz_delay);
        }
        delay(300);
      }
      contBuzz--;
    }
}

//FUNCIÓN PARA LIMPIAR Y APLICAR DELAY
void limpiayDelay(const int delayTime){
	lcd.clear();
  	delay(delayTime);
}

//FUNCIÓN IMPRIMIR MENSAJES
void imprimeMensaje(String mensaje, int row, int col){
	lcd.setCursor(row, col);
  	lcd.print(mensaje);
}

void setup(){
  
  pinMode(buzz_pin, OUTPUT); //Configurar como d. salida buzzer
  lcd.begin(16,2);	//Inicializar pantalla
	
  //Imprimir título
  imprimeMensaje("Pomodoro Counter", 0, 0);
  delay(3000);
  lcd.clear();
  
}

void loop() {

    while(contador > 0){

      sesion++;
      tEstudio = 25;
      tDescanso = 5;
      
      //Do - while estudio
      
      do{
        imprimeMensaje("Sesion: "+String(sesion), 0, 0);
        //Evitar errores con un if - else
        if(tEstudio >= 10){
          imprimeMensaje("Minutos: "+String(tEstudio), 0, 1);
        }else{
          imprimeMensaje("Minutos: 0"+String(tEstudio), 0, 1);
        }      
        tEstudio--;
        delay(60000);
      }while(tEstudio != 0);


      limpiayDelay(500);
      accionarBuzzer(2);
	
      //Do - while descanso 
      do{
        imprimeMensaje("A descansar", 0, 0);
        imprimeMensaje("Minutos: "+String(tDescanso), 0, 1);
        tDescanso--;
        delay(60000);
      }while(tDescanso != 0);

      limpiayDelay(500);
      accionarBuzzer(2);
      contador--; //Decrementamos contador de sesiones
    }
  
	imprimeMensaje("Estudio finished", 0, 0); //Terminamos así el programa
}
