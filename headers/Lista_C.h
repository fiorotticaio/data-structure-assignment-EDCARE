#ifndef LISTA_C_H
#define LISTA_C_H

#include "./Cuidador.h"

// Tipo Lista_C (lista de cuidadores)
typedef struct lista_C Lista_C;

// Tipo Celula_C (celula da lista de cuidadores)
typedef struct celula_I Celula_I;

// Tipo Cuidador
typedef struct cuidador Cuidador;


/*================ FUNÇÕES BÁSICAS ==============================*/

/** 
 * input: nenhum
 * output: ponteiro para sentinela de lista de cuidadores
 * pré-condição: ?
 * pós-condição: ponteiro de retorno deve ser armazenado para uso
 */
Lista_C* InicializaLista_C();

/** Função de teste para verificar quais células foram registradas na lista
 * input: lista (lista de cuidadores)
 * output: impressão na tela dos itens da lista
 * pré-condição: lista de cuidadors existe
 * pós-condição: lista não é modificada
 */
void ImprimeLista_C(Lista_C* lista, char* titulo);

/** Libera a memória alocada para a lista de cuidadors
 * input: lista (lista de cuidadores)
 * output: nenhum
 * pré-condição: lista de cuidadors existe
 * pós-condição: toda a memória alocada para a lista de cuidadors foi liberada
 */
void DestroiLista_C(Lista_C* lista, int mantemCuidadores);


/*================ GETTERS E SETTERS =============================*/

/** 
 * input: ponteiro para lista de cuidadores e ponteiro para novo cuidador
 * output: nenhum
 * pré-condição: lista deve existir, juntamente com o cuidador
 * pós-condição: novo cuidador é inserido como último item da lista
 */
void InsereCuidadorUlt(Lista_C* lista, Cuidador* cuidador);

/** 
 * input: ponteiro para lista de cuidadores e ponteiro para nome do cuidador procurado
 * output: o ponteiro para o cuidador com o nome procurado, ou um ponteiro nulo caso nao encontre
 * pré-condição: lista deve existir
 * pós-condição: nem a lista nem o cuidador (quando encontrado) são é modificados
 */
Cuidador* ProcuraNomeCuidadorLista(Lista_C* lista, char* nomeCuidador);


/*================ OUTROS MÉTODOS ==============================*/

/** Atualiza os dados de localização dos cuidadores
 * input: ponteiro para lista de cuidadores e a quantidade de leituras a serem feitas
 * output: nenhum
 * pré-condição: lista de cuidadores deve existir
 * pós-condição: dados de localização dos cuidadores atualizados
 */
void AtualizaDadosCuidadores(Lista_C* listaCuidadores, int qtdLeituras);

/** Aciona o cuidador mais próximo de determinado idoso
 * input: latitude do idoso, longitude do idoso, lista de cuidadores do idoso 
 *        e arquivo de saída 
 * output: nenhum
 * pré-condição: latitude e longitude válidas, lista de cuidadores do idoso existe e
 *               arquivo de saída existe
 * pós-condição: impressão no arquivo de saída o nome do cuidador acionado
 */
void AcionaCuidadorMaisProximo(double lat, double longi, Lista_C* listaCuidadores, FILE* f);


#endif // LISTA_C_H