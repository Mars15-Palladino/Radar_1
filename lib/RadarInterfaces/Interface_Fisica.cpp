#include "Interface_Fisica.h"

Interface_Fisica_Modulo::Interface_Fisica_Modulo():tela_TFT(TFT_Pino_CS, TFT_Pino_DC, TFT_Pino_RST){

}

void Interface_Fisica_Modulo::inicializar_tela(){
    tela_TFT.initR(INITR_BLACKTAB);
    tela_TFT.fillScreen(ST77XX_BLACK);

    tela_TFT.setTextColor(ST77XX_WHITE);
    tela_TFT.setTextSize(3);
    tela_TFT.setCursor(20, 60);
    tela_TFT.print("TFT OK");

    Serial.println("TFT inicializado.");

}