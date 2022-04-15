const int rLedPin = 13;
const int bLedPin = 12;
const int gLedPin = 11;
char incomingByte = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(rLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  Serial.begin(115200);
}

int ledColor(const char c) {
  switch(c){
      case 'r':
        digitalWrite(rLedPin, HIGH);
        digitalWrite(bLedPin, LOW);
        digitalWrite(gLedPin, LOW);
        break;
        
      case 'b':
        digitalWrite(rLedPin, LOW);
        digitalWrite(bLedPin, HIGH);
        digitalWrite(gLedPin, LOW);
        break;
        
      case 'g':
        digitalWrite(rLedPin, LOW);
        digitalWrite(bLedPin, LOW);
        digitalWrite(gLedPin, HIGH);
        break;
        
      case '0':
        digitalWrite(rLedPin, LOW);
        digitalWrite(bLedPin, LOW);
        digitalWrite(gLedPin, LOW);
        break;
      default:
        return 1;
   }
   return 0;
}

void ledLoop() {
  for(int i = 0; i < 3; i++){
    switch(i) {
      case 0:
        ledColor('r');
        break;
      case 1:
        ledColor('b');
        break;
      case 2:
        ledColor('g');
    }
    delay(800);
  }
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte);
  } else {
    if(ledColor(incomingByte)){
      ledLoop();
    }
    delay(1);
  }
}
