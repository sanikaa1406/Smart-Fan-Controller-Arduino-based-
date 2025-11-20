#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// PIN & SENSOR SETTINGS
#define DHTPIN 2
#define DHTTYPE DHT11
#define FAN_PIN 3          // PWM-capable pin for fan control
#define POT_PIN A0

DHT dht(DHTPIN, DHTTYPE);

// LCD: Address = 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// INITIAL SETUP
void setup() {
  Serial.begin(9600);

  dht.begin();
  pinMode(FAN_PIN, OUTPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Fan Control");
  lcd.setCursor(0, 1);
  lcd.print("System Starting...");
  delay(2000);
  lcd.clear();
}

// MAIN LOOP
void loop() {

  // Read temperature
  float temperature = dht.readTemperature();

  // Check if sensor gives error
  if (isnan(temperature)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.setCursor(0, 1);
    lcd.print("Check DHT11");
    delay(1500);
    return;
  }

  // Map potentiometer to set temperature threshold
  int threshold = map(analogRead(POT_PIN), 0, 1023, 20, 40);

  // Fan speed calculation (PWM)
  int fanSpeed = 0;

  if (temperature > threshold) {
    fanSpeed = map(temperature, threshold, threshold + 10, 150, 255);
    fanSpeed = constrain(fanSpeed, 150, 255);
  } else {
    fanSpeed = 0;
  }

  analogWrite(FAN_PIN, fanSpeed);

  // LCD DISPLAY
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Thr:");
  lcd.print(threshold);
  lcd.print("C  F:");
  lcd.print(map(fanSpeed, 0, 255, 0, 100));
  lcd.print("%");

  delay(800);
}
