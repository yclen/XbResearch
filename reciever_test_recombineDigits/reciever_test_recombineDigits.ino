#include <SoftwareSerial.h>

#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor2 = (4);
Servo myservo;
SoftwareSerial mySerial(16, 17); //these are pins A2 and A3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  myservo.attach(10);

}



int tenTo(int power){
  int result = 1;
  for(int i=0; i<power; i++){
    result = result * 10;
  }
  return result;
}

void control_motors(int a, int b){
  int m;
  if (a>505){
    m = map(a, 500, 999, 0, 255);
   
    motor2.run(FORWARD);
  }
  else if (a<490){
    m = map(a, 499, 0, 0, 255);
    
    motor2.run(BACKWARD);
  }
  else {
    m = 0;
  }
  
  

  motor2.setSpeed(m);

  myservo.write(map(b, 0, 999, 0, 180));
}


int a;
int b;
bool setA = true;
int digit;
int num = 0;
int i = 0;
char data;

void loop() {
 
  
if (mySerial.available()) {  // check if data is available on serial port
  
      data = mySerial.read(); // read the data from serial port
      digit = data - '0'; //convert char data into an integer
      // Serial.println(digit);
      

      num = num + digit*tenTo(i);
      

      i++;
      if(i>=3){
  
        
        if (setA){
          a = num;
          setA = false;
          // Serial.println(a);
        }
        else {
          b = num;
          setA = true;
        Serial.print("A equals: ");
        Serial.print(a);
        Serial.print(" | B equals: ");
        Serial.println(b);
        }
        i = 0;
        num = 0;
      }
      

      control_motors(b, a);
      
     }
  
   

  
  
  
}
