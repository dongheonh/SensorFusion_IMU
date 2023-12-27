#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno3 = Adafruit_BNO055(55, 0x28);

void setup() {
    Serial.begin(9600);
    if (!bno3.begin()) {
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
        while (1);
    }
    bno3.setExtCrystalUse(true);
}

void loop() {
    imu::Vector<3> accel = bno3.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
    imu::Vector<3> mag = bno3.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
    imu::Vector<3> gyro = bno3.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);

    // Print data in the specified format
    Serial.print(accel.x()); Serial.print(", ");
    Serial.print(accel.y()); Serial.print(", ");
    Serial.print(accel.z()); Serial.print(", ");
    Serial.print(mag.x()); Serial.print(", ");
    Serial.print(mag.y()); Serial.print(", ");
    Serial.print(mag.z()); Serial.print(", ");
    Serial.print(gyro.x()); Serial.print(", ");
    Serial.print(gyro.y()); Serial.print(", ");
    Serial.println(gyro.z());

    delay(500);
}
