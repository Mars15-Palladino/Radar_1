#ifndef RADAR_SERVO_H // comandos para 
#define RADAR_SERVO_H


#include <Arduino.h>
#include <Servo.h>

class RadarServo{ // é feito o uso de chaves para criação de classes
    private:
       Servo RadarServo1;
       byte pinoServo;
       int servo_pos;

    public:
        void pino_atribuido(byte PinoServo_Atr);
        void OperacaoServo();
        
};

#endif