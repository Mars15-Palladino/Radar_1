#include "RadarMonitor.h"


RadarMonitor::RadarMonitor(Interface_Fisica_Modulo& interfaceRecebida) : DadosInterface(interfaceRecebida){
    
}

void RadarMonitor::Dados_Radar_Recebidos(float distanciaRecebidaSensor, int anguloRecebidoServo){
    if(millis() - ultimaAtualizacaoMonitor >= intervaloAtualizacaoMonitor){
        ultimaAtualizacaoMonitor = millis();

        DadosInterface.Recebe_Dados(distanciaRecebidaSensor, anguloRecebidoServo);
    }
}