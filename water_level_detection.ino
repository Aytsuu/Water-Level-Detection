#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize pins
int waterSensorPin = A0;
int leds[5] = {13, 12, 11, 10, 9};


void setup() {
  Serial.begin(9600);
  // pinMode(ledPin, OUTPUT);
  
  for(int i=0; i < 5; i++){
    pinMode(leds[i], OUTPUT);
  };

  lcd.init();
  lcd.backlight();
}
void loop() {
  int value = analogRead(waterSensorPin);
  lcd.setCursor(0, 0);
  lcd.print("Value :");
  lcd.print(value);
  lcd.print("   ");
  Serial.println(value);
  lcd.setCursor(0, 1);
  lcd.print("W Level :");


  if (value == 0) {
    for(int i = 0; i < 5; i++) {
      digitalWrite(leds[i], LOW);
    };
    lcd.print("Empty ");
  } else if (value > 1 && value < 350) {
    lcd.print("LOW   ");
  } else if (value > 350 && value < 510) {
    for(int i = 0; i < 3; i++) {
      digitalWrite(leds[i], HIGH);
    };
    lcd.print("Medium");
  } else if (value > 510){
    for(int i=0; i < 5; i++) {
      digitalWrite(leds[i], HIGH);
    };
    lcd.print("HIGH  ");
  }
  
  delay(1000);
}