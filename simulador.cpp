#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "camadaFisica.hpp"

int main(void) {
  aplicacaoTransmissora();    /* chama a aplicação da transmissão */
  return 0;
}

/*** Camada de aplicação ***/

void aplicacaoTransmissora(void) {
  int codificacao = 0;      /* tipo de codificação */
  string mensagem;      
  cout << "Digite a mensagem: " << endl;
  getline(cin, mensagem);       /* recebe a mensagem a ser codificada*/
  cout << "Selecione o tipo de protocolo:" << endl;
  cout << "\t1 -> Binário" << endl;
  cout << "\t2 -> Manchester" << endl;
  cout << "\t3 -> Bipolar" << endl;
  cin >> codificacao;       /* recebe o tipo de codificação */
  camadaDeAplicacaoTransmissora(mensagem, codificacao);
}

/* Recebe a mensagem e a codifica a mensagem para transmitir o sinal  */ 
void camadaDeAplicacaoTransmissora(string mensagem, int codificacao){
  vector<int> quadro = codificaMensagem(mensagem);
  camadaFisicaTransmissora(quadro, codificacao);
}

/* Recebe o sinal codificado e o decodifica */
void camadaDeAplicacaoReceptora(vector<int> quadro) {  
  string mensagem = decodificaMensagem(quadro);
  aplicacaoReceptora(mensagem);
}

/* Recebe a mensagem a ser exibida */
void aplicacaoReceptora(string mensagem) {
  cout << "\nMensagem recebida: " << mensagem << endl;
}
