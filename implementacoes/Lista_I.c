/*===== Importação de bibliotecas =====*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../headers/Lista_I.h"

/*===== Estruturação do tipo Lista de Idosos =====*/
typedef struct celula_I Celula_I;

struct lista_I {
    Celula_I* Prim;
    Celula_I* Ult;
};

struct celula_I {
    Idoso* idoso;
    Celula_I* prox;
};


/*================ FUNÇÕES BÁSICAS ==============================*/
Lista_I* InicializaLista_I() {
    Lista_I * lista = malloc(sizeof(Lista_I));
    lista->Prim = NULL;
    lista->Ult = NULL;
    return lista;
}

void ImprimeLista_I(Lista_I* lista, char * titulo){
    Celula_I * c = lista->Prim;
    printf("\n------%s------\n", titulo);

    while(c!=NULL){
        char * nome = getNomeIdoso(c->idoso);
        printf("%s\n", nome);
        c = c->prox;
    }   
}

void ImprimeAmigosIdosos(Lista_I* lista){
    Celula_I * c = lista->Prim;
    
    while(c!=NULL){
        char * nome = getNomeIdoso(c->idoso);
        char titulo[100];
        sprintf(titulo, "LISTA DE AMIGOS DE %s", nome);
        ImprimeLista_I(getAmigosIdoso(c->idoso), titulo);
        c = c->prox;
    }
}

void ImprimeCuidadoresIdosos(Lista_I* lista){
    Celula_I * c = lista->Prim;
    
    while(c!=NULL){
        char * nome = getNomeIdoso(c->idoso);
        char titulo[100];
        sprintf(titulo, "LISTA DE CUIDADORES DE %s", nome);
        ImprimeLista_C(getCuidadoresIdoso(c->idoso), titulo);
        c = c->prox;
    }
}

void DestroiLista_I(Lista_I* lista, int mantemIdosos) {
    Celula_I * c = lista->Prim;
    Celula_I * cProx = NULL;
    while(c!=NULL){
        cProx = c->prox;
        if (!mantemIdosos) DestroiIdoso(c->idoso);
        if (c!=NULL) free(c);
        c = cProx;
    }
    free(lista);
}


/*================ GETTERS E SETTERS =============================*/
void InsereIdosoUlt(Lista_I* lista, Idoso* idoso) {
    Celula_I * celula = malloc(sizeof(Celula_I));
    celula->idoso = idoso;
    celula->prox = NULL;
    
    if (lista->Prim==NULL) {
        lista->Prim = lista->Ult = celula;
    } else {
        lista->Ult->prox = celula;
        lista->Ult = celula;
    }
}

Idoso* ProcuraNomeIdosoLista(Lista_I* lista, char* nomeIdoso){
    Idoso* achado = NULL;
    Celula_I* i = NULL;

    for(i = lista->Prim ; i!=NULL ; i=i->prox){
        char * nomeAtual = getNomeIdoso(i->idoso);
        if (!strcmp(nomeAtual, nomeIdoso)) {
            achado = i->idoso;
            break;
        }
    }

    return achado;
}

/*================ OUTROS MÉTODOS ==============================*/
void FazLeituraIdosos(Lista_I* listaIdosos, int qtdLeituras) {
    
    char diretorio[100], diretorio2[100];
    int i = 0, j = 0;

    Celula_I* p;
    Idoso* idosoASerMatado = NULL;

    //limpado todos os arquivos de saida dos idosos, e criando novos caso já nao existam
    for(p=listaIdosos->Prim;p!=NULL;p=p->prox) {
        sprintf(diretorio, "saidas/%s-saida.txt", getNomeIdoso(p->idoso));
        FILE* limpaArquivo = fopen(diretorio, "w");
        fclose(limpaArquivo);
    }
    
    while (i < qtdLeituras) {

        int caiu=0, faleceu = 0;
        double temp = 0.0, lat = 0.0, longi = 0.0;
        p = listaIdosos->Prim;

        while (p != NULL) {

            /* abrindo o arquivo de entrada do idoso */
            sprintf(diretorio, "entradas/%s.txt", getNomeIdoso(p->idoso));
            FILE* arquivoEntrada = fopen(diretorio, "r");

            // atualiza a localização dos cuidadores do idoso que esta sendo lido
            AtualizaDadosCuidadores(getCuidadoresIdoso(p->idoso), i+1);

            
            // caso nao seja a primeira leva de leituras, então deve-se desconsiderar todas as linhas
            // do arquivo que ja foram lidas nos loops passados
            if (i>0) {
                for(j=0;j<i;j++) fscanf(arquivoEntrada, "%*[^\n]\n");

                if (j!=i) {
                    printf("ERRO COM: %s\n", getNomeIdoso(p->idoso));
                    continue;
                }
            }

            /* se ler a temperatuda (primeira leitura) com erro na verdade é o falecimento */
            if (fscanf(arquivoEntrada, "%lf;", &temp) != 1) {
                
                idosoASerMatado = p->idoso;
                setFaleceuIdoso(p->idoso, 1);
                faleceu = 1;
            
            } else {
                
                setTempIdoso(p->idoso, temp);

                //febre baixa
                if (getTempIdoso(p->idoso)>=37 && getTempIdoso(p->idoso)<38) {
                    setFebreSeguidasIdoso(p->idoso, getFebreSeguidasIdoso(p->idoso)+1);
                }
                
                fscanf(arquivoEntrada, "%lf;", &lat);
                setLatIdoso(p->idoso, lat);

                fscanf(arquivoEntrada, "%lf;", &longi);
                setLongiIdoso(p->idoso, longi);

                fscanf(arquivoEntrada, "%d", &caiu);
                setCaiuIdoso(p->idoso, caiu);
                
                
            }
            
            fclose(arquivoEntrada);
            p = p->prox; 
        }

        RegistraInfosIdosos(listaIdosos);
        i++;

    }
}

