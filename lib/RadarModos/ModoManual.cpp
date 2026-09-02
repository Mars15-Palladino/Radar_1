#include "ModoManual.h"

ModoManual::ModoManual(RadarSensor*sensor,RadarServo* servo){
    this->sensor = sensor;
    this->servo = servo;
}
void ModoManual:: joystick_pino_atribuido(byte pinoJoystick_Atr){
     Pino_joystick = pinoJoystick_Atr;
    // CONFIGURA O A0 COMO ENTRADA ANALOGICA
    pinMode(Pino_joystick, INPUT);
}

int ModoManual::LerJoystick(){
    valor_joystick = analogRead(Pino_joystick);
    return valor_joystick;
}

void ModoManual::ExecutarModoManual(){
    // REINICIA O MODO MANUAL SEMPRE QUE ELE FOR SELECIONADO
    funcionamento_manual = true;

    // MANTEM O CONTROLE ATIVO ATE O USUARIO PRESSIONAR 0
    while (funcionamento_manual) {
        // VERIFICA SE O USUARIO SOLICITOU A SAIDA DO MODO MANUAL
        if (Serial.available() > 0) {
            char teclado = Serial.read();

             switch(teclado){
                case '0':
                        funcionamento_manual = false;
                        Serial.println("==================================");
                        Serial.println("Operação manual encerrada.");
                    break;
            default:
                Serial.println("Opção inválida. Pressione 0 para encerrar a operação automática.");
        }
    }
        // LE O VALOR ATUAL DO PINO A0
        LerJoystick();

        // MOVE O SERVO DE ACORDO COM A POSICAO DO JOYSTICK
        if (millis() - ultimoMovimento_Joystick_Servo >= Intervalo_movimento_Joystick_Servo) {
            ultimoMovimento_Joystick_Servo = millis();
            servo->ControleManual(valor_joystick);
            float distancia = sensor->OperacaoSensor_Distancia();

             // Exibe o resultado no Monitor Serial
            Serial.print("Ângulo: ");
            Serial.print(servo->ObterAngulo());
            Serial.print(" Graus: ");

            Serial.print("Distância: ");
            Serial.print(distancia);
            Serial.println(" cm");
            /*
            Serial.print("Joystick: ");
            Serial.println(valor_joystick);*/
        }
    }
}