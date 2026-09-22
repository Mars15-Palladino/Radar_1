#ifndef RADAR_MONITOR_H
#define RADAR_MONITOR_H

//Aqui recebemos os dados e são enviados lá para a interface física
#include <Arduino.h>
#include "Interface_Fisica.h"
//#include"RadarSensor.h"

class RadarMonitor{
    private:
        unsigned long ultimaAtualizacaoMonitor;
        unsigned long intervaloAtualizacaoMonitor = 0;
        Interface_Fisica_Modulo& DadosInterface;


    public:
        //Recebe os dados do sensor e e posição do servo
        void Dados_Radar_Recebidos(float distanciaRecebidaSensor, int anguloRecebidoServo);
        RadarMonitor(Interface_Fisica_Modulo& DadosInterface);

};

#endif