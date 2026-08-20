#include "ModoManual.h"

ModoManual::ModoManual(RadarServo* servo){
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
        // LE O VALOR ATUAL DO PINO A0
        LerJoystick();

        // MOVE O SERVO DE ACORDO COM A POSICAO DO JOYSTICK
        if (millis() - ultimoMovimento_Joystick_Servo >= Intervalo_movimento_Joystick_Servo) {
            ultimoMovimento_Joystick_Servo = millis();
            servo->ControleManual(valor_joystick);

            // MOSTRA A LEITURA DO A0 E O ANGULO ENVIADO AO SERVO
            Serial.print("A0: ");
            Serial.print(valor_joystick);
            Serial.print(" | ANGULO: ");
            Serial.println(servo->ObterAngulo());
        }

        // VERIFICA SE O USUARIO SOLICITOU A SAIDA DO MODO MANUAL
        if (Serial.available() > 0) {
            char teclado = Serial.read();

            if (teclado == '0') {
                funcionamento_manual = false;
                Serial.println("=============================");
                Serial.println("OPERACAO MANUAL ENCERRADA");
            }
        }
    }
}