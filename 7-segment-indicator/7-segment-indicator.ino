#define MY_PERIOD 250
const int anodPins[] = {A2, A3, A4, A5};
const int segmentsPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int numIndicators = 4;
const int numSegments = 8;

const int seg[10][numSegments] = {
  {1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0, 1, 1, 0}
};

uint32_t tmr1;
int numberIndicators[numIndicators] = {0, 0, 0, 0};

void setup() {
  for (int i = 0; i < numIndicators; i++) {
    pinMode(anodPins[i], OUTPUT);
  }
  for (int i = 0; i < numSegments; i++) {
    pinMode(segmentsPins[i], OUTPUT);
  }
}

void loop() {
  if (millis() - tmr1 >= MY_PERIOD) {
    tmr1 = millis();
    for (int i = numIndicators - 1; i >= 0; i--) {
      numberIndicators[i]++;
      if (numberIndicators[i] > 9) {
        numberIndicators[i] = 0;
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < numIndicators; i++) {
    setNumberAndDisplay(numberIndicators[i], i);
  }
}

void setNumberAndDisplay(int number, int indicator) {
  for (int k = 0; k < numSegments; k++) {
    digitalWrite(segmentsPins[k], seg[number][k] == 1 ? LOW : HIGH);
  }
  digitalWrite(anodPins[indicator], HIGH);
  delay(1);
  digitalWrite(anodPins[indicator], LOW);
}
