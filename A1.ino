void setup(){
    pinMode(8,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(12,OUTPUT);
   
    Serial.begin(9600);
}
void loop(){
    int t=100;

    digitalWrite(8,HIGH);
    delay(t);
    digitalWrite(8,LOW);
    
     digitalWrite(10,HIGH);
    delay(t);
    digitalWrite(10,LOW);

     digitalWrite(12,HIGH);
    delay(t);
    digitalWrite(12,LOW);

     digitalWrite(12,HIGH);
    delay(t);
    digitalWrite(12,LOW);
    
     digitalWrite(10,HIGH);
    delay(t);
    digitalWrite(10,LOW);

     digitalWrite(8,HIGH);
    delay(t);
    digitalWrite(8,LOW);


    
    }           