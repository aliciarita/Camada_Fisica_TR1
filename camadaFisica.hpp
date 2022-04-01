#ifndef _CAMADA_FISICA
#define _CAMADA_FISICA

using namespace std;

/**
 * Fonte de informação encaminha a mensagem
 */
void aplicacaoTransmissora();

/**
 * Recebe a mensagem e a codifica a mensagem para transmitir o sinal
 * @param mensagem      inserida pelo usuário
 * @param codificacao   tipo de codificação
 */
void camadaDeAplicacaoTransmissora(string mensagem, int codificacao);

/**
 * Define o tipo de codificação da mensagem
 * @param quadro   sinal transmitido
 * @param codificacao   tipo de codificação
 */
void camadaFisicaTransmissora(vector<int> quadro, int codificacao);

/**
 * Método transmissor da codificação binária
 * @param quadro   sinal a ser codificado p/ binário
 * @return vector<int>  Retorna um vetor de bits binários
 */
vector<int> camadaFisicaTransmissora_Codificacao_Binaria(vector<int> quadro);

/**
 * Método transmissor da codificação manchester
 * @param quadro   sinal a ser codificado p/ manchester
 * @return vector<int>  retorna um vetor de bits manchester
 */
vector<int> camadaFisicaTransmissora_Codificacao_Manchester(vector<int> quadro);

/**
 * Método transmissor da codificação bipolar
* @param quadro   sinal a ser codificado p/ bipolar
 * @return vector<int>  retorna um vetor de bits bipoalr
 */
vector<int> camadaFisicaTransmissora_Codificacao_Bipolar(vector<int> quadro);

/**
 * Para corrigir a perda se sinal, fazemos uma codificação da mensagem.
 * @param mensagem  mensagem a ser codificada
 * @return vector<int>  retorna um vetor codificado em 8 bits
 */
vector<int> codificaMensagem(string mensagem);

/**
 * Simula a transmissão da informação no meio de
 * comunicação, passando de um ponto A (ponto transmissor) 
 * para um ponto b (ponto receptor)
 * @param fluxoBrutoDeBits  bits
 * @param codificacao   tipo de codificação
 */
void meioDeComunicacao(vector<int> fluxoBrutoDeBits, int codificacao);

/**
 * Define o tipo de decodificação do sinal
 * @param fluxoBrutoDeBits bit
 * @param decodificacao  tipo de decodificação
 */
void camadaFisicaReceptora(vector<int> fluxoBrutoDeBits, int decodificacao);

/**
 * Recebe o sinal codificado e o decodifica
 * @param quadro   trem de bits 
 */
void camadaDeAplicacaoReceptora(vector<int> quadro);

/**
 * Método receptor da codificação binária
 * @param fluxoBrutoDeBits 
 * @return vector<int> 
 */
vector<int> camadaFisicaReceptora_Codificacao_Binaria(vector<int> fluxoBrutoDeBits);

/**
 * Método receptor da codificação manchester
 * @param fluxoBrutoDeBits 
 * @return vector<int> 
 */
vector<int> camadaFisicaReceptora_Codificacao_Manchester(vector<int> fluxoBrutoDeBits);

/**
 * Método recpetor da codificação bipolar
 * @param fluxoBrutoDeBits 
 * @return vector<int> 
 */
vector<int> camadaFisicaReceptora_Codificacao_Bipolar(vector<int> fluxoBrutoDeBits);

/**
 * O sinal recebido é decodificado 
 * @param quadro   trem de bits 
 * @return string  retorna a mensagem ao usuário
 */
string decodificaMensagem(vector<int> quadro);

/**
 * Recebe a mensagem a ser exibida
 * @param mensagem 
 */
void aplicacaoReceptora(string mensagem);

#endif