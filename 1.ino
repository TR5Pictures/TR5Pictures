int timecho = 1000;
unsigned long hientai = 0;
unsigned long thoigian;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int den = 8;


void setup() {
  Serial.begin(9600);
lcd.init();
lcd.backlight();
  pinMode(den, OUTPUT);
}

void loop() {
    digitalWrite(den, HIGH);
    delay(1000);
      digitalWrite(den, LOW);
    delay(1000);

  thoigian = millis();
  Serial.print("Time: ");
  Serial.println(thoigian);

  if (thoigian - hientai >= timecho) {
    hientai = millis();
    Serial.print("              ");
    Serial.print("Hiện tại: ");
    Serial.print(hientai);
    Serial.print("     ");

    if (digitalRead(den) == LOW)  //Nếu đèn đang OFF
    {
      digitalWrite(den, HIGH);
      Serial.println("Đèn ON");
    } else  // Ngược lại, nếu đèn đang ON
    {
      digitalWrite(den, LOW);
      Serial.println("Đèn OFF");
    }
  }

  
}
