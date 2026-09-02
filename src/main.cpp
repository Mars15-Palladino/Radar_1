#include <Arduino.h>      // Biblioteca principal do Arduino


/*Teste Inicialização TFT no main, Substituido pelo arquivo Interface_Fisica.cpp e Interface_Fisica.h

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS     10
#define TFT_DC      9
#define TFT_RST     8

Adafruit_ST7735 tela = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


 tela.initR(INITR_BLACKTAB);

    tela.fillScreen(ST77XX_BLACK);

    tela.setTextColor(ST77XX_WHITE);
    tela.setTextSize(2);
    tela.setCursor(20, 60);
    tela.print("TFT OK");

    Serial.println("TFT inicializado.");
*/

#include "RadarServo.h"   // Biblioteca criada para controlar o servo
#include "RadarSensor.h"  // Biblioteca criada para controlar o HC-SR04
#include "RadarMenu.h"    // Biblioteca criada para controlar o menu do radar
#include "Interface_Fisica.h" // Biblioteca criada para controlar a interface física

#include "ModoManual.h" // Biblioteca criada para controlar o modo manual do radar

// Criação do objeto responsável pelo servo
RadarServo servo_pino_h;

// Criação do objeto responsável pelo sensor ultrassônico
RadarSensor sensor_pino_h;

// CRIAÇÃO DO OBJETO RESPONSÁVEL PELO CONTROLE MANUAL
ModoManual joystick_pino_h(&sensor_pino_h,&servo_pino_h);

// CRIAÇÃO DO OBJETO RESPONSÁVEL PELO MENU DO RADAR
RadarMenu radar_menu(&sensor_pino_h, &servo_pino_h, &joystick_pino_h);


Interface_Fisica_Modulo interface_fisica_TFT; // Criação do objeto responsável pela interface física do radar, que usa o objeto da biblioteca Adafruit_ST7735 para controlar o display TFT, e é usado para inicializar a tela, limpar a tela e configurar o modo de exibição do radar.



void setup()
{
    // Inicializa a comunicação serial com o computador
    Serial.begin(115200);
    
    interface_fisica_TFT.inicializar_tela(); // Inicializa a interface física do radar (TFT)
   

    // Configura o servo no pino digital 3
    servo_pino_h.pino_atribuido(3);

    // Configura o HC-SR04
    // TRIG = pino 5
    // ECHO = pino 6
    sensor_pino_h.pino_sensor_atribuido(5, 6);

    // CONFIGURA O PINO ANALOGICO A0 PARA O CONTROLE MANUAL
    joystick_pino_h.joystick_pino_atribuido(A0);

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