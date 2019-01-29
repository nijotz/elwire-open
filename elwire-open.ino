bool status = true;

double level_min[] = {
  0,     // blank
  0,     // blank
  0.00,  // channel 1
  0.05,  // channel 2
  0.00,  // channel 3
  0.05,  // channel 4
  0.00,  // channel 5
  0.00,  // channel 6
  0.05,  // channel 7
};

void setup() {
  pinMode(2, OUTPUT);  // channel A
  pinMode(3, OUTPUT);  // channel B
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H

  // We also have two status LEDs, pin 10 on the Escudo,
  // and pin 13 on the Arduino itself
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int order[] = {2,3,7,5,6};

  for (int i=0; i<5; i++) {
    if (status) {
      digitalWrite(order[i], HIGH);
    } else {
      digitalWrite(order[i], LOW);
    }

    delay(100);
  }

  // blink both status LEDs
  digitalWrite(10, status);
  digitalWrite(13, status);
  status = !status;
}
