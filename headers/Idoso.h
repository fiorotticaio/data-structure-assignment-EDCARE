#ifndef IDOSO_H
#define IDOSO_H

#include "Lista_I.h"
#include "Cuidador.h"

// Tipo Idoso
typedef struct idoso Idoso;

// Tipo Lista_I (lista de idosos)
typedef struct lista_I Lista_I;

/*================ FUNÇÕES BÁSICAS ==============================*/

/** Inicializa um idoso somente com o nome e o resto vazio
 * inputs: nome (nome do idoso)
 * output: ponteiro para o idoso inicializado
 * pré-codição: nome não pode ser nulo
 * pós-condição: idoso de retorno existe com nome e outros campos vazios
*/
Idoso* InicializaIdoso(char* nome);

/** Imprime o nome do idoso
 * inputs: idoso
 * output: nenhum
 * pré-codição: idoso existe
 * pós-condição: nenhuma
*/
void ImprimeNomeIdoso(Idoso* idoso);

/** Libera a memória alocada para o idoso
 * inputs: idoso
 * output: nenhum
 * pré-codição: idoso existe
 * pós-condição: toda a memória alocada para o idoso foi liberada
*/
void DestroiIdoso(Idoso* idoso);


/*================ GETTERS E SETTERS =============================*/

/** Pega a lista de amigos do idoso
 * inputs: idoso
 * output: ponteiro para lista de amigos
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
Lista_I* getAmigosIdoso(Idoso* idoso);

/** Pega a lista de cuidadores do idoso
 * inputs: idoso
 * output: ponteiro para lista de cuidadores
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
Lista_C* getCuidadoresIdoso(Idoso* idoso);

/** Pega a temperatura do idoso
 * inputs: idoso
 * output: temperatura do idoso
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
double getTempIdoso(Idoso* idoso);

/** Seta a temperatura do idoso
 * inputs: idoso e temp (temperatura do idoso)
 * output: nenhum
 * pré-codição: idoso existe e temperatura válida
 * pós-condição: temperatura do idoso modificada
*/
void setTempIdoso(Idoso* idoso, double temp);

/** Pega a sequencia de febres baixas do idoso
 * inputs: idoso
 * output: qtd de febres baixas seguidas do idoso
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
int getFebreSeguidasIdoso(Idoso* idoso);

/** Seta a quantidade de febres seguidas do idoso
 * inputs: idoso e quantidade de febres
 * output: nenhum
 * pré-codição: idoso existe e quantidade é unsigned int
 * pós-condição: sequencia de febres do idoso modificada
*/
void setFebreSeguidasIdoso(Idoso* idoso, int qtd);

/** Pega a latitude do idoso
 * inputs: idoso
 * output: latitude do idoso
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
double getLatIdoso(Idoso* idoso);

/** Seta a latitude do idoso
 * inputs: idoso e lat (latitude do idoso)
 * output: nenhum
 * pré-codição: idoso existe e latitude válida
 * pós-condição: latitude do idoso modificada
*/
void setLatIdoso(Idoso* idoso, double lat);

/** Pega a longitude do idoso
 * inputs: idoso
 * output: longitude do idoso
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
double getLongiIdoso(Idoso* idoso);

/** Seta a longitude do idoso
 * inputs: idoso e longi (longitude do idoso)
 * output: nenhum
 * pré-codição: idoso existe e longitude válida
 * pós-condição: longitude do idoso modificada
*/
void setLongiIdoso(Idoso* idoso, double longi);

/** Pega o nome do idoso
 * inputs: idoso
 * output: ponteiro para string com nome do idoso
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
char * getNomeIdoso(Idoso* idoso);

/** Pega a queda do idoso
 * inputs: idoso
 * output: queda em booleano
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
int getCaiuIdoso(Idoso* idoso);

/** Seta o dado de se o idoso caiu ou não
 * inputs: idoso e se caiu ou não em booleano (inteiro)
 * output: nenhum
 * pré-codição: idoso existe
 * pós-condição: condição de queda do idoso modificada
*/
void setCaiuIdoso(Idoso* idoso, int caiu);

/** Pega o falecimento do idoso
 * inputs: idoso
 * output: falecimento em booleano
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
int getFaleceuIdoso(Idoso* idoso);

/** Seta o dado de se o idoso faleceu ou não
 * inputs: idoso e se faleceu ou não em booleano (inteiro)
 * output: nenhum
 * pré-codição: idoso existe
 * pós-condição: condição de 'faleceu' do idoso modificada
*/
void setFaleceuIdoso(Idoso* idoso, int faleceu);


/*================ OUTROS MÉTODOS ==============================*/

/** Verifica se o idoso caiu
 * inputs: idoso
 * output: int 1 se o idoso caiu, 0 se não
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
int Caiu(Idoso* idoso);

/** Verifica se o idoso está com febre alta
 * inputs: idoso
 * output: int 1 se o idoso está com febre alta, 0 se não
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
int EstaComFebreAlta(Idoso* idoso); 

/** Verifica se o idoso está com febre baixa
 * inputs: idoso
 * output: int 1 se o idoso está com febre baixa, 0 se não
 * pré-codição: idoso existe
 * pós-condição: idoso não é modificado
*/
int EstaComFebreBaixa(Idoso* idoso); 

/** Adiciona um amigo à lista de amigos do idoso, pelo fim da lista
 * inputs: idoso e amigo a ser adicionado
 * output: 0 caso não consiga adicionar o amigo e 1 caso consiga
 * pré-codição: idoso e amigo existem e amigo ainda nao esta na lista de amigso do idoso
 * pós-condição: idoso terá uma lista de amigos maior
*/
int adicionaAmigo(Idoso* idoso, Idoso* amigo);

/** Adiciona um cuidador à lista de cuidadores do idoso, pelo fim da lista
 * inputs: idoso e cuidador a ser adicionado
 * output: 0 caso não consiga adicionar o cuidador e 1 caso consiga
 * pré-codição: idoso e cuidador existem e cuidador ainda nao esta na lista de cuidadores do idoso
 * pós-condição: idoso terá uma lista de cuidadores maior
*/
int adicionaCuidador(Idoso* idoso, Cuidador* cuidador);


#endif // IDOSO_H