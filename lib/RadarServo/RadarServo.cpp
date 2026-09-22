#include "RadarServo.h" // aqui eu chamo a biblioteca local que foi criada no lib

void RadarServo::pino_atribuido(byte PinoServo_Atr){
    servo_pos = 0;
    sentidoHorario_Servo = true;
    ultimoMovimento_Servo = 0;
    
    if(PinoServo_Atr >=0 && PinoServo_Atr <= 13){
    pinoServo = PinoServo_Atr;
    RadarServo1.attach(pinoServo);//tem que igual ao objeto do .h
    }
    else{
        pinoServo = 3;
        RadarServo1.attach(pinoServo);
    }
};
bool RadarServo::MoverServo_automatico(){
     if(millis()-ultimoMovimento_Servo >= intervalo_Movimeto_Servo){
        ultimoMovimento_Servo = millis();// milis é a função, armazena último tempo marcado
                                         // Armazena o instante (em milissegundos) em que o servo realizou
                                        // o último movimento.
        if(sentidoHorario_Servo){
            servo_pos++;
            RadarServo1.write(servo_pos);
            if(servo_pos >= 180){
            sentidoHorario_Servo = false;
            }
        }
        else{
            servo_pos--;
            RadarServo1.write(servo_pos);
            if(servo_pos <= 0){
                sentidoHorario_Servo = true;
            }
        }
        return true;
     }
        return false;
}
   
int RadarServo::ObterAngulo(){
    return servo_pos;
}
void RadarServo::ControleManual(int valor_joystick){
    // GARANTE QUE A LEITURA DO A0 ESTEJA DENTRO DA FAIXA ANALOGICA
    valor_joystick = constrain(valor_joystick, 0, 1023);

    // CONVERTE A LEITURA DO A0 PARA UM ANGULO DE 0 A 180 GRAUS
    servo_pos = map(valor_joystick, 0, 1023, 0, 180);

    // LIMITA O ANGULO PARA PROTEGER O SERVO CONTRA VALORES FORA DA FAIXA
    servo_pos = constrain(servo_pos, 0, 180);

    // ENVIA O ANGULO CALCULADO PARA O SERVO
    RadarServo1.write(servo_pos);
}