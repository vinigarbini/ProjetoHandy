// Programa: Mao Luva
// Arduino: Uno
// Modulo Bluetooth: HC-05
#include <SoftwareSerial.h>

// Pinos da Variaveis dos sensores de cada dedo
int Dedo1Sensor = A0;
int Dedo2Sensor = A2;
int Dedo3Sensor = A3;
int Dedo4Sensor = A4;
int Dedo5Sensor = A5;

// Valores de referencia do sensor, com os dedos dobrados ao maximo
int Dedo1Fechado = 25;
int Dedo2Fechado = 19;
int Dedo3Fechado = 9;
int Dedo4Fechado = 10;
int Dedo5Fechado = 9;

// Valores de referencia do sensor, com os dedos esticados
int Dedo1Aberto = 62;
int Dedo2Aberto = 114;
int Dedo3Aberto = 53;
int Dedo4Aberto = 38;
int Dedo5Aberto = 44;

// Variaveis a serem enviadas via comunicaco bluetooth
int Dedo1;
int Dedo2;
int Dedo3;
int Dedo4;
int Dedo5;

// Pinos para a comunicacao serial do bluetooth (RX e TX)
SoftwareSerial Bluetooth(0,1);

void setup()
{
  // Ativa a comunicacao serial a taxa de 9600 baud/s
  Bluetooth.begin(9600);
  
  // Setando as variaveis dos sensores dos dedos como entrada dos pinos
  pinMode(Dedo1Sensor, INPUT);   
  pinMode(Dedo2Sensor, INPUT);
  pinMode(Dedo3Sensor, INPUT);
  pinMode(Dedo4Sensor, INPUT);
  pinMode(Dedo5Sensor, INPUT);

}

void loop()
{
  // Leitura dos Sensores
  Dedo1 = analogRead(Dedo1Sensor);
  Dedo2 = analogRead(Dedo2Sensor);  
  Dedo3 = analogRead(Dedo3Sensor);
  Dedo4 = analogRead(Dedo4Sensor);
  Dedo5 = analogRead(Dedo5Sensor);  
  
  // Recalibracao dos dedos abertos
  if(Dedo1 > Dedo1Aberto)   
    Dedo1Aberto = Dedo1;
  if(Dedo2 > Dedo2Aberto)   
    Dedo2Aberto = Dedo2;
  if(Dedo3 > Dedo3Aberto)   
    Dedo3Aberto = Dedo3;
  if(Dedo4 > Dedo4Aberto)   
    Dedo4Aberto = Dedo4;
  if(Dedo5 > Dedo5Aberto)   
    Dedo5Aberto = Dedo5;

  // Recalibracao dos dedos fechados
  if(Dedo1 < Dedo1Fechado)   
    Dedo1Fechado = Dedo1;
  if(Dedo2 < Dedo2Fechado)   
    Dedo2Fechado = Dedo2;
  if(Dedo3 < Dedo3Fechado)   
    Dedo3Fechado = Dedo3;
  if(Dedo4 < Dedo4Fechado)   
    Dedo4Fechado = Dedo4;
  if(Dedo5 < Dedo5Fechado)   
    Dedo5Fechado = Dedo5;
  
  // Redimensionamento dos valores do sensor para saida analogica, dentro do intervalo de 0 a 180 graus
  Dedo1 = map(Dedo1, Dedo1Fechado, Dedo1Aberto, 0, 180);  
  Dedo2 = map(Dedo2, Dedo2Fechado, Dedo2Aberto, 0, 180);
  Dedo3 = map(Dedo3, Dedo3Fechado, Dedo3Aberto, 0, 180);
  Dedo4 = map(Dedo4, Dedo4Fechado, Dedo4Aberto, 0, 180);  
  Dedo5 = map(Dedo5, Dedo5Fechado, Dedo5Aberto, 0, 180);
  
  // Transmissao dos valores via comunicacao serial do bluetooth (TX)
  Bluetooth.write("A");      // Caractere para inicio de paridade
  Bluetooth.write(Dedo1);    
  Bluetooth.write(Dedo2);
  Bluetooth.write(Dedo3);
  Bluetooth.write(Dedo4);
  Bluetooth.write(Dedo5);
  
  delay(100);
}