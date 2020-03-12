int irpin = D1;
int pirpin = D2;
int smokepin = D3;
int ledpin = D4;
int buzzerpin = D5;

void setup() {
  Serial.begin(9600);
  pinMode(irpin,INPUT);
  pinMode(pirpin,INPUT);
  pinMode(smokepin,INPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(buzzerpin,OUTPUT);

}

void loop() {
  int ir = digitalRead(irpin);
  int pir = digitalRead(pirpin);
  int smoke = digitalRead(smokepin);
    if (ir == HIGH)
    {
      digitalWrite(ledpin, LOW);
      Serial.println("Garage close");
        if( pir == HIGH)
        {
          digitalWrite(buzzerpin, LOW);
          Serial.println("No intruder");
        }
       else if (pir == LOW)
        {
          digitalWrite(buzzerpin, HIGH);
          Serial.println("Intruder alert!!!");
        }
        if (smoke == HIGH) 
          {
            digitalWrite(buzzerpin, LOW);
          }
        else if (smoke == LOW)
        {
          digitalWrite(buzzerpin, HIIGH);
          Serial.println("FIRE!!!");
        }
    }
     else
     {
      digitalWrite(ledpin, HIGH);
      Serial.println("Garage open");
          if (smoke == HIGH) 
          {
            digitalWrite(buzzerpin, LOW);
          }
          else 
        {
          digitalWrite(buzzerpin, HIIGH);
          Serial.println("FIRE!!!");
        }

      
     }
}
