#include <Mouse.h>
#define ledPin LED_BUILTIN
//const int ledPin = 13;
int mouseSensitivity = 12; 

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Mouse.begin();
  randomSeed(analogRead(0));
}

void loop() {
  
  int x = random(100);
  int y = random(100);
  int wheel = 0;
  int t = random(10);
  Serial.println(t, DEC);
//  Serial.print(" ");
  
  delay(3000);
//  Serial.println(HIGH);
  digitalWrite(ledPin, 1);
  int count = 0;
  while(count < t){
    Serial.print(x);
    Serial.print(" ");
    Serial.println(y);
    x=-x;
    y=-y;
    Mouse.move(x, y, wheel);
    count++;
    delay(1000);
  }
  Serial.println(LOW);
  digitalWrite(ledPin, LOW);
  
}
