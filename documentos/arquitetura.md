# Arquitetura do projeto

## Visão geral

O firmware é organizado em módulos pequenos. `main.cpp` monta os objetos e coordena o ciclo principal; as classes de domínio executam o controle do servo, a leitura do sensor, os modos de operação e a saída gráfica.


    A[main.cpp] --> B[RadarMenu]
    A --> C[RadarMonitor]
    B --> D[ModoAutomatico]
    B --> E[ModoManual]
    D --> F[RadarServo]
    D --> G[RadarSensor]
    E --> F
    E --> G
    C --> H[Interface_Fisica_Modulo]
    F --> I[Servo SG90]
    G --> J[HC-SR04]
    H --> K[TFT ST7735]


## Fluxo de inicialização

Em `setup()`:

1. A comunicação serial é iniciada em 115200 baud.
2. O TFT é inicializado e o desenho base do radar é renderizado.
3. O servo é associado ao pino D3.
4. O HC-SR04 é configurado com TRIG em D5 e ECHO em D6.
5. O joystick é configurado em A0 e o botão em D7 com `INPUT_PULLUP`.
6. O menu inicial é enviado ao Monitor Serial.

## Ciclo principal

`loop()` verifica primeiro o botão do joystick. Em seguida, o `RadarMenu` escolhe uma destas operações:

| Estado | Comportamento |
| --- | --- |
| Menu | Aguarda `1`, `2` ou `0` pelo Serial. |
| Automático | `RadarServo` avança ou recua um grau a cada 15 ms; após cada movimento, o sensor é consultado. |
| Manual | O joystick é lido a cada 10 ms e convertido para o intervalo de 0 a 180 graus. |

Independentemente do modo, `RadarMonitor` encaminha a última distância e o último ângulo para a interface física. A classe `RadarSensor` limita novas medições a um intervalo de 20 ms e retorna a última distância entre as medições.

## Módulos

### `RadarServo`

Mantém o ângulo atual, controla a direção da varredura e encapsula a biblioteca `Servo`. No modo manual, converte a leitura analógica do joystick para um ângulo de 0 a 180 graus.

### `RadarSensor`

Gera o pulso de disparo do HC-SR04, mede o tempo de eco e converte o resultado para centímetros. Um timeout de 30 ms evita espera indefinida quando não há eco.

### `RadarMenu`, `ModoAutomatico` e `ModoManual`

O menu interpreta os caracteres recebidos pelo Serial. Os modos possuem estados independentes e garantem que somente um deles seja ativado pela seleção normal do menu.

### `RadarMonitor` e `Interface_Fisica_Modulo`

O monitor desacopla a coleta dos dados do desenho no TFT. A interface usa SPI, desenha cinco arcos correspondentes a 50, 100, 150, 200 e 250 cm, e projeta o ponto detectado usando o ângulo e a distância recebidos.

## Cuidados para manutenção

- Atualize a tabela de pinagem do README quando alterar os pinos em `main.cpp` ou `Interface_Fisica.h`.
- Preserve o intervalo entre leituras do HC-SR04 para reduzir interferência entre ecos.
- Ao adicionar uma interface, prefira receber os dados por `RadarMonitor` em vez de acoplar o novo código ao sensor.
- Ao alterar o protocolo serial, atualize a seção de operação e qualquer consumidor externo ao mesmo tempo.


###
A ideia deste projeto surgiu do interesse por sistemas de radar, um tema que sempre despertou minha curiosidade e me levou a pesquisar e aprender sobre o assunto. Ao longo do desenvolvimento, o projeto proporcionou bastante aprendizado, principalmente em relação à organização, planejamento, modularização e integração de diferentes componentes de um sistema embarcado.

Em relação ao código, também houve aprendizado, porém a maior contribuição do projeto foi perceber, na prática, a importância de estruturar e planejar antes de iniciar uma implementação mais complexa.

Na etapa final, principalmente no desenvolvimento do controle e da representação gráfica no display TFT, houve maior utilização de ferramentas de Inteligência Artificial como apoio à implementação. Mesmo assim, essa etapa também contribuiu para identificar conhecimentos que ainda precisam ser estudados e praticados antes de assumir projetos de maior complexidade.

Dessa forma, o projeto cumpriu seu objetivo como experiência prática e serviu como base para identificar tanto os conhecimentos adquiridos quanto os pontos que precisam ser aprimorados nos próximos projetos.