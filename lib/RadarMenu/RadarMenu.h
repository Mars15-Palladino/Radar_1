#ifndef RADAR_MENU_H      // Evita que este arquivo seja incluído mais de uma vez
#define RADAR_MENU_H

#include <Arduino.h>
#include "ModoAutomatico.h"
#include "RadarSensor.h"
#include "RadarServo.h"

class RadarMenu
{
    private:
        int opcao;
        RadarSensor* sensor;
        RadarServo* servo;
    public:
        RadarMenu(RadarSensor* sensor, RadarServo* servo);
        void IniciarMenu();
        bool LerOpcao_Menu();
        void ExecutarOpcao_Menu();
};

   
       

#endif