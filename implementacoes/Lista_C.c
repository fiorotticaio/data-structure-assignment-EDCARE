/*===== Importação de bibliotecas =====*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../headers/Cuidador.h"

/*===== Estruturação do tipo Lista de Cuidadores =====*/
typedef struct celula_C Celula_C;

struct lista_C {
    Celula_C* Prim;
    Celula_C* Ult;
};

struct celula_C {
    Cuidador* cuidador;
    Celula_C* prox;
};


/*================ FUNÇÕES BÁSICAS ==============================*/
Lista_C* InicializaLista_C() {
    Lista_C * lista = malloc(sizeof(Lista_C));
    lista->Prim = NULL;
    lista->Ult = NULL;
    return lista;
}

void ImprimeLista_C(Lista_C* lista, char* titulo){
    Celula_C * c = lista->Prim;
    printf("\n------%s------\n", titulo);
    while(c!=NULL){
        char * nome = getNomeCuidador(c->cuidador);
        printf("%s\n", nome);
        c = c->prox;
    }   
}

void DestroiLista_C(Lista_C* lista, int mantemCuidadores) {
    Celula_C * c = lista->Prim;
    Celula_C * cProx = NULL;
    while (c!=NULL) {
        cProx = c->prox;
        if (!mantemCuidadores) DestroiCuidador(c->cuidador);
        if (c != NULL) free(c);
        c = cProx;
    }
    free(lista);
}


/*================ GETTERS E SETTERS =============================*/
void InsereCuidadorUlt(Lista_C* lista, Cuidador* cuidador) {
    Celula_C * celula = malloc(sizeof(Celula_C));
    celula->cuidador = cuidador;
    celula->prox = NULL;
    
    if (lista->Prim==NULL) {
        lista->Prim = lista->Ult = celula;
    } else {
        lista->Ult->prox = celula;
        lista->Ult = celula;
    }
}

Cuidador* ProcuraNomeCuidadorLista(Lista_C* lista, char* nomeCuidador){
    Cuidador* achado = NULL;
    Celula_C* i = NULL;


    for(i = lista->Prim ; i!=NULL ; i=i->prox){
        if (!strcmp(getNomeCuidador(i->cuidador), nomeCuidador)) {
            achado = i->cuidador;
            break;
        }
    }

    return achado;
}


/*================ OUTROS MÉTODOS ==============================*/
void AtualizaDadosCuidadores(Lista_C* listaCuidadores, int qtdLeituras) {

    char diretorio[100];
    Celula_C* p = NULL;


    p = listaCuidadores->Prim;
    while (p != NULL) {
        int i = 0, j = 0;
        double lat = 0.0;
        double longi = 0.0;

        sprintf(diretorio, "entradas/%s.txt", getNomeCuidador(p->cuidador));
        FILE* f = fopen(diretorio, "r");
        if (!f) {
            printf("Diretorio de entrada de leituras de cuidadores não existe!\n");
            exit(0);
        }

        while (i < qtdLeituras) {
            fscanf(f, "%lf;", &lat);
            setLatCuidador(p->cuidador, lat);

            fscanf(f, "%lf;", &longi);
            setLongiCuidador(p->cuidador, longi);

            i++;
        }

        p = p->prox;

        fclose(f);
    }

}

void AcionaCuidadorMaisProximo(double lat, double longi, Lista_C* listaCuidadores, FILE* f) {

    Cuidador* cuidadorMaisProx = NULL;
    Celula_C* p = NULL;
    double dist = 0, minDist = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    for (p = listaCuidadores->Prim; p != NULL; p = p->prox) {

        x1 = lat;
        y1 = longi;
        x2 = getLatCuidador(p->cuidador);
        y2 = getLongiCuidador(p->cuidador);

        dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

        if (p == listaCuidadores->Prim) {
            minDist = dist;
            cuidadorMaisProx = p->cuidador;

        } else {
            if (dist < minDist) {
                minDist = dist;
                cuidadorMaisProx = p->cuidador;
            }
        }
    }

    if (cuidadorMaisProx==NULL) printf("ERRO: o idoso nao tem cuidadores\n");
    else fprintf(f, ", acionou %s\n", getNomeCuidador(cuidadorMaisProx));
}