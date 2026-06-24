# Radar Arduino

Projeto de radar ultrassônico utilizando:

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

## Estrutura

```text
src/
lib/
  RadarServo/
  RadarSensor/
```

## Próximas Funcionalidades

- [ ] Integrar servo e sensor durante a varredura
- [ ] Implementar varredura angular automática
- [ ] Exibir ângulo e distância pela Serial
- [ ] Adicionar display para informações e menu
- [ ] Implementar controle manual por joystick
- [ ] Implementar modo automático após inatividade
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