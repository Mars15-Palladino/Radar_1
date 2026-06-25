#ifndef RADAR_SERVO_H      // Evita que este arquivo seja incluído mais de uma vez
#define RADAR_SERVO_H

#include <Arduino.h>       // Biblioteca principal do Arduino
#include <Servo.h>         // Biblioteca responsável pelo controle de servomotores

// Classe responsável pelo controle do servo motor do radar
class RadarServo
{
private:

    // Objeto da biblioteca Servo.
    // É através dele que enviamos os comandos ao servo, como:
    // attach() -> associa o servo a um pino do Arduino.
    // write()  -> move o servo para um determinado ângulo.
    //
    // Este objeto representa o servo físico conectado ao Arduino.
    Servo RadarServo1;

    // Armazena o pino digital onde o servo está conectado.
    byte pinoServo;

    // Armazena a posição (ângulo) atual do servo.
    // É atualizado durante a movimentação do servo.
    int servo_pos;

public:

    // Configura o pino utilizado pelo servo e realiza o attach().
    void pino_atribuido(byte PinoServo_Atr);

    // Executa a movimentação automática do servo (varredura).
    void MoverServo();

    // Retorna o último ângulo armazenado na variável servo_pos.
    int ObterAngulo();
};

#endif