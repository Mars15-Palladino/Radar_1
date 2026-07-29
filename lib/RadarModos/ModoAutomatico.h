#ifndef MODO_AUTOMATICO_H
#define MODO_AUTOMATICO_H

#include "RadarSensor.h"
#include "RadarServo.h"

class ModoAutomatico {
    private:
        RadarSensor* sensor;
        RadarServo* servo;
        bool funcionamentoModo_automatico = true; // Variável para controlar o loop do modo automático

    public:
        ModoAutomatico(RadarSensor* sensor, RadarServo* servo);
        void ExecutarModoAutomatico();
};

#endif