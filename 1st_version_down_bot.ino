#include <Servo.h>

// ==========================================
// НАСТРОЙКА ПЕРВОГО КОМПЛЕКТА (X, Y) -> (10, 13)
// ==========================================
Servo servo1_X; // Серво для оси X первого джойстика
Servo servo1_Y; // Серво для оси Y первого джойстика

const int pinJoy1_X = A0;      // Джойстик 1: Ось X
const int pinJoy1_Y = A1;      // Джойстик 1: Ось Y
const int pinServo1_X = 10;    // Серво 1 (Ось X) -> Пин 10
const int pinServo1_Y = 13;    // Серво 2 (Ось Y) -> Пин 13

// ==========================================
// НАСТРОЙКА ВТОРОГО КОМПЛЕКТА (A2, A3) -> (4, 7)
// ==========================================
Servo servo2_X; // Серво для оси X второго джойстика
Servo servo2_Y; // Серво для оси Y второго джойстика

const int pinJoy2_X = A2;      // Джойстик 2: Ось X
const int pinJoy2_Y = A3;      // Джойстик 2: Ось Y
const int pinServo2_X = 4;     // Серво 3 (Ось X) -> Пин 4
const int pinServo2_Y = 7;     // Серво 4 (Ось Y) -> Пин 7

// Переменные для хранения значений
int val1_X, val1_Y, angle1_X, angle1_Y;
int val2_X, val2_Y, angle2_X, angle2_Y;

void setup() {
  Serial.begin(9600); // Для отладки

  // --- Инициализация ПЕРВОГО комплекта ---
  servo1_X.attach(pinServo1_X);
  servo1_Y.attach(pinServo1_Y);
  
  // Ставим в ноль при старте
  servo1_X.write(0);
  servo1_Y.write(0);

  // --- Инициализация ВТОРОГО комплекта ---
  servo2_X.attach(pinServo2_X);
  servo2_Y.attach(pinServo2_Y);
  
  // Ставим в ноль при старте
  servo2_X.write(0);
  servo2_Y.write(0);

  // Ждем 1 секунду, чтобы все 4 сервопривода успели занять начальное положение
  delay(1000); 
}

void loop() {
  // === ОБРАБОТКА ПЕРВОГО ДЖОЙСТИКА ===
  val1_X = analogRead(pinJoy1_X);
  val1_Y = analogRead(pinJoy1_Y);
  
  angle1_X = map(val1_X, 0, 1023, 0, 180);
  angle1_Y = map(val1_Y, 0, 1023, 0, 180);
  
  servo1_X.write(angle1_X);
  servo1_Y.write(angle1_Y);

  // === ОБРАБОТКА ВТОРОГО ДЖОЙСТИКА ===
  val2_X = analogRead(pinJoy2_X);
  val2_Y = analogRead(pinJoy2_Y);
  
  angle2_X = map(val2_X, 0, 1023, 0, 180);
  angle2_Y = map(val2_Y, 0, 1023, 0, 180);
  
  servo2_X.write(angle2_X);
  servo2_Y.write(angle2_Y);

  // Небольшая задержка для стабильности
  delay(15);

 
  Serial.print("Set1 X:"); Serial.print(angle1_X);
  Serial.print(" Y:"); Serial.print(angle1_Y);
  Serial.print(" | Set2 X:"); Serial.print(angle2_X);
  Serial.print(" Y:"); Serial.println(angle2_Y);

}