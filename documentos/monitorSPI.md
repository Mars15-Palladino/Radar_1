# Sobre o Monitor

O TFT não é simplesmente um "monitor que recebe texto".

Ele é uma matriz de pixels.

No seu caso:

128 × 160 = 20.480 pixels

Cada pixel pode receber uma cor.

          X →
      0             127
      ┌──────────────┐
    0 │              │
      │              │
      │    TELA      │
      │              │
      │              │
  159 │              │
      └──────────────┘
      ↑
      Y

      OS zeros, são os cantos da tela, e funcionam como coordenadas

      E onde entra o SPI?

O Arduino não manda diretamente:

"Desenhe um círculo aqui."

Ele envia comandos e dados para o controlador do TFT através do SPI.

Simplificando:

Arduino
   │
   │ SPI
   │
   ▼
Controlador do TFT
   │
   ▼
Pixels

as conexões que você já fez têm funções diferentes:

Pino	Função
SCK	Clock do SPI
SDA	Dados enviados pelo Arduino (MOSI)
CS	Seleciona o TFT
AO/DC	Diz se estamos enviando comando ou dados
RESET	Reinicia o controlador
VCC	Alimentação
GND	Referência
LED	Iluminação


# Sobre  as fontes
   Aparentemente, elas possuem escalas, com o tamanho sendo de 0-3, com a fonte padrão tendo aproximadamente 6 pixels de largura e 8 de altura por linha

   Radar = 5*6 = 30 pixels

   Se eu mudar para o tamaho 2, a escla dobra

   Boa pergunta. Esse 8 veio da dimensão da fonte padrão do Adafruit_GFX, não de uma regra do seu TFT.

Na fonte padrão, cada caractere ocupa uma célula de aproximadamente:


6 × 8 pixels
↑   ↑
X   Y

   Resumindo, Definem quato espaço vai ser pego na tela


   há toda uma quetsão de cordenadas que vão definir a posição da escrita/desenho

   tela_TFT.setTextColor(ST77XX_YELLOW);// Define a cor do texto
    tela_TFT.setTextSize(1);// Define o tamanho do texto
    tela_TFT.setCursor(90, 2);// Define a posição do cursor para o texto
    tela_TFT.print("Radar");

    tela_TFT.setTextColor(ST77XX_WHITE);// Define a cor do texto
    tela_TFT.setTextSize(1);// Define o tamanho do texto
    tela_TFT.setCursor(80, 64);// Define a posição do cursor para o texto
    tela_TFT.print("Centro");


    tela_TFT.setTextColor(ST77XX_WHITE);// Define a cor do texto
    tela_TFT.setTextSize(1);// Define o tamanho do texto
    tela_TFT.setCursor(40, 66);// Define a posição do cursor para o texto
    tela_TFT.print("03/09/2026");

    Acima, tem algo escrito em uma parte da tela, e dois se sobrepondo

    tela_TFT.setTextSize(1);
tela_TFT.setCursor(40, 40);
tela_TFT.print("Centro");

Com a fonte padrão e setTextSize(1), podemos considerar aproximadamente:

cada caractere → 6 px de largura
altura → 8 px

Então "Centro" tem 6 caracteres:

6 × 6 = 36 px de largura

e aproximadamente 8 px de altura.

Logo, a região ocupada seria aproximadamente:

x = 40
y = 40
largura ≈ 36
altura ≈ 8