long duration = 0;
int cm = 0;
int inch = 0;
int buzzer = 2;
int distance_cm(byte trig_pin,byte dist_pin)
{
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin,LOW);
  int value = (pulseIn(dist_pin,HIGH)/2)/29.1+2;
  if (value>255) { value=255;}
  delay(20);
  return value;
}
void setup() {
  noTone(2);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(6, INPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT); //ลำโพง
}

void loop() 
{
  digitalWrite(4, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

  duration = pulseIn(6, HIGH);
  cm = duration*0.034/2;
  inch = duration*0.0133/2;
  Serial.print("CM : ");
  Serial.println(cm);

if (distance_cm(4,6) <= 15) {

  digitalWrite(3,HIGH);
  tone(buzzer,1000);

} 
  else{
    digitalWrite(3,LOW);
    noTone(2);
 
  }
  delay(150);
}
