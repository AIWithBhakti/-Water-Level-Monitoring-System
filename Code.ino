#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
const int trigPin = 9;
const int echoPin = 10;
const int greenLED = 3;
const int yellowLED = 4;
const int redLED = 5;
const int buzzer = 6;

const int tankHeight = 100; // Height of the tank in cm

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Pin Modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Water Level:");
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  long distance = duration * 0.034 / 2;

  // Calculate water level
  long waterLevel = tankHeight - distance;

  // Display water level on LCD
  lcd.setCursor(0, 1);
  if (waterLevel > 0 && waterLevel <= tankHeight) {
    lcd.print("Level: ");
    lcd.print(waterLevel);
    lcd.print(" cm   "); // Padding for overwriting old values
  } else if (waterLevel <= 0) {
    lcd.print("Level: Empty   ");
  } else {
    lcd.print("Out of Range   ");
  }

  // LED and buzzer control
  if (waterLevel < 30) { // Low water level
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000); // Buzzer alert
  } else if (waterLevel >= 30 && waterLevel <= 70) { // Medium water level
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
  } else if (waterLevel > 70) { // High water level
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    tone(buzzer, 500); // Buzzer alert for full tank
  }

  // Debugging via Serial Monitor
  Serial.print("Water Level: ");
  Serial.print(waterLevel);
  Serial.println(" cm");

  // Delay for stability
  delay(500);
}