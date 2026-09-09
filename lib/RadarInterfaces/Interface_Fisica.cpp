#include "Interface_Fisica.h"

Interface_Fisica_Modulo::Interface_Fisica_Modulo():tela_TFT(TFT_Pino_CS, TFT_Pino_DC, TFT_Pino_RST){

}

void Interface_Fisica_Modulo::inicializar_tela(){
    tela_TFT.initR(INITR_BLACKTAB);// Inicializa o display com a configuração de cor vermelha (INITR_REDTAB) para o ST7735, que define a ordem dos pinos e a forma como os dados são enviados para o display.

    tela_TFT.setRotation(1);// Define a rotação da tela para 1, que é a orientação paisagem (landscape) do display. Isso significa que o lado mais longo do display estará na horizontal e o lado mais curto estará na vertical. A rotação é importante para garantir que os elementos gráficos sejam desenhados corretamente na tela. Aceita valores de 0 a 3, onde cada valor representa uma rotação diferente (0 = retrato, 1 = paisagem, 2 = retrato invertido, 3 = paisagem invertida).

    tela_TFT.fillScreen(ST77XX_BLACK);// Limpa a tela do display, preenchendo-a com a cor preta (ST77XX_BLACK), que é definida na biblioteca Adafruit_ST7735.h. Isso garante que a tela esteja limpa antes de desenhar qualquer coisa nela.

    tela_TFT.setTextColor(ST77XX_YELLOW);// Define a cor do texto
    tela_TFT.setTextSize(1);// Define o tamanho do texto, ocupando 6 pixel de largura e 8 pixel de altura por caractere. O tamanho do texto pode ser ajustado para valores maiores, como 2, 3, etc., para aumentar a legibilidade do texto na tela.

    tela_TFT.setCursor(40, 2);// Define a posição do cursor para o texto
    tela_TFT.print("Radar");

    tela_TFT.setTextColor(ST77XX_WHITE);// Define a cor do texto
    tela_TFT.setTextSize(1);// Define o tamanho do texto
    tela_TFT.setCursor(40, 40);// Define a posição do cursor para o texto
    tela_TFT.print("Centro");


    tela_TFT.setTextColor(ST77XX_WHITE);// Define a cor do texto
    tela_TFT.setTextSize(1);// Define o tamanho do texto
    tela_TFT.setCursor(40, 50);// Define a posição do cursor para o texto
    tela_TFT.print("03/09/2026");


   delay(2000);// Aguarda 2 segundos para que o usuário possa ver a tela inicial antes de prosseguir com o restante do código. Isso é útil para exibir informações importantes, como o nome do projeto, a data ou outras mensagens iniciais, antes de iniciar a operação principal do radar.

   tela_TFT.fillRect(35, 35, 120, 52, ST77XX_RED);// Limpa a tela do display novamente, preenchendo-a com a cor preta (ST77XX_BLACK). Isso é feito para remover a tela inicial e preparar o display para exibir as informações principais do radar.



}