void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

int intPow(int base, int exponent) {
  int result = 1;

  for (int i = 0; i < exponent; i++) {
    result *= base;
  }
  return result;
}

void printDigits(int num){
  int digit, mod, div;

  for(int i=0; i<3; i++){
    mod = intPow(10, (i+1));
    div = intPow(10, i);
    digit = num%mod / div;
    Serial.print(digit);
    delay(10);
    
    
  }
  


}
int aPrev = 0;
int bPrev = 0;

void loop() {
  // put your main code here, to run repeatedly:
  // int a = 321;
  // int b = 789;

  int a = analogRead(A0);
  int b = analogRead(A1);

  if (a>999){
    a = 999;
  }
  if (b>999){
    b = 999;
  }

  if (a == aPrev && b == bPrev){

  }
  else{
  // Serial.print("/");
  printDigits(a);
  // Serial.print("/");
  printDigits(b);
  }
  delay(50);
  aPrev = a;
  bPrev = b;
  // Serial.println("");
  

  // Serial.print(" A equals: ");
  // Serial.print(a);
  // Serial.print(" | B equals: ");
  // Serial.println(b);
  // delay(500);


}
