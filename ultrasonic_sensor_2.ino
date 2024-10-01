#define trigPin 2
#define echoPin 4
#define led1 12
#define led2 11
#define led3 10
#define led4 9
#define led5 8
#define led6 7
#define buzzer 3

int sound = 250;

void setup() {

 Serial.begin (9600);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop() {

 long duration, distance;

 digitalWrite(trigPin, LOW); 

 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);

 delayMicroseconds(10);

 digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);

 distance = (duration/2) / 29.1; // covert to distance as cm

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);

  if (distance >= 14) {

  digitalWrite(led6, HIGH);
  sound = 0;

}

 else if (distance > 11) {

    digitalWrite(led5, HIGH);
   sound = 300;
}

 else if (distance > 9) {

  digitalWrite(led4, HIGH);
  sound = 0;
}

 else if (distance > 5) {

  digitalWrite(led3, HIGH);
  sound = 0;
}

  
 else if (distance > 3) {

      digitalWrite(led2, HIGH);
      sound = 0;
} 

 else if (distance >0 ) {

      digitalWrite(led1, HIGH);
      sound = 0;
}


 if ( distance > 14 || distance <= 0 ){

      Serial.println("Out of range");

      noTone(buzzer);

 }

 else {

     Serial.print(distance);

     Serial.println(" cm");

     tone(buzzer, sound);

}

 delay(500);

}
