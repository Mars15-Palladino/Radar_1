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
    // Mantém o controle ativo até o usuário pressionar 0.
    if (Serial.available() > 0) {
        char teclado = Serial.read();

        while (Serial.available() > 0) {
            Serial.read();
        }

        if (teclado == '0') {
            funcionamento_manual = false;
            Serial.println("==================================");
            Serial.println("Operação manual encerrada.");
            return;
        }

        Serial.println("Opção inválida. Pressione 0 para encerrar a operação manual.");
    }

    if (millis() - ultimoMovimento_Joystick_Servo >= Intervalo_movimento_Joystick_Servo) {
        ultimoMovimento_Joystick_Servo = millis();

        LerJoystick();
        servo->ControleManual(valor_joystick);
        float distancia = sensor->OperacaoSensor_Distancia();

        Serial.print("Ângulo: ");
        Serial.print(servo->ObterAngulo());
        Serial.print(" Graus: Distância: ");
        Serial.print(distancia);
        Serial.println(" cm");
    }
}
bool ModoManual::ModoManualAtivo()
{
    return funcionamento_manual;
}
void ModoManual::AtivarModoManual()
{
    funcionamento_manual = true;
    ultimoMovimento_Joystick_Servo = 0;
}
void ModoManual::DesativarModoManual()
{
    funcionamento_manual = false;
}