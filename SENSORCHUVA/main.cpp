#include <Arduino.h>
#define chuvaAnalog A0 //Pino Analógico
#define chuvaDigital 16 //Pino digital
void setup() {
Serial.begin(9600);
pinMode(chuvaDigital,INPUT); //Pino como entrada
}
void loop(){
//Lendo a porta analógica
int chuvaAnalogVal = analogRead(chuvaAnalog);
//Lendo a porta digital
int chuvaDigitalVal = digitalRead(chuvaDigital);
Serial.print(chuvaAnalogVal);
Serial.print("\t");
Serial.println(chuvaDigitalVal);
millis(200);
}