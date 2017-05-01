float temperature = 0.0;

void setup () {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(3, HIGH);
}

void loop () {
  temperature = ((((analogRead(A0)/1024.0)*5.0) - 0.5)*100);
  Serial.println((int)(temperature));
  Serial.write((int)(temperature));
  delay(5000);
}

  
  

