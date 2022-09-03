#include <Servo.h>
#include <IRremote.h>  //including infrared remote header file 

int RECV_PIN = 8; // the pin where you connect the output pin of IR sensor 

IRrecv irrecv(RECV_PIN); 

decode_results results; 


int servo1 = 2;
int servo2 = 3;
int servo3 = 4;
int servo4 = 5;
int servo5 = 6;
int servo6 = 7;

Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;

void setup() {
Serial.begin(9600);
irrecv.enableIRIn(); 
s1.attach(servo1);
s2.attach(servo2);
s3.attach(servo3);
s4.attach(servo4);
s5.attach(servo5);
s6.attach(servo6);
}

void loop() {
  if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready. 

 { 

 int   keycode = results.value;// Results of decoding are stored in result.value 

  Serial.println(" "); 

  Serial.print("Code: "); 

  Serial.println(results.value); //prints the value a a button press 

  Serial.println(" "); 

  irrecv.resume(); // Restart the ISR state machine and Receive the next value 

}
/*
delay(500);
s1.write(90);
delay(500);
s2.write(90);
delay(500);
s3.write(90);
delay(500);
s4.write(90);
delay(500);
s5.write(90);
delay(500);
s6.write(90);   
delay(500);
s1.write(45);
delay(500);
s2.write(45);
delay(500);
s3.write(45);
delay(500);
s4.write(45);
delay(500);
s5.write(45);
delay(500);
s6.write(45 );
delay(500);*/
} 
