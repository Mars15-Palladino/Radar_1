#ifndef INTERFACE_FISICA_H // Proteção contra múltiplas inclusões
#define INTERFACE_FISICA_H // senão já definida, define INTERFACE_FISICA_H

#include <Arduino.h>//Biblioteca principal do Arduino, oferece funções básicas como delay(), millis(), digitalWrite(), etc.

#include <Adafruit_GFX.h>//Biblioteca de gráficos Adafruit, oferece coisas básicas como linhas, círculos, retângulos, etc.

#include <Adafruit_ST7735.h>//Biblioteca de driver para o display ST7735, que é usado no radar, faz o controle do microcontrolador do display, como enviar pixels, limpar a tela, etc.

#include <SPI.h>//Biblioteca para comunicação SPI, necessária para o funcionamento do display. Usada para enviar dados do microcontrolador para o display pelo barramento SPI, usando o Adafruit_ST7735.


class Interface_Fisica_Modulo{//Classe que representa a interface física do módulo de radar, responsável por gerenciar a comunicação com o hardware e fornecer funções para interagir com o radar.

    private: //Funções privadas e conexões com o hardware
        static const byte TFT_Pino_CS = 10; // Pino que seleciona o display (Chip Select) seleciona qual dispositivo SPI vai receber a comunicação.

        static const byte TFT_Pino_DC = 9; // informa ao controlador do TFT o que os dados enviados pelo Arduino significam, o que fazer, ligar desligar, mudar cor.

        static const byte TFT_Pino_RST = 8; // Pino que reseta o display (Reset)
        
        //quem transporta os dados para o microcontrolador do display, é o barramento SPI o pino MOSI, que é um protocolo de comunicação serial síncrono. O Adafruit_ST7735 usa a biblioteca SPI para enviar os dados do Arduino para o display.

        Adafruit_ST7735 tela_TFT; // Objeto da classe Adafruit_ST7735, que representa o display ST7735, usado para desenhar na tela do radar, como linhas, círculos, retângulos, etc. O objeto é inicializado com os pinos de controle do display (CS, DC e RST) e é usado para enviar comandos e dados para o display. Usado pelo construtor da classe Interface_Fisica_Modulo para inicializar o display e fazer a comunicação com o microcontrolador do display.
            int ultimoAnguloRadar = 0;
            int ultimoObjetoX = 0;
            int ultimoObjetoY = 0;
            bool ultimoObjetoDetectado = false;
            bool radarJaAtualizado = false;

    public: //Funções públicas

    Interface_Fisica_Modulo(); // Construtor da classe, inicializa a interface física do módulo de radar, faz comunicação com o CPP, Obriagtório ter o mesmo nome da classe.

    void inicializar_tela(); // Função que inicializa o display, limpa a tela e configura o modo de exibição, deve ser chamada no setup() do Arduino.
    void Recebe_Dados(float distanciaRecebidaSensor, int anguloRecebidoServo);
     void DesenharRadar();

    
};



#endif // INTERFACE_FISICA_H
