#include "ModoAutomatico.h"

ModoAutomatico::ModoAutomatico(RadarSensor* sensor, RadarServo* servo){
    this->sensor = sensor;
    this->servo = servo;

}
void ModoAutomatico::ExecutarModoAutomatico(){
    while(funcionamentoModo_automatico == true){// por enquanto ele tende a ser um comando bloqueante, mas futuramente será um comando não bloqueante       
        if(Serial.available()>0){
            char teclado = Serial.read();

            switch(teclado){
                case '0':
                        funcionamentoModo_automatico = false;
                        Serial.println("==================================");
                        Serial.println("Operação automática encerrada.");
                    break;
            default:
                Serial.println("Opção inválida. Pressione 0 para encerrar a operação automática.");
                //return;  // Sai da função para evitar a execução do restante do código (Se eu deixar o return o resultado do zero não funciona de forma correta, então comentei ele)
            }
        }
            if(servo->MoverServo() == true)
            {  
                float distancia = sensor->OperacaoSensor_Distancia();
            // Exibe o resultado no Monitor Serial
            Serial.print("Ângulo: ");
            Serial.print(servo->ObterAngulo());
            Serial.print(" Graus: ");

            Serial.print("Distância: ");
            Serial.print(distancia);
            Serial.println(" cm");
            }
        }
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

