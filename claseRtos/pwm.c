#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define SERVO_PIN 1       // Pin 1 de WiringPi (GPIO 18)
#define PWM_RANGE 200     // Rango del PWM

void setup() {
    printf("Raspberry Pi wiringPi PWM test program\n");
    
    if (wiringPiSetup() == -1) {
        exit(1);
    }

    pinMode(SERVO_PIN, PWM_OUTPUT); // Configurar el pin como salida PWM
    pwmSetMode(PWM_MODE_MS);         // Configurar el modo de PWM
    pwmSetRange(PWM_RANGE);          // Establecer el rango del PWM
    pwmSetClock(192);                // Establecer la frecuencia del PWM
}

void moveServo(int angle) {
    // Convertir el ángulo de 0-180 a un rango de 0-200 para el PWM
    int pwmValue = (angle * PWM_RANGE) / 180; 
    pwmWrite(SERVO_PIN, pwmValue);  // Escribir el valor de PWM al pin
}

int main(void) {
    setup();

    // Mover el servo de 0 a 180 grados
    for (int angle = 0; angle <= 180; angle++) {
        moveServo(angle);
        usleep(500000);  // Esperar 0.5 segundos
    }

    // Mover el servo de 180 a 0 grados
    for (int angle = 180; angle >= 0; angle--) {
        moveServo(angle);
        usleep(500000);  // Esperar 0.5 segundos
    }

    return 0;
}
