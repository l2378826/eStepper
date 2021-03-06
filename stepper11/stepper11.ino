// Author :BruceTsao 2014.2.27

#define CLK_PIN 9
#define ENABLE_PIN 8
// #define RESET_PIN 11
#define CCW_PIN 10
void setup() {
  // Make all the pins OUTPUT and set them to LOW
  for (int i = 8 ; i <= 10 ; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  // This is the order according to the application notes
  //digitalWrite(RESET_PIN, HIGH);
  digitalWrite(ENABLE_PIN, HIGH);
}
int del = 500;
int counter = 0;
int dir = LOW;
void loop() {
  // Send out a clock signal. switch the direction bit every 2000 clocks.
  digitalWrite(CLK_PIN, HIGH);
  delayMicroseconds(del);
  digitalWrite(CLK_PIN, LOW);
  delayMicroseconds(del);
  counter++;
  if (counter >= (200*2)) {
    if (dir == LOW) {
      dir = HIGH;
      digitalWrite(CCW_PIN, dir);
      delay(1500);
    }
    else {
      dir = LOW;
      digitalWrite(CCW_PIN, dir);
      delay(1500);
  }
    counter = 0;
  }
}



