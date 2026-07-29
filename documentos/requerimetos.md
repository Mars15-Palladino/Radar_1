# Sistema de Radar Ultrassônico

## Objetivo
 
Desenvolver um sistema de radar utilizando um sensor ultrassônico HC-SR04 e um servo motor controlados por um Arduino, capaz de realizar varreduras do ambiente, medir distâncias e apresentar os resultados tanto no monitor serial quanto em uma interface gráfica desenvolvida em Python.

## Requisitos funcionais

 RF01 – Medição de distância

O sistema deve medir a distância dos objetos utilizando o sensor ultrassônico HC-SR04.

RF02 – Varredura angular

O sistema deve movimentar o servo motor entre 0° e 180° para realizar a varredura do ambiente.

RF03 – Exibição no Monitor Serial

O sistema deve enviar ao Monitor Serial o ângulo atual do servo e a distância medida.

RF04 – Interface em Python

O sistema deve disponibilizar os dados através da comunicação serial para uma aplicação desenvolvida em Python.
A aplicação deverá representar graficamente as medições do radar.

RF05 – Atualização contínua

As medições devem ser atualizadas continuamente durante a varredura.

## Requisitos não funcionais

RNF01 – Tempo de resposta

O sistema deve atualizar as leituras em tempo real durante a movimentação do servo.

RNF02 – Organização do código

O software deverá ser desenvolvido em linguagem C++ utilizando PlatformIO, com separação entre arquivos .h e .cpp.

RNF03 – Comunicação serial

A comunicação entre Arduino e computador deverá ocorrer via porta serial.

RNF04 – Facilidade de manutenção

O código deverá ser modular para permitir futuras expansões, como novos sensores ou diferentes interfaces gráficas.

# Funcionalidades futuras

- Controle manual do radar por joystick.
- Alteração da velocidade de varredura.
- Seleção entre modo automático e modo manual.
- Uso de display OLED.
- Migração para ESP32.
- Integração com câmera.
- Detecção e acompanhamento de objetos.

# Componentes utilizados

- Arduino Uno
- Sensor ultrassônico HC-SR04
- Servo motor SG90
- Protoboard
- Cabos jumper
- Computador para execução da interface em Python