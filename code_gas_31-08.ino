void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}
void loop() {
  int gasvalue = analogRead(4);
  Serial.print("Valor do sensor de gás: ");
  Serial.print(gasvalue);
  if(gasvalue<=700){
    digitalWrite(2, HIGH);
    Serial.println("Perigo! Vazamento de gás detectado!");
  }
  else{
    digitalWrite(2, LOW);
    Serial.println(" Seguro para o meio ambiente");
  }
  delay(2000); 
}

