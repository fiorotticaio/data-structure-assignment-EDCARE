#ifndef CUIDADOR_H
#define CUIDADOR_H

#include "Lista_C.h"
#include "./Idoso.h"

// Tipo Cuidador
typedef struct cuidador Cuidador;


/*================ FUNÇÕES BÁSICAS ==============================*/

/** Inicializa um cuidador somente com o nome e o resto vazio
 * inputs: nome (nome do cuidador)
 * output: ponteiro para o cuidador inicializado
 * pré-codição: nome não pode ser nulo
 * pós-condição: cuidador de retorno existe com nome e outros campos vazios
*/
Cuidador* InicializaCuidador(char* nome);

/** Imprime o nome do cuidador
 * inputs: cuidador
 * output: nenhum
 * pré-codição: cuidador existe
 * pós-condição: nenhuma
*/
void ImprimeNomeCuidador(Cuidador* cuidador);

/** Libera a memória alocada para o cuidador
 * inputs: cuidador
 * output: nenhum
 * pré-codição: cuidador existe
 * pós-condição: toda a memória alocada para o cuidador foi liberada
*/
void DestroiCuidador(Cuidador* cuidador);


/*================ GETTERS E SETTERS =============================*/

/** Pega a latitude do cuidador
 * inputs: cuidador
 * output: latitude do cuidador
 * pré-codição: cuidador existe
 * pós-condição: cuidador não é modificado
*/
double getLatCuidador(Cuidador* cuidador);

/** Seta a latitude do cuidador
 * inputs: cuidador e lat (latitude do cuidador)
 * output: nenhum
 * pré-codição: cuidador existe e latitude válida
 * pós-condição: latitude do cuidador modificada
*/
void setLatCuidador(Cuidador* cuidador, double lat);

/** Pega a longitude do cuidador
 * inputs: cuidador
 * output: longitude do cuidador
 * pré-codição: cuidador existe
 * pós-condição: cuidador não é modificado
*/
double getLongiCuidador(Cuidador* cuidador);

/** Seta a longitude do cuidador
 * inputs: cuidador e longi (longitude do cuidador)
 * output: nenhum
 * pré-codição: cuidador existe e longitude válida
 * pós-condição: longitude do cuidador modificada
*/
void setLongiCuidador(Cuidador* cuidador, double longi);

/** Pega o nome do cuidador
 * inputs: cuidador
 * output: ponteiro para string com nome
 * pré-codição: cuidador existe
 * pós-condição: cuidador não é modificado
*/
char * getNomeCuidador(Cuidador* cuidador);


#endif // CUIDADOR_H