void RegistraInfosIdosos(Lista_I* listaIdosos){
    
    char diretorio[100];
    Celula_I* p = NULL;
    Celula_I* aux = NULL;
    
    p = listaIdosos->Prim;

    while(p!=NULL){
        
        sprintf(diretorio, "saidas/%s-saida.txt", getNomeIdoso(p->idoso));
        FILE* arquivoSaida = fopen(diretorio, "a");

        //falecimento
        if (getFaleceuIdoso(p->idoso)) {

            fprintf(arquivoSaida, "falecimento\n");
            
            aux=p->prox;
            MataIdoso(p->idoso, listaIdosos);
            p=aux;
            fclose(arquivoSaida);
            continue;
        
        //queda
        } else if (getCaiuIdoso(p->idoso)) {
            
            fprintf(arquivoSaida, "queda");
            AcionaCuidadorMaisProximo(getLatIdoso(p->idoso), getLongiIdoso(p->idoso), getCuidadoresIdoso(p->idoso), arquivoSaida);
            setCaiuIdoso(p->idoso, 0);
            if (getTempIdoso(p->idoso)>=38) setFebreSeguidasIdoso(p->idoso, 0);

        //febre alta
        } else if (getTempIdoso(p->idoso)>=38) {

            fprintf(arquivoSaida, "febre alta");
            AcionaCuidadorMaisProximo(getLatIdoso(p->idoso), getLongiIdoso(p->idoso), getCuidadoresIdoso(p->idoso), arquivoSaida);
            setFebreSeguidasIdoso(p->idoso, 0);

        } else {
            

            //febre baixa
            if (getTempIdoso(p->idoso)>=37 && getTempIdoso(p->idoso)<38) {

                //4 febres baixas seguidas 
                if (getFebreSeguidasIdoso(p->idoso)>=4) {
                    
                    fprintf(arquivoSaida, "febre baixa pela quarta vez");
                    AcionaCuidadorMaisProximo(getLatIdoso(p->idoso), getLongiIdoso(p->idoso), getCuidadoresIdoso(p->idoso), arquivoSaida);
                    setFebreSeguidasIdoso(p->idoso, 0);

                } else{

                    fprintf(arquivoSaida, "febre baixa");
                    AcionaAmigoMaisProximo(getLatIdoso(p->idoso), getLongiIdoso(p->idoso), getAmigosIdoso(p->idoso), arquivoSaida);

                }

            //tudo ok
            } else {
                fprintf(arquivoSaida, "tudo ok\n");
            }
        }

        fclose(arquivoSaida);
        p=p->prox;
    }

}

void MataIdoso(Idoso* idoso, Lista_I* listaIdosos) {

    Celula_I* p;
    Idoso* aux;

    /* desfazendo a rede de amizade com o idoso que faleceu */
    for (p = listaIdosos->Prim ; p != NULL; p = p->prox) {

        /* para qualquer idoso diferente do idoso que morreu */
        if (strcmp(getNomeIdoso(p->idoso), getNomeIdoso(idoso))) {
            /* vendo se tinha ele como amigo */
            aux = ProcuraNomeIdosoLista(getAmigosIdoso(p->idoso), getNomeIdoso(idoso));
            if (aux != NULL) {
                RetiraIdosoLista(getAmigosIdoso(p->idoso), getNomeIdoso(idoso), 0); // nome como chave de procura
            }
        }
    }

    RetiraIdosoLista(listaIdosos, getNomeIdoso(idoso), 1);
}

void RetiraIdosoLista(Lista_I* lista, char* nome, int destroiIdoso) {
    Celula_I* p = lista->Prim;
    Celula_I* ant = NULL; 
    Idoso* idoso;

    while (p != NULL && strcmp(getNomeIdoso(p->idoso), nome)) {
        ant = p; // incremento
        p = p->prox;
    }

    if (p == NULL) { // não encontrou o idoso ou a lista está vazia
        return;
    }

    idoso = p->idoso; NULL;
        

    if (lista->Prim == lista->Ult) { // lista com só 1 idoso
        // lista volta a ficar vazia
        lista->Prim = lista->Ult = NULL;

    } else if (lista->Prim == p) { // primera célula
        lista->Prim = p->prox;

    } else if (lista->Ult == p) { // última célula
        lista->Ult = ant;
        ant->prox = NULL;

    } else { // célula no meio da lista
        ant->prox = p->prox;
    }

    if (destroiIdoso) DestroiIdoso(idoso);
    free(p);
}

void AcionaAmigoMaisProximo(double lat, double longi, Lista_I* listaAmigos, FILE* f) {

    Idoso* idosoMaisProx = NULL;
    Celula_I* p = NULL;
    double dist = 0, minDist = -1, x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    for (p = listaAmigos->Prim; p != NULL; p = p->prox) {

        if (getFaleceuIdoso(p->idoso)) continue;

        x1 = lat;
        y1 = longi;
        x2 = getLatIdoso(p->idoso);
        y2 = getLongiIdoso(p->idoso);

        dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

        //se for o primeiro amigo válido, então a menor distancia já sera dele
        if (minDist==-1) {
            minDist = dist;
            idosoMaisProx = p->idoso;

        } else {
            if (dist < minDist) {
                minDist = dist;
                idosoMaisProx = p->idoso;
            }
        }
    }
    
    if (minDist==-1) fprintf(f, " mas, infelizmente, o idoso está sem amigos na rede\n");
    else fprintf(f, ", acionou amigo %s\n", getNomeIdoso(idosoMaisProx));

}