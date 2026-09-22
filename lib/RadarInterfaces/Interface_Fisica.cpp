#include "Interface_Fisica.h"
#include <math.h>

int16_t x1, y1;
uint16_t largura, altura;

namespace
{
const int CentroRadarX = 80;
const int CentroRadarY = 127;
const int RaioMaximoRadar = 78;
const float DistanciaMaximaRadar = 250.0;
}

Interface_Fisica_Modulo::Interface_Fisica_Modulo():tela_TFT(TFT_Pino_CS, TFT_Pino_DC, TFT_Pino_RST){

}

void Interface_Fisica_Modulo::Recebe_Dados(float distanciaRecebidaSensor, int anguloRecebidoServo){
    int anguloRadar = constrain(anguloRecebidoServo, 0, 180);

    if (radarJaAtualizado)
    {
        for (int deslocamento = -10; deslocamento <= 0; deslocamento++)
        {
            int anguloRastro = constrain(ultimoAnguloRadar + deslocamento, 0, 180);
            float radianoRastro = anguloRastro * PI / 180.0;
            int fimRastroX = CentroRadarX + cos(radianoRastro) * RaioMaximoRadar;
            int fimRastroY = CentroRadarY - sin(radianoRastro) * RaioMaximoRadar;
            tela_TFT.drawLine(CentroRadarX, CentroRadarY, fimRastroX, fimRastroY, ST77XX_BLACK);
        }

        if (ultimoObjetoDetectado)
        {
            tela_TFT.drawLine(CentroRadarX, CentroRadarY, ultimoObjetoX, ultimoObjetoY, ST77XX_BLACK);
            tela_TFT.fillCircle(ultimoObjetoX, ultimoObjetoY, 3, ST77XX_BLACK);
        }

        DesenharRadar();
    }

    for (int deslocamento = -10; deslocamento <= 0; deslocamento++)
    {
        int anguloRastro = constrain(anguloRadar + deslocamento, 0, 180);
        float radianoRastro = anguloRastro * PI / 180.0;
        int fimRastroX = CentroRadarX + cos(radianoRastro) * RaioMaximoRadar;
        int fimRastroY = CentroRadarY - sin(radianoRastro) * RaioMaximoRadar;
        uint16_t corRastro = deslocamento == 0
            ? ST77XX_GREEN
            : tela_TFT.color565(0, 35 + (deslocamento + 10) * 4, 0);

        tela_TFT.drawLine(CentroRadarX, CentroRadarY, fimRastroX, fimRastroY, corRastro);
    }

    bool objetoDetectado = distanciaRecebidaSensor > 0;
    if (objetoDetectado)
    {
        float radiano = anguloRadar * PI / 180.0;
        float distanciaNoRadar = min(distanciaRecebidaSensor, DistanciaMaximaRadar);
        int raioObjeto = (distanciaNoRadar * RaioMaximoRadar) / DistanciaMaximaRadar;
        int objetoX = CentroRadarX + cos(radiano) * raioObjeto;
        int objetoY = CentroRadarY - sin(radiano) * raioObjeto;
        tela_TFT.fillCircle(objetoX, objetoY, 2, ST77XX_RED);
    }

    tela_TFT.fillRect(0, 113, 25, 12, ST77XX_BLACK);
    tela_TFT.setTextColor(ST77XX_GREEN);
    tela_TFT.setTextSize(1);
    tela_TFT.setCursor(2, 115);
    tela_TFT.print(anguloRadar);

    ultimoAnguloRadar = anguloRadar;
    ultimoObjetoDetectado = objetoDetectado;
    float distanciaNoRadar = min(distanciaRecebidaSensor, DistanciaMaximaRadar);
    ultimoObjetoX = objetoDetectado ? CentroRadarX + cos(anguloRadar * PI / 180.0) * ((distanciaNoRadar * RaioMaximoRadar) / DistanciaMaximaRadar) : 0;
    ultimoObjetoY = objetoDetectado ? CentroRadarY - sin(anguloRadar * PI / 180.0) * ((distanciaNoRadar * RaioMaximoRadar) / DistanciaMaximaRadar) : 0;
    radarJaAtualizado = true;

}
void Interface_Fisica_Modulo::DesenharRadar()
{
    const int raios[] = {16, 31, 47, 62, 78};
    const int distancias[] = {50, 100, 150, 200, 250};

    // Arcos do radar
    for (int indice = 0; indice < 5; indice++)
    {
        int raio = raios[indice];

        for (int grau = 0; grau <= 180; grau++)
        {
            float radiano = grau * PI / 180.0;

            int x = CentroRadarX + cos(radiano) * raio;
            int y = CentroRadarY - sin(radiano) * raio;

            tela_TFT.drawPixel(x, y, ST77XX_GREEN);
        }

        tela_TFT.setTextColor(ST77XX_GREEN);
        tela_TFT.setTextSize(1);
        String textoDistancia = String(distancias[indice]) + "cm";
        int16_t textoX;
        int16_t textoY;
        uint16_t textoLargura;
        uint16_t textoAltura;
        tela_TFT.getTextBounds(textoDistancia, 0, 0, &textoX, &textoY, &textoLargura, &textoAltura);
        tela_TFT.setCursor(CentroRadarX - textoLargura / 2, CentroRadarY - raio - 8);
        tela_TFT.print(distancias[indice]);
        tela_TFT.print("cm");
    }

    for (int grau = 0; grau <= 180; grau += 5)
    {
        float radiano = grau * PI / 180.0;
        int comprimentoMarca = grau % 30 == 0 ? 6 : 3;
        int inicioX = CentroRadarX + cos(radiano) * (RaioMaximoRadar - comprimentoMarca);
        int inicioY = CentroRadarY - sin(radiano) * (RaioMaximoRadar - comprimentoMarca);
        int fimX = CentroRadarX + cos(radiano) * RaioMaximoRadar;
        int fimY = CentroRadarY - sin(radiano) * RaioMaximoRadar;

        tela_TFT.drawLine(inicioX, inicioY, fimX, fimY, ST77XX_GREEN);
    }

}
void Interface_Fisica_Modulo::inicializar_tela()
{
    tela_TFT.initR(INITR_BLACKTAB);
    tela_TFT.setRotation(1);
    tela_TFT.fillScreen(ST77XX_BLACK);

    DesenharRadar();
}