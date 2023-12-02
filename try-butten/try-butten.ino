boolean buttFlag = 0;
boolean butt;

void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  butt = !digitalRead(A7);

  if (butt == 1 && buttFlag == 0) {
    buttFlag = 1;
    digitalWrite(LED_BUILTIN, 1);
  }

  if (butt == 0 && buttFlag == 1) {
    buttFlag = 0;
    digitalWrite(LED_BUILTIN, 0);
  }
}
