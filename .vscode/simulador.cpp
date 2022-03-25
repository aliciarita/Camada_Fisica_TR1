/**
 * @file simulador.cpp
 * @author Alícia Rita Oliveira dos Reis (170129306@aluno.unb)
 * @author Cintia Leal Rodrigues (170125696@aluno.unb) 
 * O simulador é responsável por simular as camadas de redes.
*/
#include "camadaFisica.hpp"

void main(){    
    aplicacaoTransmissora();
}

void aplicacaoTransmissora(){
    string mensagem;
    cont << "Digite uma mensagem:" <<endl;
    cin >> mensagem;

    camadaDeAplicacaoTransmissora(mensagem); /* chama a camada aplicacao transmissora */
    int tipoDeDecodificacao;       /* numero do tipo de codificacao */
    cout << "\nSelecione o tipo de protocolos:" <<endl
         << "\t1 -> Codificação Binária" <<endl
         << "\t2 -> Codificação Manchester" <<endl
         << "\t3 -> Codificação Bipolar" <<endl
    cin >> tipoDeDecodificacao;
    camadaFisicaTransmissora(tipoDeDecodificacao);
}
