

#include <Keypad.h>
#include <LiquidCrystal.h>


const int rs = A5, en = A4, d4 = A3, d5 = A2, d6 =A1, d7 = A0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte Rows= 4; //number of rows on the keypad i.e. 4
const byte Cols= 3; //number of columns on the keypad i,e, 3

int Dirc ;


char keymap[Rows][Cols]=
{
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};



byte rPins[Rows]= {3,2,7,0}; //Rows 0 to 3
byte cPins[Cols]= {6,5,4}; //Columns 0 to 2

Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

// Left Motor
int Inp1 = 13 ;
int Inp2 = 12 ;

// Right Motor 
int Inp3 = 11 ;
int Inp4 = 10 ;

void setup()
{ 
  pinMode(Inp1, OUTPUT);
  pinMode(Inp2, OUTPUT);
  pinMode(Inp3, OUTPUT);
  pinMode(Inp4, OUTPUT);
  
    lcd.begin(16, 2);
 
     lcd.print( "Welcome To");
     lcd.setCursor (0,1);
     lcd.print( "Turtle Bot");
     
  lcd.setCursor(0, 0);
     Serial.begin(9600);  // initializing serail monitor
     delay (3000);
}


void loop()
{   
     lcd.clear();
  
    Dirc=Dir(); 
       
     if (Dirc == 1)
     {  int x = 0 , y = 0 ;
     lcd.clear();
     lcd.print( "Enter the Number");
     lcd.setCursor (0,1);
     lcd.print( "of Cycles");
     while ( x==0 ){x = kpd.getKey();}
     x=x-48;
     lcd.clear();
     lcd.print(x);
     while ( y==0 ){y = kpd.getKey();}
     y=y-48;
     lcd.print(y);
     x=x*10+y;
    
     digitalWrite(Inp1, HIGH);
     digitalWrite(Inp2, LOW);
     digitalWrite(Inp3, HIGH);
     digitalWrite(Inp4, LOW);
          
          delay (933*x); // dc motor takes 0.933 seconds to complete one cycle 
          digitalWrite(Inp1, LOW);
          digitalWrite(Inp2, LOW);
          digitalWrite(Inp3, LOW);
          digitalWrite(Inp4, LOW);
          lcd.clear();
     }  

     else if (Dirc == 2)
     {  int x = 0 , y = 0 ;
     lcd.clear();
     lcd.print( "Enter the Number");
     lcd.setCursor (0,1);
     lcd.print( "of Cycles");
     while ( x==0 ){x = kpd.getKey();}
     x=x-48;
     lcd.clear();
     lcd.print(x);
     while ( y==0 ){y = kpd.getKey();}
     y=y-48;
     lcd.print(y);
     x=x*10+y;
    
     digitalWrite(Inp1, LOW);
     digitalWrite(Inp2, HIGH);
     digitalWrite(Inp3, LOW);
     digitalWrite(Inp4, HIGH);
          
          delay (933*x); // dc motor takes 0.933 seconds to complete one cycle 
          digitalWrite(Inp1, LOW);
          digitalWrite(Inp2, LOW);
          digitalWrite(Inp3, LOW);
          digitalWrite(Inp4, LOW);
          lcd.clear();
     }
     
     else if (Dirc == 3)
     {  
    
     digitalWrite(Inp1, HIGH);
     digitalWrite(Inp2, LOW);
     digitalWrite(Inp3, LOW);
     digitalWrite(Inp4, HIGH);
          
          delay (933); // dc motor takes 0.933 seconds to complete one cycle 
          digitalWrite(Inp1, LOW);
          digitalWrite(Inp2, LOW);
          digitalWrite(Inp3, LOW);
          digitalWrite(Inp4, LOW);
          lcd.clear();
     }
     
     else if (Dirc == 4)
     {  
    
     digitalWrite(Inp1, LOW);
     digitalWrite(Inp2, HIGH);
     digitalWrite(Inp3, HIGH);
     digitalWrite(Inp4, LOW);
          
          delay (933); // dc motor takes 0.933 seconds to complete one cycle 
          digitalWrite(Inp1, LOW);
          digitalWrite(Inp2, LOW);
          digitalWrite(Inp3, LOW);
          digitalWrite(Inp4, LOW);
          lcd.clear();
     }
}

int Dir (){
  int x = 0;
  char z = kpd.getKey();
     lcd.clear();
     lcd.print( "Choose Direction");
     delay (1000);
     lcd.clear();
     lcd.print( "FRW:2 BACKWARD:8 ");
     lcd.setCursor (0,1);
     lcd.print( "LEFT:4 RIGHT:6");
     while ( x == 0 ){
      z = kpd.getKey();
     if (z == '2'){
      lcd.clear();
      lcd.print("FORWARD");
      delay(1000);
            
      return 1; }
      
      else if (z == '8'){
      lcd.clear();
      lcd.print("BACKWARD");
      delay(1000);
            
      return 2; }

      
      else if (z == '6'){
      lcd.clear();
      lcd.print("RIGHT");
      delay(1000);
            
      return 3; }
  
      else if (z == '4'){
      lcd.clear();
      lcd.print("LEFT");
      delay(1000);
            
      return 4; }
  
      }
  }
  
  
  
