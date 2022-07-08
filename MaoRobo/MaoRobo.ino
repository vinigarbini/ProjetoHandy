// Programa: Mao Robo
// Arduino: Mega
// Modulo Bluetooth: HC-05
// Servo Motores: SG90
#include <SoftwareSerial.h>
#include <Servo.h>

// Variaveis dos Servo Motores
Servo Dedo1Servo;
Servo Dedo2Servo;
Servo Dedo3Servo;
Servo Dedo4Servo;
Servo Dedo5Servo;

// Variaveis da posicao do servo motor (Entre 0 e 180)
int Dedo1Ang = 0;
int Dedo2Ang = 0;
int Dedo3Ang = 0;
int Dedo4Ang = 0;
int Dedo5Ang = 0;

// Pinos para a comunicacao serial do bluetooth (TX e RX)
SoftwareSerial Bluetooth(3, 2);

// Caractere de paridade
byte Paridade;

void setup()
{
  // Ativa comunicacao serial a taxa de 9600 baud/s
  Serial.begin(9600);
  
  // Ativa a comunicacao do bluetooth a taxa de 38400 baud/s
  Bluetooth.begin(38400);
  
  // Setando os pinos dos servomotores
  Dedo1Servo.attach(4);  
  delay(100); //Delay para setagem de cada servo
  Dedo2Servo.attach(5);   
  delay(100);
  Dedo3Servo.attach(6);
  delay(100);
  Dedo4Servo.attach(7);
  delay(100);
  Dedo5Servo.attach(8);
  delay(100);
  
  pinMode(Bluetooth, INPUT);

}

void loop()
{ 
  // Recebimento dos dados via bluetooth
  if(Bluetooth.available()) {
    Paridade = Bluetooth.read();
    Dedo1Ang = Bluetooth.read();    
    Dedo2Ang = Bluetooth.read();
    Dedo3Ang = Bluetooth.read();    
    Dedo4Ang = Bluetooth.read();    
    Dedo5Ang = Bluetooth.read();       
  }
   
  if(Paridade == 'A'){   // Verificando a paridade
      
      // Acionamento dos motores, baseado nos dados recebidos via bluetooth
      Dedo1Servo.write(Dedo1Ang);
      Dedo2Servo.write(Dedo2Ang);
      Dedo3Servo.write(Dedo3Ang);
      Dedo4Servo.write(Dedo4Ang);
      Dedo5Servo.write(Dedo5Ang);
  }
  delay(100);
}            
