#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "camadaFisica.hpp"

#define BINARIA 1
#define MANCHESTER 2
#define BIPOLAR 3

void camadaFisicaTransmissora(vector<int> quadro, int codificacao){  
  vector<int> fluxoBrutoDeBits;     
  switch (codificacao) {  /* tipo de codificação inserida pelo usuário */
    case BINARIA:   /* codificação binária */
      fluxoBrutoDeBits = camadaFisicaTransmissora_Codificacao_Binaria(quadro);
      break;
    case MANCHESTER:    /* codificação manchester */
      fluxoBrutoDeBits = camadaFisicaTransmissora_Codificacao_Manchester(quadro);
      break;
    case BIPOLAR:   /* codificação bipolar */
      fluxoBrutoDeBits = camadaFisicaTransmissora_Codificacao_Bipolar(quadro);
      break;
    default:
      cout << "\nCodificação inválida! Tente novamente" << endl;
    break;
  }
  meioDeComunicacao(fluxoBrutoDeBits, codificacao);
}

/**/
void meioDeComunicacao(vector<int> fluxoBrutoDeBits, int codificacao) {
  vector<int> pontoA = fluxoBrutoDeBits;    /* ponto A = ponto de transmissão */
  vector<int> pontoB;       /* ponto B = ponto de recepção*/
  unsigned tam = pontoA.size(), i;
  for (i = 0; i < tam; i++) {
    pontoB.push_back(pontoA.at(i)); /* adiciona o elemento de ponto A no ponto B*/
  }
  camadaFisicaReceptora(pontoB, codificacao); /* ponto de recepção é passado para a camada física recptora*/
}

void camadaFisicaReceptora(vector<int> fluxoBrutoDeBits, int decodificacao) {
  vector<int> quadro;
  switch (decodificacao) {
    case BINARIA:   /* decodificação binária */
      quadro = camadaFisicaReceptora_Codificacao_Binaria(fluxoBrutoDeBits);
      break;
    case MANCHESTER:  /* decodificação manchester */
      quadro = camadaFisicaReceptora_Codificacao_Manchester(fluxoBrutoDeBits);
      break;
    case BIPOLAR: /* decodificação bipolar */
      quadro = camadaFisicaReceptora_Codificacao_Bipolar(fluxoBrutoDeBits);
      break;
    default:
        cout << "Decodificação inválida! Tente novamente" << endl;
      break;
  }
  camadaDeAplicacaoReceptora(quadro); /* Recebe o sinal codificado e o decodifica */
}

/* Binária */
vector<int> camadaFisicaTransmissora_Codificacao_Binaria(vector<int> quadro) {
  cout << endl << "Codificação Binária:" << endl;
  unsigned tam = quadro.size(), i;
  for (i = 0; i < tam; i++) {
    cout << quadro.at(i); /* printa o elemento do vetor em codigo ASCII*/
    cout << " ";
  }
  cout << endl;
  return quadro;
}

vector<int> camadaFisicaReceptora_Codificacao_Binaria(vector<int> fluxoBrutoDeBits) {
  return fluxoBrutoDeBits;  /* retorna o fluxo bruto de bits */
}

/* Manchester */
vector<int> camadaFisicaTransmissora_Codificacao_Manchester(vector<int> quadro) {
  cout << endl << "Codificação Manchester:" << endl;
  vector<int> clock{0, 1};    /* representa o clock */
  vector<int> bits;  
  unsigned tam = quadro.size(), i;
  for (i = 0; i < tam; i++) { /* quadro XOR clock */
    bits.push_back(quadro.at(i) ^ clock.at(0));   /* adiciona (quadro XOR clock(0)) */
    bits.push_back(quadro.at(i) ^ clock.at(1));   /* adiciona (quadro XOR clock(1)) */

    /* printa (quadro XOR clock) */
    cout << (quadro.at(i) ^ clock.at(0)); /*at -> elemento de acesso*/
    cout << " ";
    cout << (quadro.at(i) ^ clock.at(1));
    cout << " ";
  }
  cout << endl;
  return bits;
}


vector<int> camadaFisicaReceptora_Codificacao_Manchester(vector<int> fluxoBrutoDeBits){
  vector<int> bits;
  unsigned tam = fluxoBrutoDeBits.size(), i;
  for (i = 0; i < tam; i += 2) {  /* busca de 2 em 2*/
    bits.push_back(fluxoBrutoDeBits.at(i));  /* recuperação do sinal original */
  }
  return bits;
}

/* Bipolar */
vector<int> camadaFisicaTransmissora_Codificacao_Bipolar(vector<int> quadro){
  cout << endl << "Codificação Bipolar:" << endl;
  bool bipolar = false;  /*  O bipolar começa com 1 positivo */
  unsigned tam = quadro.size(), i;
  for (i = 0; i < tam; i++){
    if(quadro.at(i) == 0){  /* caso for 0, não muda */
      cout << " 0 ";
    }
    else if(quadro.at(i) == 1){   /* caso for 1*/
      if (bipolar) {    
        quadro.at(i) = -1;  /* muda o polo para -V */
        cout << "-1 ";
      } else {
        quadro.at(i) = 1;    /* muda o polo para +V */
        cout << " 1 ";
      }
     bipolar = !bipolar;
    } 
  }
  cout << endl;
  return quadro;
}

vector<int> camadaFisicaReceptora_Codificacao_Bipolar(vector<int> fluxoBrutoDeBits) {
  unsigned tam = fluxoBrutoDeBits.size(), i;
  for (i = 0; i < tam; i++) {    
    /* função abs -> pega o valor absoluto */
    /* função at -> acessa o elemento */
    fluxoBrutoDeBits.at(i) = abs(fluxoBrutoDeBits.at(i)); /* faz o módulo */
  }
  return fluxoBrutoDeBits;
}


vector<int> codificaMensagem(string mensagem) {
  vector<int> quadro;

  unsigned tam = mensagem.size(), i;
  for (i = 0; i < tam; i++) {  /* Pega mensagem inteira*/
    vector<int> tmp;
    int bin = int(mensagem.at(i));      /* função at -> acessa o elemento */
    for (int j = 0; j < 8; j++) {  /* 8 bits por letra */
      if (bin % 2 == 0) {
        tmp.push_back(0); /* adiciona 0 ao no fianl do vetor */
      } else {
        tmp.push_back(1); /* adiciona 1 ao no fianl do vetor */
      }
      bin >>= 1;    /* move 1 bit para direita*/
    }
    for (int k = 7; k >= 0; k--) {
      quadro.push_back(tmp.at(k));  /* Adiciona letra ao vetor maior */
    }
  }
  return quadro;
}

string decodificaMensagem(vector<int> quadro) { /*decodifica a mensagem*/
  string mensagem;
  unsigned tam = quadro.size(), i;    /* verifica o tamnho da mensagem */
  int letra;
  for (i = 0; i < tam; i++) {     /* para a mensagem inteira*/
    if (i % 8 == 0) {     /* 8 bits por letra */
      /* append -> anexa 1 caracteres */
      mensagem.append(1, char(letra));  /* Adiciona a letra na mensagem */
      letra = 0;    /* zera a letra */
    }
    letra <<= 1;   /* Forma cada letra */
    letra += quadro.at(i);  /* adicionando e movendo para esquerda */
  }
  mensagem.append(1, char(letra));  /* adiciona a última letra */
  return mensagem;
}
