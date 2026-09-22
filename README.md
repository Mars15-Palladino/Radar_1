# Radar ultrassônico

Firmware de um radar ultrassônico para **Arduino Uno**, desenvolvido em C++ com PlatformIO. O sistema movimenta um servo SG90, mede distâncias com um HC-SR04 e apresenta a varredura em um display TFT ST7735 de 1,8 polegada.

O projeto serve como estudo de sistemas embarcados, separação em módulos C++ e integração entre sensores, atuadores e interfaces de usuário.

## Funcionalidades

- Varredura automática entre 0 e 180 graus.
- Medição de distância em centímetros com o HC-SR04.
- Controle manual do ângulo por joystick analógico.
- Menu e comandos de operação pelo Monitor Serial.
- Visualização do radar no display TFT, com escala de 50 a 250 cm.
- Atualização temporizada do servo, do sensor e da interface usando `millis()`.
- Interrupção da operação automática ou manual pelo caractere `0` no Serial.

## Hardware

| Componente | Pino do Arduino Uno |
| --- | --- |
| Servo SG90 | D3 |
| HC-SR04 TRIG | D5 |
| HC-SR04 ECHO | D6 |
| Botão do joystick | D7 |
| TFT CS | D10 |
| TFT DC/A0 | D9 |
| TFT RST | D8 |
| Joystick analógico | A0 |
| TFT SCK | D13, SPI |
| TFT SDA/MOSI | D11, SPI |

Conecte também `VCC` e `GND` de todos os módulos. O servo deve ter alimentação adequada e compartilhar o GND com o Arduino. Consulte o datasheet dos módulos antes de aplicar 5 V ao display.

## Como executar

### Pré-requisitos

- VS Code com PlatformIO IDE.
- Arduino Uno conectado ao computador.
- Componentes montados conforme a tabela acima.

### Compilar e gravar

1. Conecte o Arduino ao computador.
2. Confira `upload_port` e `monitor_port` em [platformio.ini](platformio.ini). O valor versionado atualmente é `COM4`.
3. Compile e grave o firmware pelo PlatformIO ou execute:

```bash
pio run
pio run --target upload
```

4. Abra o monitor serial em 115200 baud:

```bash
pio device monitor --baud 115200
```

As portas `COM4` e os cabos não são universais; altere a configuração quando o Arduino aparecer em outra porta.

## Operação

Ao iniciar, o firmware imprime o menu:

```text
1 - Modo automático
2 - Controle Manual
0 - Encerrar Operação
```

- **Modo automático:** o servo percorre continuamente de 0 a 180 graus e retorna a 0. Para encerrar, envie `0` pelo Monitor Serial ou pressione o botão do joystick.
- **Modo manual:** a leitura de `A0` é convertida de 0--1023 para 0--180 graus. Para encerrar, envie `0` pelo Monitor Serial.
- **Botão do joystick:** funciona como alternância rápida do modo automático. Ao ativá-lo, o modo manual é desativado.
- **Display:** o arco verde representa a escala; o feixe verde representa o ângulo atual e os pontos vermelhos representam objetos detectados. Leituras sem eco são tratadas como distância zero.

Cada leitura serial segue o formato aproximado:

```text
Ângulo: 90 Graus: Distância: 42.50 cm
```

## Organização do código

```text
src/main.cpp                  Inicialização e laço principal
lib/RadarServo/               Controle automático e manual do servo
lib/RadarSensor/              Leitura do HC-SR04
lib/RadarModos/               Modos automático e manual
lib/RadarMenu/                Menu e seleção do modo
lib/RadarInterfaces/          Comunicação com o TFT ST7735
lib/RadarMonitor/             Encaminhamento dos dados para a interface
documentos/                   Requisitos e notas de implementação
```

Para detalhes do fluxo e das responsabilidades, consulte [documentos/arquitetura.md](documentos/arquitetura.md).

## Dependências

As bibliotecas são declaradas em [platformio.ini](platformio.ini):

- `arduino-libraries/Servo`
- `adafruit/Adafruit GFX Library`
- `adafruit/Adafruit ST7735 and ST7789 Library`

## Limitações e próximos passos

- A interface Python descrita em [documentos/requerimetos.md](documentos/requerimetos.md) ainda não está presente neste repositório.
- A leitura do HC-SR04 usa `pulseIn` com timeout de 30 ms; portanto, a movimentação é temporizada, mas a leitura individual pode bloquear durante esse timeout.
- A opção `0 - Encerrar Operação` encerra o modo selecionado e retorna ao menu; ela não desliga o Arduino.
- Possíveis evoluções: visualização externa em Python, ajuste da velocidade, detecção/acompanhamento de objetos e migração para ESP32.