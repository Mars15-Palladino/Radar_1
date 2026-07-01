# Radar Arduino

Projeto de radar ultrassônico desenvolvido em C++ utilizando Arduino Uno, servo SG90 e sensor HC-SR04.

O objetivo é aplicar conceitos de arquitetura de software embarcado, programação orientada a objetos, programação não bloqueante com `millis()` e integração entre sensores e atuadores.

## Evolução do Projeto

### v0.1.0
- Criação das classes `RadarServo` e `RadarSensor`
- Controle básico do servo
- Leitura básica do sensor HC-SR04

### v0.2.0
- Implementação da movimentação não bloqueante utilizando `millis()`
- Sincronização da leitura do HC-SR04 com a movimentação do servo
- Comunicação Serial exibindo ângulo e distância em tempo real


Tecnologias Utilizadas

- Arduino Uno
- HC-SR04
- Servo SG90
- PlatformIO
- C++

## Status Atual

✅ Controle do servo através da classe RadarServo

✅ Leitura de distância através da classe RadarSensor

✅ Comunicação Serial

✅ Estrutura modular utilizando C++

✅  Implementação da movimentação não bloqueante do servo SG90 utilizando `millis()`

✅ Sincronização da leitura do sensor HC-SR04 com a movimentação do servo, realizando uma medição para cada posição angular


## Estrutura

```text
src/
lib/
  RadarServo/
  RadarSensor/
```

## Próximas Funcionalidades

- [x] Integrar servo e sensor durante a varredura (30/06/2026) 
- [x] Implementar varredura angular automática (30/06/2026)
- [x] Exibir ângulo e distância pela Serial (30/06/2026)

## Interface

- [ ] Adicionar display para informações e menu
- [ ] Implementar controle manual por joystick
## Funcionalidades
- [ ] Implementar modo automático após inatividade
## Expansões
- [ ] Criar visualização gráfica estilo radar/sonar
- [ ] Migrar para ESP32
- [ ] Adicionar comunicação sem fio

## Objetivo

Desenvolver um radar ultrassônico completo para estudo de:

- Sistemas embarcados
- Programação orientada a objetos em C++
- Sensores e atuadores
- Arquitetura de software embarcado
- Interface homem-máquina (IHM)
- Programação não bloqueante utilizando `millis()`