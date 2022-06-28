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

// Variavel do caractere de paridade
byte Paridade;  

// Variaveis da posicao do servo motor (Entre 0 e 180)
int Dedo1Ang = 0;
int Dedo2Ang = 0;
int Dedo3Ang = 0;
int Dedo4Ang = 0;
int Dedo5Ang = 0;

// Pinos para a comunicacao serial do bluetooth (RX e TX)
SoftwareSerial Bluetooth(0,1);

void setup()
{
  // Ativa a comunicacao serial a taxa de 9600 baud/s
  Bluetooth.begin(9600);
  
  // Setando os pinos dos servomotores
  Dedo1Servo.attach(2);  
  delay(100); //Delay para setagem de cada servo
  Dedo2Servo.attach(3);   
  delay(100);
  Dedo3Servo.attach(4);
  delay(100);
  Dedo4Servo.attach(5);
  delay(100);
  Dedo5Servo.attach(6);
  delay(100);

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
    
    if(Paridade == 'A'){   // Verificando a paridade
    
      // Recebimento do sinal dos sensores via bluetooth, entre 0 e 180
      if(Dedo1Ang!=255)
      Dedo1Servo.write(Dedo1Ang);
                                                    
      if(Dedo2Ang!=255)
      Dedo2Servo.write(Dedo2Ang);

      if(Dedo3Ang!=255)
      Dedo3Servo.write(Dedo3Ang);

      if(Dedo4Ang!=255)
      Dedo4Servo.write(Dedo4Ang);

      if(Dedo5Ang!=255)
      Dedo5Servo.write(Dedo5Ang);
    
    }
  }
  delay(100);
}            