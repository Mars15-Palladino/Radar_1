#ifndef MODO_AUTOMATICO_H
#define MODO_AUTOMATICO_H

#include "RadarSensor.h"
#include "RadarServo.h"

class ModoAutomatico {
    private:
        RadarSensor* sensor;
        RadarServo* servo;
        bool funcionamentoModo_automatico = false; // Variável para controlar o loop do modo automático

    public:
    
    bool ModoAutomaticoAtivo();//Consultar estado
    void AtivarModoAutomatico();
    void DesativarModoAutomatico();

        ModoAutomatico(RadarSensor* sensor, RadarServo* servo);// Construtor que recebe os ponteiros para o sensor e o servo
        void ExecutarModoAutomatico();
        void modoManual();
};


#endif