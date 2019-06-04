#define Trigger 2
#define Echo 3

int timetaken, dist;

int sendv;

void setup() {
  Serial.begin (9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
}

void loop() {
  timetaken=dist=0; //initialize the variable to zero before calculation

  //request the US to send a wave
  digitalWrite(Trigger, HIGH);
  digitalWrite(Trigger, LOW);
  
  timetaken = pulseIn(Echo, HIGH); //calculate the time taken for the wave to return
  dist = (timetaken/2) / 2.91; //formulae to calculate the distance using time taken
  
  if (dist <= 200 && dist > 0)//send the value to python only if it ranhes from 0-20 cm
   sendv = dist;

   Serial.println(sendv);
  
  delay(200);
  
}
