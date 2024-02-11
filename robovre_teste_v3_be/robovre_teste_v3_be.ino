#include "IRremote.h"
int led = 9;
const int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //começa a receber
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
   
    if (results.value == 0xFF30CF){
      Serial.println("Botao A Pressionado");
      digitalWrite(led,HIGH); 
    }
    
    if (results.value == 0xFF18E7){
      Serial.println("Botao B Pressionado");
      digitalWrite(led,LOW); 
       
    }
   
    irrecv.resume(); // Recebe o próximo valor
  }
}
