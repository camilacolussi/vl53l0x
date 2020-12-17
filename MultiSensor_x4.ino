//VL53L0x Multi sensor 
//Camila Colussi 2020
//Arduino Uno + 4 VL53L0x sensors
//Use SerialMonitor to see the measurements

// reference: https://arduinoproyek.wordpress.com/2019/03/27/vl53l0x-multi-sensor/

#include <Wire.h>

#include <VL53L0X.h>

VL53L0X sensor1;
VL53L0X sensor2;
VL53L0X sensor3;
VL53L0X sensor4;

int a;
int b;
int c;
int d;

void setup()

{

pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);

digitalWrite(7, LOW);
digitalWrite(6, LOW);
digitalWrite(5, LOW);
digitalWrite(4, LOW);

delay(500);

Wire.begin();
Serial.begin (9600);


//sensor1
digitalWrite(7, HIGH);
delay(150);
sensor1.init(true);
delay(100);
sensor1.setAddress((uint8_t)01);

//sensor2
digitalWrite(6, HIGH);
delay(150);
sensor2.init(true);
delay(100);
sensor2.setAddress((uint8_t)02);

//sensor3
digitalWrite(5, HIGH);
delay(150);
sensor3.init(true);
delay(100);
sensor3.setAddress((uint8_t)03);

//sensor4
digitalWrite(4, HIGH);
delay(150);
sensor4.init(true);
delay(100);
sensor4.setAddress((uint8_t)04);

//continuous
sensor1.startContinuous();
sensor2.startContinuous();
sensor3.startContinuous();
sensor4.startContinuous();

}


void loop()

{

a = sensor1.readRangeContinuousMillimeters();
b = sensor2.readRangeContinuousMillimeters();
c = sensor3.readRangeContinuousMillimeters();
d = sensor4.readRangeContinuousMillimeters();

Serial.println(" ");

Serial.print(a);

Serial.print(" ");

Serial.print(b);

Serial.print(" ");

Serial.print(c);

Serial.print(" ");

Serial.print(d);


delay(500);

}
