/*===== Importação de bibliotecas =====*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../headers/Idoso.h"
#include "../headers/Cuidador.h"
#include "../headers/Lista_I.h"
#include "../headers/Lista_C.h"

/*===== Estruturação do tipo Cuidador =====*/
struct cuidador {
    char* nome;
    double lat;
    double longi;
};


/*================ FUNÇÕES BÁSICAS ==============================*/
Cuidador* InicializaCuidador(char* nome) {
    Cuidador* cuidador = (Cuidador*) malloc(sizeof(Cuidador));
    cuidador->nome = strdup(nome);
    cuidador->lat = 0.0;
    cuidador->longi = 0.0;
    return cuidador;
}

void ImprimeNomeCuidador(Cuidador* cuidador) { printf("%s\n", cuidador->nome); }

void DestroiCuidador(Cuidador* cuidador) {
    if (cuidador->nome!=NULL) free(cuidador->nome);
    if (cuidador!=NULL) free(cuidador);
}



/*================ GETTERS E SETTERS =============================*/
double getLatCuidador(Cuidador* cuidador) { return cuidador->lat; }

void setLatCuidador(Cuidador* cuidador, double lat) { cuidador->lat = lat; }

double getLongiCuidador(Cuidador* cuidador) { return cuidador->longi; }

void setLongiCuidador(Cuidador* cuidador, double longi) { cuidador->longi = longi; }

char * getNomeCuidador(Cuidador* cuidador){ return cuidador->nome; }