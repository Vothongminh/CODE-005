//https://www.youtube.com/c/VTMVlogVoThongMinh
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define sensor A1
#define led 13
#define motor 8
//.................................................
void setup() {
  Serial.begin(9600);
  lcd.init();
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("----VUON TU DONG----");
  lcd.setCursor(0, 1);
  lcd.print("Do am dat:    %");
}
//.................................................
void loop() {
  int value = analogRead(sensor);
  value = map(value, 0, 1023, 0, 100);
  lcd.setCursor(11, 1);
  lcd.print(value);
  if (value < 100) {
    lcd.setCursor(13, 1);
    lcd.print(' ');
  } else if (value < 10) {
    lcd.setCursor(12, 1);
    lcd.print(' ');
  }
  if (value > 70) {
    Serial.println("Do am binh thuong");
    lcd.setCursor(0, 2);
    lcd.print("    Do am dat ok    ");
    lcd.setCursor(0, 3);
    lcd.print("                   ");
    digitalWrite(led, LOW);
    digitalWrite(motor, LOW);
  }
  else {
    Serial.println("Dat kho thieu nuoc");
    lcd.setCursor(0, 2);
    lcd.print(" Dat kho thieu nuoc ");
    digitalWrite(led, HIGH);
    digitalWrite(motor, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("   MOTOR dang chay  ");
  }
}
