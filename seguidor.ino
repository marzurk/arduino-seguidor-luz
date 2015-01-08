//Tenemos que incluir la biblioteca Servo.h
#include <Servo.h>

//Declaramos las variables a usar

//------------------------------------------------------------//
//Variables a emplear para la lectura de las fotoresistencias
const int pinSensor = A0;
int valorAnalogico = 0;
const int pinSensor2 = A1;
int valorAnalogico2 = 0;

//------------------------------------------------------------//
//Variables a emplear en el control del servomotor, iniciandolo en 90°
Servo miServo;
int servoPosicion = 90;

//El método de configuración que ademas inicia una comunicación serial
//para leer los valores de las fotoresitencias en la terminal de arduino
void setup(){
  pinMode(pinSensor, INPUT);
  Serial.begin(9600);
  miServo.attach(3);
  miServo.write(servoPosicion);
}


void loop(){

//leemos los valores de las fotoresistencias con el método analogRead(numeroPin)
  valorAnalogico = analogRead(pinSensor);
  valorAnalogico2 = analogRead(pinSensor2);
  int diferencia = valorAnalogico2 - valorAnalogico;
  
  //De acuerdo a la diferencia entre las fotoresitencias movemos el servo hacia un lado u otro
 Serial.println(diferencia);
  if(diferencia > 50){
    servoPosicion -=20;
  }
  if(diferencia > 100){
    servoPosicion -= 40;
  }
  if(diferencia < -50){
    servoPosicion += 20;
  }
  if(diferencia < -100){
    servoPosicion += 40;
  }
  if(servoPosicion > 189){
    servoPosicion = 189;
  }
  if(servoPosicion < 2){
    servoPosicion = 0;
  }
  miServo.write(servoPosicion);
  delay(500);
}
