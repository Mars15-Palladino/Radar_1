#ifndef SENSOR_RADAR_H  // Evita múltiplas inclusões do mesmo arquivo
#define SENSOR_RADAR_H

#include <Arduino.h>    // Funções e tipos básicos do Arduino
#include "RadarServo.h"

// Classe responsável por controlar o sensor ultrassônico HC-SR04
class RadarSensor
{
private:

    // Pino responsável por disparar o pulso ultrassônico
    byte pino_trig;

    // Pino responsável por receber o eco da onda sonora
    byte pino_echo;

    // Armazena o tempo medido pelo ECHO em microssegundos
    unsigned long tempoEco;
    unsigned long Ultimo_Movimento_Sensor;
    unsigned long Ultimo_Tempo_Movimeto_Sensor = 20;
    float Ultima_Distancia;

public:

    // Recebe os pinos utilizados pelo sensor e realiza sua configuração
    void pino_sensor_atribuido(byte trig, byte echo);

    // Executa uma medição e retorna a distância em centímetros
    float OperacaoSensor_Distancia();
    //Retorno dos valores
    void Informacoes();
};

#endif