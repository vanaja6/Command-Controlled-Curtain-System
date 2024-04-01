const int switch1 = 6;
const int switch2 = 7;
const int led = 13;
#define op1 9  // motor 1 - pin 1
#define op2 10 // motor 1 - pin 2
String input; 
void setup(){
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(op1, OUTPUT);
  pinMode(op2, OUTPUT);
  Serial.begin(9600);
}
void loop(){
 input = Serial.readString();
 int switch1_state = 0 ;
 int switch2_state = 0 ;
 switch1_state = digitalRead(switch1);
 switch2_state = digitalRead(switch2);
  Serial.print("switch1_state = "); 
  Serial.println(switch1_state);
  Serial.print("switch2_state = ");
  Serial.println(switch2_state);
  //closing.................. 
if(input.indexOf("close")>=0){
  Serial.println("closing.................");
  if(switch1_state == HIGH && switch2_state == LOW){
      Serial.println("2");
      while(switch1_state == HIGH && switch2_state == LOW){
        Serial.println("3");
        digitalWrite(led, HIGH);
        digitalWrite(op1, HIGH);
        digitalWrite(op2, LOW);
       // b1_state = digitalRead(b1);
        switch2_state = digitalRead(switch2);
        if(switch2_state == HIGH){
         Serial.println("4");
         break;
        }
      }
    }
    else
      Serial.println("Curtain is Already closed"); 
  }
//opening...................
  if(input.indexOf("open")>=0){
    Serial.println("opening.................");
    if(switch1_state == LOW && switch2_state == HIGH){ 
      while(switch1_state == LOW && switch2_state == HIGH){
        //Serial.println("4");
        digitalWrite(led, HIGH);
        digitalWrite(op1, LOW);
        digitalWrite(op2, HIGH);
        switch1_state = digitalRead(switch1);
        //b2_state = digitalRead(b2);
        if(switch1_state == HIGH){
          Serial.println("5");
          break;
        }
      }
     }
     else
     Serial.println("Curtain is Already open");
  }
  digitalWrite(led, LOW);
  digitalWrite(op1, LOW);
  digitalWrite(op2, LOW);
}