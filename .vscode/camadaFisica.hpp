#include <iostream>
#include <vector>

using namespace std;

#define BINARIA 1;
#define MANCHESTER 2;
#define BIPOLAR 3;

void camadaDeAplicacaoTransmissora(string mensagem);

void camadaFisicaTransmissora(int quadro[]);

int[] camadaFisicaTransmissora_Codificacao_Binaria(int quadro[]);

int[] camadaFisicaTransmissora_Codificacao_Manchester(int quadro[]);

int[] camadaFisicaTransmissora_Codificacao_Bipolar(int quadro[]);

/**
 * Método que simula a transmissão da informação no meio de
 * comunicação, passando de um ponto A (ponto transmissor) 
 * para um ponto B (ponto receptor)
 * @param fluxoBrutoDeBits 
 */
void MeioDeComunicacao(int fluxoBrutoDeBits []);

void camadaFisicaReceptora(int quadro[]);

int[] camadaFisicaReceptora_Codificacao_Binaria(int quadro[]);

int[] camadaFisicaReceptora_Codificacao_Manchester(int quadro[]);

int[] camadaFisicaReceptora_Codificacao_Bipolar(int quadro[]);

void camadaDeAplicacaoReceptora(int quadro[]);
