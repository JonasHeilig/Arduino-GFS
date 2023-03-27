int Schalter1 = 12; //Anpassen
int Schalter1zustand;
int LED1 = 13;

void setup(){
  Serial.begin(9600);
  pinMode(Schalter1,INPUT);
}

void loop(){
  Schalter1zustand = digitalRead(Schalter1);
  Serial.println(Schalter1zustand,DEC);
}