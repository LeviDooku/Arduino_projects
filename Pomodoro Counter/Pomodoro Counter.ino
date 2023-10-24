#include <LiquidCrystal.h>

const int rs = 13;
const int E = 11;
const int D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(rs,E,D4,D5,D6,D7);

const int buzz_pin = 7;

int sesion = 0;
int tEstudio = 25;
int tDescanso = 5;
int cont = 5;

void accionarBuzzer(const int nVeces){
  
	int contBuzz = nVeces;
  	const int delayT = 300;
    const int buzz_delay = 100;

    while (contBuzz > 0){
      for (int j = 0; j < 2; j++){ // Repite el patrón dos veces
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

void limpiayDelay(const int delayTime){
	lcd.clear();
  	delay(delayTime);
}

void setup(){
  
  pinMode(buzz_pin, OUTPUT);
  lcd.begin(16,2);

  lcd.home();
  lcd.print("Pomodoro Counter");

  delay(3000);
  lcd.clear();
}

void loop() {

    while(cont > 0){

      sesion++;
      
      do{

        lcd.home();
        lcd.print("Sesion: ");
        lcd.setCursor(11,0);
        lcd.print(sesion);
        lcd.setCursor(0,1);
        lcd.print("Minutes: ");
        lcd.setCursor(10, 1);

        if(tEstudio >= 10){
          lcd.print(tEstudio);
        }
        else{
          lcd.print("0"+String(tEstudio));
        }      

        tEstudio--;
        delay(60);

      }while(tEstudio != 0);

      limpiayDelay(500);
      accionarBuzzer(3);

      do{

        lcd.home();
        lcd.print("A descansar");
        lcd.setCursor(0,1);
        lcd.print("Minutes: ");
        lcd.print(tDescanso);
        tDescanso--;
        delay(60);

      }while(tDescanso != 0);

      limpiayDelay(500);
      accionarBuzzer(3);
      cont--;
    }
  
    lcd.home();
    lcd.print("Estudio");
    lcd.setCursor(0,1);
    lcd.print("Terminado! :)");
}




