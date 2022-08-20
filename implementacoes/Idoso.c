/*===== Importação de bibliotecas =====*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../headers/Idoso.h"
#include "../headers/Cuidador.h"
#include "../headers/Lista_I.h"
#include "../headers/Lista_C.h"

/*===== Estruturação do tipo Idoso =====*/
struct idoso {
    char* nome;
    double temp;
    int febreSeguidas;
    double lat;
    double longi;
    int caiu;
    int faleceu;
    Lista_I* amigos;
    Lista_C* cuidadores;
};


/*================ FUNÇÕES BÁSICAS ==============================*/

Idoso* InicializaIdoso(char* nome) {
    Idoso* idoso = (Idoso*) malloc(sizeof(Idoso));
    idoso->nome = strdup(nome);
    idoso->temp = 0.0;
    idoso->lat = 0.0;
    idoso->longi = 0.0;
    idoso->caiu = 0;
    idoso->faleceu = 0;
    idoso->febreSeguidas = 0;
    idoso->amigos = InicializaLista_I();
    idoso->cuidadores = InicializaLista_C();
    return idoso;
}

void ImprimeNomeIdoso(Idoso* idoso) { printf("%s\n", idoso->nome); }

void DestroiIdoso(Idoso* idoso) {
    if (idoso->nome !=NULL) free(idoso->nome);
    if (idoso->amigos!=NULL) DestroiLista_I(idoso->amigos, 1);
    if (idoso->cuidadores!=NULL) DestroiLista_C(idoso->cuidadores, 1);
    if (idoso!=NULL) free(idoso);
}


/*================ GETTERS E SETTERS =============================*/
Lista_I* getAmigosIdoso(Idoso* idoso) { return idoso->amigos; }

Lista_C* getCuidadoresIdoso(Idoso* idoso) { return idoso->cuidadores; }

double getTempIdoso(Idoso* idoso) { return idoso->temp; }

void setTempIdoso(Idoso* idoso, double temp) { idoso->temp = temp; }

int getFebreSeguidasIdoso(Idoso* idoso) { return idoso->febreSeguidas; }

void setFebreSeguidasIdoso(Idoso* idoso, int qtd) { idoso->febreSeguidas = qtd; }

double getLatIdoso(Idoso* idoso) { return idoso->lat; }

void setLatIdoso(Idoso* idoso, double lat) { idoso->lat = lat; }

double getLongiIdoso(Idoso* idoso) { return idoso->longi; }

void setLongiIdoso(Idoso* idoso, double longi) { idoso->longi = longi; }

char * getNomeIdoso(Idoso* idoso) { return idoso->nome; }

int getCaiuIdoso(Idoso* idoso) { return idoso->caiu; }

void setCaiuIdoso(Idoso* idoso, int caiu) { idoso->caiu = caiu; }

int getFaleceuIdoso(Idoso* idoso) { return idoso->faleceu; }

void setFaleceuIdoso(Idoso* idoso, int faleceu) { idoso->faleceu = faleceu; }

/*================ OUTROS MÉTODOS ==============================*/
int Caiu(Idoso* idoso) {
    if (idoso->caiu) return 1;
    else return 0;
}

int EstaComFebreAlta(Idoso* idoso) {
    if (idoso->temp >= 38.0) return 1;
    else return 0;
}

int EstaComFebreBaixa(Idoso* idoso) {
    if (idoso->temp >= 37.0 && idoso->temp < 38.0) return 1;
    else return 0;
}

int adicionaAmigo(Idoso* idoso, Idoso* amigo){
    if (ProcuraNomeIdosoLista(idoso->amigos, amigo->nome)) return 0; // já são amigos

    InsereIdosoUlt(idoso->amigos, amigo);
    InsereIdosoUlt(amigo->amigos, idoso); 

    return 1;
}

int adicionaCuidador(Idoso* idoso, Cuidador* cuidador){
    if (ProcuraNomeCuidadorLista(getCuidadoresIdoso(idoso), getNomeCuidador(cuidador))) return 0; // já é cuidador

    InsereCuidadorUlt(getCuidadoresIdoso(idoso), cuidador);

    return 1;
}