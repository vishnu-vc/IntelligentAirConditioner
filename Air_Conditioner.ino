#include <NewPing.h>

#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 100
int distance = 0;
int temp =0;
int LED = 13; // conect Led to arduino pin 13
int pinTemp = A5;

NewPing sonar(trig_pin, echo_pin, maximum_distance);

void setup(){
  Serial.begin (9600);
  pinMode (LED, OUTPUT); // Led pin OUTPUT
}

void loop() {
  
  temp = readTemp();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("C");
  delay(500);
  distance = readPing();
  Serial.println(distance);
  if (distance<100 && temp<=35){
    
    digitalWrite(LED, LOW); // LED LOW
    delay(1000);
    
  }
  
  else
  {
    digitalWrite(LED, HIGH); // LED High
    delay(1000);
  }
  
  
}

int readTemp(){
  int temp = analogRead(pinTemp);    //Read the analog pin
  temp = temp * 0.48828125;
  return temp;
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=100;
  }
  return cm;
}
