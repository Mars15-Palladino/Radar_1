#include "RadarServo.h" // aqui eu chamo a biblioteca local que foi criada no lib

void RadarServo::pino_atribuido(byte PinoServo_Atr){
    
    if(PinoServo_Atr >=0 && PinoServo_Atr <= 13){
    pinoServo = PinoServo_Atr;
    RadarServo1.attach(pinoServo);//tem que igual ao objeto do .h
    }
    else{
        pinoServo = 3;
        RadarServo1.attach(pinoServo);
    }
};
void RadarServo::OperacaoServo(){
    servo_pos = 0;
    for(servo_pos=0;servo_pos<=90;servo_pos++){
        RadarServo1.write(servo_pos);
        delay(20);
    }
    for(servo_pos=90;servo_pos>=0;servo_pos--){
        RadarServo1.write(servo_pos);
        delay(20);    
    }
}