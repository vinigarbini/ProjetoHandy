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

// Pinos para a comunicacao serial do bluetooth (RX e TX)
SoftwareSerial Bluetooth(0,1);

// Variavel do caractere de paridade
byte Paridade;  

// Teste recebido
int teste;

void setup()
{
  // Ativa comunicacao serial a taxa de 9600 baud/s
  Serial.begin(9600);
  
  // Ativa a comunicacao do bluetooth a taxa de 38400 baud/s
  Bluetooth.begin(38400);
  
  // Setando os pinos dos servomotores
  Dedo1Servo.attach(5);  
  delay(100); //Delay para setagem de cada servo
  Dedo2Servo.attach(6);   
  delay(100);
  Dedo3Servo.attach(7);
  delay(100);
  Dedo4Servo.attach(8);
  delay(100);
  Dedo5Servo.attach(9);
  delay(100);
  
  pinMode(Bluetooth, INPUT);

}

void loop()
{ 
  //Serial.print("Teste is listening: ");
  //Serial.println(Bluetooth.isListening());
  
  //if (Bluetooth.available()) { // Se existem dados para leitura
   
    //Serial.println("Testando");
  //b1 = bluetooth.read(); //Variável para armazenar o dado atual
  //command += b1; //Variável para armazenar todos os dados
   
  //if (b1 == '\n'){ //Se o dado atual for um pulador de linha (\n)
    //Serial.print(command); //Printa o comando
    //command = ""; //Limpa o comando para futuras leituras
  //}
  //else{
  //  Serial.println("sem leitura");
  //}

  
  
  // teste sinal bluetooth recebido
  //teste = Bluetooth.read();
  //Serial.print("Sinal Recebido");
  //Serial.println(Bluetooth.read());  

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
      //if(Dedo1Ang!=255)
      Dedo1Servo.write(Dedo1Ang);
                                                    
      //if(Dedo2Ang!=255)
      Dedo2Servo.write(Dedo2Ang);

      //if(Dedo3Ang!=255)
      Dedo3Servo.write(Dedo3Ang);

     //if(Dedo4Ang!=255)
      Dedo4Servo.write(Dedo4Ang);

      //if(Dedo5Ang!=255)
      Dedo5Servo.write(Dedo5Ang);
    }
 }
  delay(100);
}            
