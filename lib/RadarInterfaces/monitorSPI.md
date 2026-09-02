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