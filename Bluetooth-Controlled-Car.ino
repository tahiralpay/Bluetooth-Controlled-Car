/*
  APRIL 2022 TALPAY
  PROJE İSMİ: Bluetooth Controlled Car
*/

#define on_led 13
#define arka_led 12
#define korna 11

const int motorA1  = 6;  // L298N'in IN3 Girişi
const int motorA2  = 10; // L298N'in IN1 Girişi
const int motorB1  = 5; // L298N'in IN2 Girişi
const int motorB2  = 9;  // L298N'in IN4 Girişi
int durum;
int Hiz = 255;
int engel = 0;

void setup() {
  pinMode(8, INPUT);
  pinMode(on_led, OUTPUT);
  pinMode(arka_led, OUTPUT);
  pinMode(korna, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  engel = digitalRead(8);

  if (Serial.available() > 0) {
    durum = Serial.read();
  }

  // Uygulamadan ayarlanabilen 3 hız seviyesi.(Değerler 0-255 arası)
  if (durum == '1') {
    Hiz = 50;
  }
  else if (durum == '2') {
    Hiz = 150;
  }
  else if (durum == '3') {
    Hiz = 255;
  }

  if (engel == 1) {
    /* İleri **/
    if (durum == 'F') {
      analogWrite(motorA1, Hiz);
      analogWrite(motorA2, 0);
      analogWrite(motorB1, Hiz);
      analogWrite(motorB2, 0);
    }

    /* İleri Sağ **/
    if (durum == 'G') {
      analogWrite(motorA1, Hiz );
      analogWrite(motorA2, 0);
      analogWrite(motorB1, 100);
      analogWrite(motorB2, 0);
    }

    /* İleri Sol ***/
    if (durum == 'I') {
      analogWrite(motorA1, 100);
      analogWrite(motorA2, 0);
      analogWrite(motorB1, Hiz);
      analogWrite(motorB2, 0);
    }

    /* Geri ***/
    if (durum == 'B') {
      analogWrite(motorA1, 0);
      analogWrite(motorA2, Hiz);
      analogWrite(motorB1, 0);
      analogWrite(motorB2, Hiz);
    }

    /* Geri Sağ **/
    if (durum == 'J') {
      analogWrite(motorA1, 0);
      analogWrite(motorA2, 100);
      analogWrite(motorB1, 0);
      analogWrite(motorB2, Hiz);
    }

    /* Geri Sol */
    if (durum == 'H') {
      analogWrite(motorA1, 0);
      analogWrite(motorA2, Hiz);
      analogWrite(motorB1, 0);
      analogWrite(motorB2, 100);
    }

    /* Sağ **/
    if (durum == 'R') {
      analogWrite(motorA1, Hiz);
      analogWrite(motorA2, 0);
      analogWrite(motorB1, 0);
      analogWrite(motorB2, 0);
    }

    /* Sol  ***/
    if (durum == 'L') {
      analogWrite(motorA1, 0);
      analogWrite(motorA2, 0);
      analogWrite(motorB1, Hiz);
      analogWrite(motorB2, 0);
    }

    /* Dur **/
    if (durum == 'S') {
      analogWrite(motorA1, 0);
      analogWrite(motorA2, 0);
      analogWrite(motorB1, 0);
      analogWrite(motorB2, 0);
    }

    /* Ön LAMBA **/
    if (durum == 'W') {
      digitalWrite(on_led, HIGH);
    }

    if (durum == 'w') {
      digitalWrite(on_led, LOW);
    }

    /* Arka LAMBA **/
    if (durum == 'U') {
      digitalWrite(arka_led, HIGH);
    }

    if (durum == 'u') {
      digitalWrite(arka_led, LOW);
    }

    /* stop **/
    if (durum == 'X') {
      digitalWrite(on_led, HIGH);
      digitalWrite(arka_led, HIGH);
    }

    if (durum == 'x') {
      digitalWrite(on_led, LOW);
      digitalWrite(arka_led, LOW);
    }

    /* korna **/
    if (durum == 'V') {
      digitalWrite(korna, HIGH);
    }

    if (durum == 'v') {
      digitalWrite(korna, LOW);
    }
  }

  if (engel == 0) {
    analogWrite(motorA1, Hiz);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, Hiz);
  }
}
