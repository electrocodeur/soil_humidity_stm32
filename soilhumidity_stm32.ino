#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int soil;

void setup() {
  lcd.begin();
  lcd.backlight();
  pinMode(soil, INPUT);
}

void loop() {
  int soil = analogRead(PA0);
  int valeur = map(soil, 0, 4096, 0, 100);
  lcd.setCursor(0, 0);
  lcd.print("Moisture Value:");
  lcd.setCursor(0, 1);
  lcd.print(valeur);
  lcd.print(" %");
  delay(500);
  lcd.clear();
}
