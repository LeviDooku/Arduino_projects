#include <LiquidCrystal.h> //Library for using LCD screen

//Variables

int rs = 13;
int E = 11;
int D4 = 5, D5 = 4, D6 = 3, D7 = 2;
int sesion = 0;
int buzz_pin = 7;
int buzz_delay = 100;
const int sesiones = 5;
LiquidCrystal lcd(rs,E,D4,D5,D6,D7);

void setup() {
  
  lcd.begin(16,2);  //Size of LCD screen
  pinMode(buzz_pin, OUTPUT);

  
  //First message
  
  lcd.setCursor(4,0); //I set it like that because my screen is broken
  lcd.print("Pomodoro");
  lcd.setCursor(6,1);
  lcd.print("Counter");

  delay(3000);
  lcd.clear();

  for(int i = 0; i < sesiones; i++)
  {
    //Update variables every iteration 
    
    sesion++;
    int estudio = 25;
    int descanso = 5;
    int contador = 5;

    //Study session
    
    do{

      lcd.setCursor(4,0);
      lcd.print("Sesion: ");
      lcd.setCursor(12,0);
      lcd.print(sesion);
      lcd.setCursor(4,1);
      lcd.print("Minutes: ");
      lcd.print(estudio);
      estudio--;
      delay(600);

    }while(estudio != 0);

    lcd.clear();
    delay(500);

    //Buzzer loop
    
    do{
      delay(300);

      for(int i = 0; i < 1000; i++)
      {
        digitalWrite(buzz_pin, HIGH);
        delayMicroseconds(buzz_delay);
        digitalWrite(buzz_pin, LOW);
        delayMicroseconds(buzz_delay);
      }
        
      delay(300);

      for(int i = 0; i < 1000; i++)
      {
        digitalWrite(buzz_pin, HIGH);
        delayMicroseconds(buzz_delay);
        digitalWrite(buzz_pin, LOW);
        delayMicroseconds(buzz_delay);
      }
      
      contador--;

    //Rest session

    }while(contador != 0);

    do{

      lcd.setCursor(4,0);
      lcd.print("A descansar");
      lcd.setCursor(4,1);
      lcd.print("Minutes: ");
      lcd.print(descanso);
      descanso--;
      delay(60000);

    }while(descanso != 0);

    lcd.clear();
    delay(500);  
    
     //Buzzer loop 
    
    contador = 5;

    do{
      delay(300);

      for(int i = 0; i < 1000; i++)
      {
        digitalWrite(buzz_pin, HIGH);
        delayMicroseconds(buzz_delay);
        digitalWrite(buzz_pin, LOW);
        delayMicroseconds(buzz_delay);
      }
        
      delay(300);

      for(int i = 0; i < 1000; i++)
      {
        digitalWrite(buzz_pin, HIGH);
        delayMicroseconds(buzz_delay);
        digitalWrite(buzz_pin, LOW);
        delayMicroseconds(buzz_delay);
      }
      contador--;

    }while(contador != 0);  
  }

  delay(500);
  lcd.clear();

  //Final message

  lcd.setCursor(4,0);
  lcd.print("Sessions");
  lcd.setCursor(6,1);
  lcd.print("Finished! :)");

}

void loop() {}




