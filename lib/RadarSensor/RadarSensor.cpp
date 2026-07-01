#include "RadarSensor.h" // Biblioteca local da classe RadarSensor


// Configura os pinos utilizados pelo HC-SR04
void RadarSensor::pino_sensor_atribuido(byte trig, byte echo)
{
    // Armazena os pinos recebidos do main.cpp
    pino_trig = trig;
    pino_echo = echo;
    Ultimo_Movimento_Sensor = 0;
    Ultima_Distancia = 0;
    tempoEco = 0;

    // TRIG envia sinais para o sensor
    pinMode(pino_trig, OUTPUT);

    // ECHO recebe sinais do sensor
    pinMode(pino_echo, INPUT);
}

// Realiza uma medição e retorna a distância em centímetros
float RadarSensor::OperacaoSensor_Distancia(){
    if(millis()-Ultimo_Movimento_Sensor>=Ultimo_Tempo_Movimeto_Sensor){
        Ultimo_Movimento_Sensor = millis();
        
    // Garante que o TRIG começa em nível baixo
    digitalWrite(pino_trig, LOW);
    delayMicroseconds(2);

    // Envia um pulso de 10 µs para iniciar a medição
    digitalWrite(pino_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pino_trig, LOW);

    // Mede o tempo que o pino ECHO permanece em HIGH
    // Timeout de 30000 µs (30 ms)
    // Se não houver eco, retorna 0
    tempoEco = pulseIn(pino_echo, HIGH, 30000);

    // Converte o tempo medido em distância
    // 0.0343 cm/µs = velocidade do som
    // Divide por 2 porque o som vai e volta
    Ultima_Distancia = (tempoEco * 0.0343) / 2;
    }
    // Retorna a distância calculada em centímetros
    return Ultima_Distancia;

}