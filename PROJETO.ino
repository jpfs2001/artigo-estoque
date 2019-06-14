int distancia = 0;
int seg = 0;
int seg2 = 0;
int min = 0;
int horas = 0;
float valor = 10.00;
int t;


// ENERGIA //
const int pinoPOT = A5 ;
const int pinoLED = 2;
const int pinoLED2 = 3;
const int pinoLED3 = 4;
const int pinoLED4 = 5;

float lum = 0;
// ENERGIA //

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(pinoPOT, INPUT); 
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoLED2,OUTPUT);
  pinMode(pinoLED3, OUTPUT);
  pinMode(pinoLED4,OUTPUT); 
  pinMode(0,OUTPUT);
  
}

void loop()
{
lum = map(analogRead(pinoPOT), 0, 1023, 0, 255);
analogWrite(pinoLED, lum);
analogWrite(pinoLED2,lum);
analogWrite(pinoLED3, lum);
analogWrite(pinoLED4,lum);


  static unsigned long ult_tempo = 0;
  int tempo = millis();
  if((tempo - ult_tempo) >= 1000){
  ult_tempo = tempo;
  seg++; seg2++;
  }
  if(seg >= 60){
  seg =0;
  seg2 =0;
  min++; 
  };
  if ( min >= 60){
    min = 0;
    horas++;
  } // 1 MIN DO SISTEMA É IGUAL A 5:30 MIN E SEG REAL //
  
  distancia = 0.01723 * readUltrasonicDistance(13, 12);
  
  if ( seg == 3 && distancia <= 20){
    t = 1;
    valor = 9.00;
  }
   if ( seg == 4 && distancia <= 20){
    t = 1;
    valor = 9.00;
  }
   if ( seg == 5 && distancia <= 20){
    t = 1;
    valor = 9.00;
  }
  if (distancia <= 20 ) {
    Serial.print("SETOR 1 - ");
    Serial.print("5 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }
  
  if ( seg == 3 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 22){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 22){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 22){
    valor = 9.00;
  }
  if (distancia == 21 || distancia == 22 ) {
    Serial.print("SETOR 1 - 4 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }

  if ( seg == 3 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 23){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 23){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 23){
    valor = 9.00;
  }
  if (distancia == 24 || distancia == 23) {
    Serial.print("SETOR 1 - 3 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }

  if ( seg == 3 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 25){
    valor = 9.00;
  }

  if (distancia == 26 || distancia == 25 ) {
    Serial.print("SETOR 1 - 2 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
    }

  if ( seg == 3 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 27){
    valor = 9.00;
  }

  if (distancia == 28 || distancia == 27) {
    Serial.print("SETOR 1 - 1 Caixa Disponivel - ");
    Serial.print("  VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }
  if (distancia >= 29 ) {
    Serial.println("SETOR 1 - Necessita ser reposto");
    digitalWrite(4,HIGH);
    
  }
  
  distancia = 0.01723 * readUltrasonicDistance(7,6 );
  
  if ( seg == 3 && distancia <= 20){
    valor = 9.00;
  }
  if ( seg == 4 && distancia <= 20){
    valor = 9.00;
  }
  if ( seg == 5 && distancia <= 20){
    valor = 9.00;
  } 
  if (distancia <= 20 ) {
    Serial.print("SETOR 2 - 5 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;  
  }
  
  if ( seg == 3 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 22){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 22){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 22){
    valor = 9.00;
  }
  if (distancia == 21 || distancia == 22) {
    Serial.print("SETOR 2 - 4 Caixas Disponiveis - ");
    Serial.print("  VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.99;
  }
  
  if ( seg == 3 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 23){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 23){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 23){
    valor = 9.00;
  }
  if (distancia == 24 || distancia == 23) {
    Serial.print("SETOR 2 - 3 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }
  
  if ( seg == 3 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 25){
    valor = 9.00;
  }
  if (distancia == 26 || distancia == 25) {
    Serial.print("SETOR 2 - 2 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
    }
    
  if ( seg == 3 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 27){
    valor = 9.00;
  }
  if (distancia == 28 || distancia == 27 ) {
    Serial.print("SETOR 2 - 1 Caixa Disponivel - ");
    Serial.print("  VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }
  if (distancia >= 29) {
    Serial.println("SETOR 2 - Necessita ser reposto");
    digitalWrite(3,HIGH);
  }

  distancia = 0.01723 * readUltrasonicDistance(11,10 );
  if ( seg == 3 && distancia <= 20){
    valor = 9.00;
  }
  if ( seg == 4 && distancia <= 20){
    valor = 9.00;
  }
  if ( seg == 5 && distancia <= 20){
    valor = 9.00;
  }
  if (distancia <= 20) {
    Serial.print("SETOR 3 - 5 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }
  
  if ( seg == 3 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 22){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 22){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 22){
    valor = 9.00;
  }
  if (distancia == 22 || distancia == 21) {
    Serial.print("SETOR 3 - 4 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }

  if ( seg == 3 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 23){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 23){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 23){
    valor = 9.00;
  }
  if (distancia == 24  || distancia == 23) {
    Serial.print("SETOR 3 - 3 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }
  if ( seg == 3 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 25){
    valor = 9.00;
  }
  if (distancia == 26 || distancia == 25) {
    Serial.print("SETOR 3 - 2 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
    }
    
  if ( seg == 3 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 27){
    valor = 9.00;
  }
  if (distancia == 28 || distancia == 27) {
    Serial.print("SETOR 3 - 1 Caixa Disponivel - ");
    Serial.print("  VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
  }
  if (distancia >=29) {
    Serial.println("SETOR 3 - Necessita ser reposto");
    digitalWrite(5,HIGH);
  }

  distancia = 0.01723 * readUltrasonicDistance(9, 8);
  if ( seg == 3 && distancia <= 20){
    valor = 9.00;
  }
  if ( seg == 4 && distancia <= 20){
    valor = 9.00;
  }
  if ( seg == 5 && distancia <= 20){
    valor = 9.00;
  }
  if (distancia <= 20) {
    Serial.print("SETOR 4 - 5 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
    Serial.println("----------------------------------------------------------");
    Serial.println("----------------------------------------------------------");
    }
    
  if ( seg == 3 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 21){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 22){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 22){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 22){
    valor = 9.00;
  }
  if (distancia == 23 || distancia == 22 || distancia == 21) {
    Serial.print("SETOR 4 - 4 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
    Serial.println("----------------------------------------------------------");
    Serial.println("----------------------------------------------------------");
  }

  if ( seg == 3 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 25){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 24){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 24){
    valor = 9.00;
  }
  if (distancia == 25 || distancia == 24) {
    Serial.print("SETOR 4 - 3 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
    Serial.println("----------------------------------------------------------");
    Serial.println("----------------------------------------------------------");
  }

  if ( seg == 3 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 26){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 26){
    valor = 9.00;
  }
  if (distancia == 27 || distancia == 26) {
    Serial.print("SETOR 4 - 2 Caixas Disponiveis - ");
    Serial.print("VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
    Serial.println("----------------------------------------------------------");
    Serial.println("----------------------------------------------------------");
    }

  if ( seg == 3 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 27){
    valor = 9.00;
  }
  if ( seg == 3 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 4 && distancia == 28){
    valor = 9.00;
  }
  if ( seg == 5 && distancia == 28){
    valor = 9.00;
  }
  if (distancia == 27 || distancia == 28 ) {
    Serial.print("SETOR 4 - 1 Caixa Disponivel - ");
    Serial.print("  VALOR ");
    Serial.print(valor);
    Serial.println(" R$");
    valor=10.00;
    Serial.println("----------------------------------------------------------");
    Serial.println("----------------------------------------------------------");
  }
  
  if (distancia >=29) {
    Serial.println("SETOR 4 - Necessita ser reposto");
    digitalWrite(2,HIGH);
    Serial.println("----------------------------------------------------------");
    Serial.println("----------------------------------------------------------");

  }


 
delay(5000); // Delay a little bit to improve simulation performance
}
