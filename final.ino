bool m1a=LOW;
bool m1b=LOW;
bool m2a=LOW;
bool m2b=LOW;
int val,ch1,ch4,ch3,valu,va;

void forward(){
   m1a=HIGH;
  m1b=LOW;
  m2a=HIGH;
  m2b=LOW;
  digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
   if(valu==5 || valu==4 || valu==3 || valu==2){
    digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
  }
}

void backward(){
  m1a=LOW;
  m1b=HIGH;
  m2a=LOW;
  m2b=HIGH;
   digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
   if(valu==5 || valu==6 || valu==7 || valu==8){
    digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
  }
}

void left(){
  m1a=LOW;
  m1b=HIGH;
  m2a=HIGH;
  m2b=LOW;
  digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
   if(va==5 || va==6 || va==7 || va==8){
    digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
  }
}

void right(){
  m1a=HIGH;
  m1b=LOW;
  m2a=LOW;
  m2b=HIGH;
  digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
   if(valu==5 || valu==4 || valu==3 || valu==2){
    digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);     //acceln
  pinMode(11,INPUT);    //forward-backward
  pinMode(2,INPUT);     //left-right
  pinMode(5,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);    //pwm
  pinMode(12,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  int ch3=pulseIn(7,HIGH);
  int val=map(ch3,993,2000,25,255);
  int ch2=pulseIn(11,HIGH);
  int valu=map(ch2,980,2000,1,10);
  int ch4=pulseIn(2,HIGH);
  int va=map(ch4,980,2000,1,10);
  
  analogWrite(9,val);
  
  if(va>=8){
    right();
  }
  else
  if(va<=2){
    left();
  }
  if(valu>5){
    forward();
  }
  else
  if(valu<5){
    backward();
  }
  
  Serial.print("channel 3: ");
  Serial.println(ch3);
  Serial.print(" channel 2: ");
  Serial.println(ch2);
  Serial.println("channel 4: ");
  Serial.println(ch4);
  }
