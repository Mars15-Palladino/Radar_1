#ifndef RADAR_MENU_H      // Evita que este arquivo seja incluído mais de uma vez
#define RADAR_MENU_H

#include <Arduino.h>
#include "ModoAutomatico.h"
#include "ModoManual.h"

#include "RadarSensor.h"
#include "RadarServo.h"

class RadarMenu
{
    private:
        int opcao;
        RadarSensor* sensor;
        RadarServo* servo;
        ModoAutomatico* modoAutomatico;
        ModoManual* modoManual;
        bool estavaNoModoAutomatico = false;
    public:
        RadarMenu(RadarSensor* sensor, RadarServo* servo, ModoManual* modoManual, ModoAutomatico* modoAutomatico);
        void IniciarMenu();
        bool LerOpcao_Menu();
        
        void ExecutarOpcao_Menu();
        
        void AtualizarModoAutomatico();
        bool ModoAutomaticoAtivo();

        bool ModoManualAtivo();
        void AtualizarModoManual();
};

   
       

#endif