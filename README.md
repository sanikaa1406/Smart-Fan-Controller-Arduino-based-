Smart Fan Controller – Arduino Based
A temperature-controlled smart fan system using Arduino + DHT11 + LCD + Potentiometer + PWM Fan. n/
Features
1) Real-time temperature monitoring
2) Adjustable temperature threshold using potentiometer
3) Smooth PWM fan speed control
4) LCD display showing temperature, threshold & fan %

Components Used
Component	Quantity	Description
Arduino UNO	1	Main microcontroller
DHT11 Sensor	1	Temperature sensor
LCD 16x2 (I2C)	1	Display
Potentiometer	1	For setting threshold
DC Fan	1	Controlled using PWM
NPN Transistor / MOSFET	1	For driving fan
Jumper Wires & Breadboard	–	Wiring

How the System Works


1) DHT11 measures room temperature
2) Potentiometer sets threshold (20°C – 40°C)
3) Arduino compares temperature with threshold
4) Fan speed is automatically adjusted using PWM
5) LCD shows:
Temperature (°C)
Threshold
Fan Speed (%) 

HOW TO RUN PROJECT
1. Install Arduino IDE
2. Add DHT sensor library
3. Add LiquidCrystal_I2C library
4.Upload the code
5.Connect LCD, DHT11, Potentiometer & Fan
6.Turn knob to set threshold
7.Observe fan speed auto-adjust
