#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>

MPU6050 mpu;
Servo servoMotor;

int16_t ax, ay, az;
int16_t gx, gy, gz;

int servoPin = 6; // Servo pin
int servoAngle = 90; // Başlangıç açısı

void setup() {
  Serial.begin(9600); // Seri monitörü başlatıyoruz
  Wire.begin();
  mpu.initialize();
  servoMotor.attach(servoPin);
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // MPU6050'den gelen verileri seri monitöre yazdır
  Serial.print("Ax "); Serial.print(ax);
  Serial.print(" Ay: "); Serial.print(ay);
  Serial.print(" Az: "); Serial.print(az);
  Serial.print(" Gx: "); Serial.print(gx);
  Serial.print(" Gy: "); Serial.print(gy);
  Serial.print(" Gz: "); Serial.println(gz);

  // Burada MPU6050'den okunan değerlere göre servo motorun açısını belirleyebilirsiniz.
  // Örnek olarak, eğim açısını kullanabilirsiniz.

  int angle = map(ax, -17000, 17000, 0, 180); // MPU6050'den gelen x eksenine göre açıyı hesapla
  servoMotor.write(angle);

  delay(1000);
}