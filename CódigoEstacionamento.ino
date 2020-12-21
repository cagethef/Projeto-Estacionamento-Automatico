#include <Servo.h> // Biblioteca do servo

Servo gate; // objeto servo
int sensorportao = 3; // sensor do portao
int vaga1 = 4; // sensor vaga 1
int portao_R = 9; // LED rgb vermelho 
int portao_G = 10; // LED rgb verde
int portao_B = 11; // LED rgb azul
int vaga1_led = 12;; // LED vaga 1
int vaga2_led = 13;; // LED vaga 2

void setup() {
  // Definindo os pinos de acordo com as definições das variaveis
  gate.attach(6); // Conectando o servo no pino 6
  pinMode(sensorportao, INPUT);
  pinMode(vaga1, INPUT);
  pinMode(portao_R, OUTPUT);
  pinMode(portao_G, OUTPUT);
  pinMode(portao_B, OUTPUT);
  pinMode(vaga1_led, OUTPUT);
  pinMode(vaga2_led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  while(digitalRead(sensorportao)) // Sem nenhum carro no sensor
  {
  gate.write(75); // Mantem portao fechado ou fecha cancela
  digitalWrite(vaga1_led, LOW); // LED  VAGA 1 APAGADO
  digitalWrite(vaga2_led, LOW); // LED  VAGA 2 APAGADO
  CorRGB(0, 255, 0); // LED DO PORTAO FICA VERDE
  delay(300); // Espera 300ms
  digitalWrite(portao_R, LOW); // Apaga LED R 
  digitalWrite(portao_G, LOW); // Apaga LED G
  digitalWrite(portao_B, LOW); // Apaga LED B
  delay(300); // espera 300ms
  CorRGB(0, 255, 0); // LED DO PORTAO FICA VERDE
  delay(300); // Espera 300ms
  digitalWrite(portao_R, LOW); // Apaga LED R
  digitalWrite(portao_G, LOW); // Apaga LED G
  digitalWrite(portao_B, LOW); // Apaga LED B
  }
  
  if(!(digitalRead(sensorportao)) && (digitalRead(vaga1))) // Quando o carro se aproximar do portão e se a vaga 1 e a vaga 2 estiverem vazias
  {
  digitalWrite(vaga1_led, HIGH); // LIGAR LED DA VAGA 1
  digitalWrite(vaga2_led, HIGH); // LIGAR LED DA VAGA 2
  delay(1000); // Espera 1seg
  CorRGB(0, 255, 0); // LED DO PORTAO FICA VERDE
  gate.write(200); // Abre a cancela
  }
  
  if(!(digitalRead(sensorportao)) && !(digitalRead(vaga1))) // Quando o carro se aproximar do portão e se tiver carro na vaga 1 e a vaga 2 estiver vazia
  {
  digitalWrite(vaga1_led, LOW); // LED VAGA 1 APAGADO
  digitalWrite(vaga2_led, HIGH); // LED VAGA 2 LIGADO
  delay(1000); // Espera 1seg
  CorRGB(255, 255, 0); // LED DO PORTAO FICA AMARELO
  gate.write(200); // Abre a cancela
  }
  
  
  if(!(digitalRead(sensorportao)) && !(digitalRead(vaga1))) // Quando o carro se aproximar do portão e se nao tiver nenhuma vaga disponivel
  {
  digitalWrite(vaga1_led, LOW); // LED VAGA 1 APAGADO
  digitalWrite(vaga2_led, LOW); // LED VAGA 2 APAGADO
  delay(1000); // Espera 1seg
  CorRGB(255, 0, 0); // LED DO PORTAO FICA VERMELHO
  delay(300); // Espera 300ms
  digitalWrite(portao_R, LOW); // Apaga LED R
  digitalWrite(portao_G, LOW); // Apaga LED G
  digitalWrite(portao_B, LOW); // Apaga LED B
  delay(300); // Espera 300ms
  CorRGB(255, 0, 0); // LED DO PORTAO FICA VERMELHO
  delay(300); // Espera 300ms
  digitalWrite(portao_R, LOW); // Apaga LED R
  digitalWrite(portao_G, LOW); // Apaga LED G
  digitalWrite(portao_B, LOW); // Apaga LED B
  }
}

void CorRGB(int vermelho, int verde, int azul) // funcao para o led RGB
{
  vermelho = 255 - vermelho;
  verde = 255 - verde;
  azul = 255 - azul;
  analogWrite(portao_R, vermelho); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'vermelho'
  analogWrite(portao_G, verde); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'verde'
  analogWrite(portao_B, azul); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'azul'
}
