# -Water-Level-Monitoring-System
Water Level Monitoring System
This project implements a water level monitoring system using Arduino, ultrasonic sensors, LEDs, a buzzer, and an LCD display. The system measures the water level in a tank and provides visual and audio alerts based on predefined thresholds.

# How It Works
The ultrasonic sensor measures the distance to the water surface.
Water level is calculated by subtracting the measured distance from the total tank height.
The LCD displays the current water level.
LEDs and a buzzer provide alerts:
Red LED + Buzzer: Low water level (< 30 cm)
Yellow LED: Medium water level (30 - 70 cm)
Green LED + Buzzer: High water level (> 70 cm)

#Notes
Adjust the ultrasonic sensor for accurate distance measurement.
Modify the tank height and thresholds as needed.
Ensure the buzzer and LEDs are positioned clearly for easy alerts.
