#ifndef Modo_Manual_h
#define Modo_Manual_h

#include "RadarServo.h"
#include "RadarSensor.h"

class ModoManual{
    private:
    RadarSensor*sensor; // ponteiro para o sensor
    RadarServo* servo; // ponteiro para o servo

    bool funcionamento_manual = true;
    unsigned long ultimoMovimento_Joystick_Servo;
    unsigned long Intervalo_movimento_Joystick_Servo = 10; 

    // ARMAZENA O PINO DO JOYSTICK
    byte Pino_joystick;
    // ARMAZENA O VALOR LIDO NO JOYSTICK
    int valor_joystick;
    
    public:
    ModoManual(RadarSensor*sensor,RadarServo*servo);

    void joystick_pino_atribuido(byte pinoJoystick_Atr);

    void ExecutarModoManual();

    int LerJoystick();
};
#endif