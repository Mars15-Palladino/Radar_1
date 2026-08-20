#include "RadarMenu.h"

RadarMenu::RadarMenu(RadarSensor* sensor, RadarServo* servo, ModoManual* modoManual){
    this->sensor = sensor;
    this->servo = servo;
    this->modoManual = modoManual;
}

void RadarMenu::IniciarMenu(){
    Serial.println("=========== Menu do Radar =========");
    Serial.println("===================================");
    Serial.println("1 - Modo automático");
    Serial.println("2 - Controle Manual");
    Serial.println("0 - Encerrar Operação");
    Serial.println("===================================");
    Serial.print("Escolha a Opção: ");
}
bool RadarMenu::LerOpcao_Menu(){
    if(Serial.available()>0){
        char teclado = Serial.read();  // Converte o caractere para número, mas funciona apenas para números de 0 a 9

        if(teclado >= '0' && teclado <= '2'){

            opcao = teclado - '0';  // Converte o caractere para número, mas funciona apenas para números de 0 a 9
            Serial.print("Opção selecionada: ");
            Serial.println(opcao);
            Serial.println("===================================");
            
            while(Serial.available()>0){  // Limpa o buffer serial
            Serial.read();
            }
            return true; 
        } 
        else {
            Serial.println("Opção inválida. Por favor, selecione uma opção válida.");
            IniciarMenu();  // Reinicia o menu para que o usuário possa tentar novamente
            while(Serial.available()>0){  // Limpa o buffer serial
            Serial.read();
            }
            return false;
        }
    }
    return false;  // Retorna false se nenhuma opção foi selecionada
}   

void RadarMenu::ExecutarOpcao_Menu(){
    switch(opcao){
        case 1:{
            Serial.println("Modo Automático selecionado.");
            // Adicione aqui o código para executar o modo automático
            ModoAutomatico modoAuto(sensor, servo);
            modoAuto.ExecutarModoAutomatico();
            break;
        }
        case 2:{
            Serial.println("Modo Manual selecionado");
            modoManual->ExecutarModoManual();
            break;
        }
        case 0:{
            Serial.println("Encerrando operação.");
            // Adicione aqui o código para encerrar a operação
            break;
        }
        default:
            Serial.println("Opção inválida.");
            //Retorna para o menu se a opção for inválida
            break;
    }
    opcao = -1; // Reseta a opção para evitar execução repetida
    IniciarMenu(); // Retorna para o menu após a execução da opção
}