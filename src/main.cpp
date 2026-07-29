#include <Arduino.h>      // Biblioteca principal do Arduino
#include "RadarServo.h"   // Biblioteca criada para controlar o servo
#include "RadarSensor.h"  // Biblioteca criada para controlar o HC-SR04
#include "RadarMenu.h"

// Criação do objeto responsável pelo servo
RadarServo servo_pino_h;

// Criação do objeto responsável pelo sensor ultrassônico
RadarSensor sensor_pino_h;

RadarMenu radar_menu(&sensor_pino_h, &servo_pino_h); // Criação do objeto responsável pelo menu do radar


void setup()
{
    // Inicializa a comunicação serial com o computador
    Serial.begin(115200);

    // Configura o servo no pino digital 3
    servo_pino_h.pino_atribuido(3);

    // Configura o HC-SR04
    // TRIG = pino 5
    // ECHO = pino 6
    sensor_pino_h.pino_sensor_atribuido(5, 6);

    radar_menu.IniciarMenu();
}

void loop()
{
    if(radar_menu.LerOpcao_Menu()){
        radar_menu.ExecutarOpcao_Menu();
    }

    /*
    // Executa a movimentação do servo
    if(servo_pino_h.MoverServo() == true)
    {  
        float distancia = sensor_pino_h.OperacaoSensor_Distancia();

    // Exibe o resultado no Monitor Serial
    //Serial.print("Angulo ");
    //Serial.print(servo_pos);
    Serial.print("Ângulo: ");
    Serial.print(servo_pino_h.ObterAngulo());
    Serial.print(" Graus: ");

    Serial.print("Distância: ");
    Serial.print(distancia);
    Serial.println(" cm"); 

    }
    /*
    // Realiza uma medição de distância
    float distancia = sensor_pino_h.OperacaoSensor_Distancia();

    // Exibe o resultado no Monitor Serial
    //Serial.print("Angulo ");
    //Serial.print(servo_pos);
    Serial.print("Ângulo: ");
    Serial.print(servo_pino_h.ObterAngulo());
    Serial.print(" Graus: ");

    Serial.print("Distância: ");
    Serial.print(distancia);
    Serial.println(" cm");
    */
}