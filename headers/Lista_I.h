#ifndef LISTA_I_H
#define LISTA_I_H

#include "Idoso.h"
#include "Lista_C.h"

// Tipo Lista_I (lista de idosos)
typedef struct lista_I Lista_I;

// Tipo Celula_I (celula da lista de idosos)
typedef struct celula_I Celula_I;

// Tipo Idoso
typedef struct idoso Idoso;

/*================ FUNÇÕES BÁSICAS ==============================*/

/** 
 * input: nenhum
 * output: ponteiro para sentinela de lista de idosos
 * pré-condição: ?
 * pós-condição: ponteiro de retorno deve ser armazenado para uso
 */
Lista_I* InicializaLista_I();

/** Função de teste para verificar quais células foram registradas na lista
 * input: lista (lista de idosos) e uma string para o titulo na impressao
 * output: impressão na tela dos itens da lista
 * pré-condição: lista de cuidadors existe
 * pós-condição: lista não é modificada
 */
void ImprimeLista_I(Lista_I* lista, char * titulo);

/** Função de teste para verificar quais células foram registradas na lista
 * input: lista (lista de idosos)
 * output: impressão na tela dos itens da lista
 * pré-condição: lista de idoso existe
 * pós-condição: lista não é modificada
 */
void ImprimeAmigosIdosos(Lista_I* lista);

/** Função de teste para verificar quais células foram registradas na lista
 * input: lista (lista de idosos) e uma string para o titulo na impressao
 * output: impressão na tela dos itens da lista
 * pré-condição: lista de idoso existe
 * pós-condição: lista não é modificada
 */
void ImprimeCuidadoresIdosos(Lista_I* lista);

/** Libera a memória alocada para a lista de idosos
 * input: lista (lista de idosos) e uma variavel que controla se libera ou nao cada idoso das celulas (feito pra lista de amigos)
 * output: nenhum
 * pré-condição: lista de idosos existe
 * pós-condição: toda a memória alocada para a lista de idosos foi liberada
 */
void DestroiLista_I(Lista_I* lista, int mantemIdosos);


/*================ GETTERS E SETTERS =============================*/

/** Insere idoso na ultima posição da lista de idosos
 * input: ponteiro para lista de idosos e ponteiro para novo idoso
 * output: lista é modificada
 * pré-condição: lista deve existir, juntamente com o idoso
 * pós-condição: novo idoso é inserido como último item da lista
 */
void InsereIdosoUlt(Lista_I* lista, Idoso* idoso);

/** Procura idoso pelo nome na lista de idosos
 * input: ponteiro para lista de idosos e ponteiro para nome do idoso procurado
 * output: o ponteiro para o idoso com o nome procurado, ou um ponteiro nulo caso nao encontre
 * pré-condição: lista deve existir
 * pós-condição: nem a lista nem o idoso (quando encontrado) são é modificados
 */
Idoso* ProcuraNomeIdosoLista(Lista_I* lista, char* nomeIdoso);


/*================ OUTROS MÉTODOS ==============================*/

/** Faz a leitura dos arquivos com os dados dos idosos
 * input: lista de idosos e a quantidade de leituras passada pelo terminal (na hora da execução do programa)
 * output: nenhum
 * pré-condição: lista de idosos existe, bem como seu arquivo de leituras, e o
 *               valor da quantidade de leituras deve ser igual ao número de
 *               linhas no arquivo de entrada do idoso
 * pós-condição: todo o conteúdo da lista de idosos alterado conforme a leitura dos dados
 */
void FazLeituraIdosos(Lista_I* listaIdosos, int qtdLeituras);

/** Faz o registro dos arquivos com os dados dos idosos
 * input: lista de idosos
 * output: nenhum
 * pré-condição: lista de idosos existe, bem como o diretorio de saida
 * pós-condição: arquivos de saida dos idosos alterados conforme os atributos atuais
 */
void RegistraInfosIdosos(Lista_I* listaIdosos);

/** Retira um idoso do programa pois ele faleceu
 * input: idoso falecido e a lista de idosos
 * output: nenhum
 * pré-condição: idoso e lista de idosos existe
 * pós-condição: idoso retirado de todas as listas em que estava contido
 */
void MataIdoso(Idoso* idoso, Lista_I* listaIdosos);

/** Retira um idoso de uma lista de idosos (nome como chave)
 * input: lista de idosos, nome do idoso a ser retirado e um inteiro dizendo
 *          se sua memória deve ser desalocada ou não
 * output: nenhum
 * pré-condição: lista de idosos existe e nome válido
 * pós-condição: idoso retirado da lista de idosos com sua memória liberada ou não
 */
void RetiraIdosoLista(Lista_I* lista, char* nome, int destroiIdoso);

/** Aciona o amigo mais próximo de determinado idoso
 * input: latitude do idoso, longitude do idoso, lista de amigos do idoso 
 *        e arquivo de saída 
 * output: nenhum
 * pré-condição: latitude e longitude válidas, lista de amigoes do idoso existe e
 *               arquivo de saída existe
 * pós-condição: impressão no arquivo de saída o nome do amigo acionado
 */
void AcionaAmigoMaisProximo(double lat, double longi, Lista_I* listaAmigos, FILE* f);


#endif // LISTA_I_H