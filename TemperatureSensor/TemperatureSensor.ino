#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float temperature = 0.0;

void setup () 
{
  pinMode(3, OUTPUT);
  pinMode(31, OUTPUT);
  /*
  pinMode(33, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(51, OUTPUT);
  */
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(3, HIGH);
  digitalWrite(31, HIGH);
  /*
  digitalWrite(33, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(37, HIGH);
  digitalWrite(39, HIGH);
  digitalWrite(41, HIGH);
  digitalWrite(43, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(51, HIGH);
  */
  digitalWrite(4, LOW);
  
  lcd.begin(16, 2);
  lcd.print("Hello!");
}

void loop () 
{

  temperature = ((((analogRead(A0)/1024.0)*5.0) - 0.5)*100);
  Serial.println((int)(temperature));
  Serial.write((int)(temperature));
  delay(1000);
}

  
  

