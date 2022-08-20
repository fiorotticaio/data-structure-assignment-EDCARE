#include <stdio.h>
#include <stdlib.h>
#include "./headers/Lista_I.h"
#include "./headers/Lista_C.h"

int main(int argc, char* argv[]) {

    


    /*===== Leitura de dados inicial =====*/

    /*====================== IDOSOS =============================================*/
    Lista_I * listaIdosos = InicializaLista_I();

    //abrindo arquivo 'apoio.txt'
    FILE * f = fopen("./entradas/apoio.txt", "r");
    
    //criando variaveis para armazenar:
    //  nomeIdoso       -> junção dos caracteres do nome do idoso
    //  caracterNome    -> cada caracter lido por vez da linha
    //  i               -> variavel indice para controle
    char nomeIdoso[100];
    char caractereNome='\0';
    int i = 0;

    //lendo cada letra da primeira linha do arquivo 'apoio.txt'
    while(fscanf(f,"%c", &caractereNome)==1){

        // caso tenha um caractere de whitespace nos nomes, então ele continua lendo ate achar outro caracetere
        while (caractereNome==' ') fscanf(f,"%c", &caractereNome);

        //caso o caracter lido seja ';' ou '\n', significa que
        //todos os caracteres do nome ja foram lidos
        if(caractereNome==';' || caractereNome=='\n' || caractereNome==' ') {
            Idoso* idoso = InicializaIdoso(nomeIdoso);    
            InsereIdosoUlt(listaIdosos, idoso);
            
            //depois q o nome foi lido e o idoso registrado, 
            //reseta-se a variavel de controle
            i=0;

            //caso seja o ultimo idoso fecha-se o while
            if (caractereNome=='\n' || caractereNome==' ') break;
        
        //caso o caracter seja diferente de ';' e '/n', significa que
        //o nome ainda está sendo lido, portanto o caracter é acrescentado
        //no nome e um \0 é adicionado ao final, para caso seja a ultima letra do nome
        } else {
            nomeIdoso[i] = caractereNome;
            nomeIdoso[i+1] = '\0';
            i++;
        }
    }
    
    // ImprimeLista_I(listaIdosos, "LISTA DE IDOSOS");

    //criando variaveis para receber os pares de amigos
    char nomeIdoso1[100];
    char nomeIdoso2[100];

    while(!feof(f)){
        //recebendo os amigos
        fscanf(f, "%[^;];%[^\n]\n", nomeIdoso1, nomeIdoso2);
        
        // printf("%s - %s\n", nomeIdoso1, nomeIdoso2);

        Idoso* a = ProcuraNomeIdosoLista(listaIdosos, nomeIdoso1);
        Idoso* b = ProcuraNomeIdosoLista(listaIdosos, nomeIdoso2);
        adicionaAmigo(a,b);
    }

    // ImprimeAmigosIdosos(listaIdosos);




    /*====================== CUIDADORES =============================================*/
    Lista_C* listaCuidadores = InicializaLista_C();

    // abrindo arquivo 'cuidadores.txt'
    FILE* f2 = fopen("./entradas/cuidadores.txt", "r");

    // criando variável para armazenar:
    // nomeCuidador       -> junção dos caracteres do nome do cuidador
    char nomeCuidador[100];
    caractereNome = '\0';
    i = 0;

    //lendo cada letra da primeira linha do arquivo 'apoio.txt'
    while (fscanf(f2,"%c", &caractereNome) == 1) {
        
        // caso tenha um caractere de whitespace nos nomes, então ele continua lendo ate achar outro caracetere
        while (caractereNome==' ') fscanf(f2,"%c", &caractereNome);

        // caso o caracter lido seja ';' ou '\n', significa que
        // todos os caracteres do nome ja foram lidos
        if (caractereNome == ';' || caractereNome == '\n') {
            Cuidador* cuidador = InicializaCuidador(nomeCuidador);    
            InsereCuidadorUlt(listaCuidadores, cuidador);
            
            // depois q o nome foi lido e o cuidador registrado, 
            // reseta-se as variaveis de controle
            i = 0;

            // caso seja o ultimo cuidador fecha-se o while
            if (caractereNome == '\n' || caractereNome == ' ') break;
        
        //caso o caracter seja diferente de ';' e '/n', significa que
        //o nome ainda está sendo lido, portanto o caracter é acrescentado
        //no nome e um \0 é adicionado ao final, para caso seja a ultima letra do nome
        } else {
            nomeCuidador[i] = caractereNome;
            nomeCuidador[i+1] = '\0';
            i++;
        }
        
    }
    
    
    //ImprimeLista_C(listaCuidadores, "LISTA DE CUIDADORES");
    
    // resetando variavel de controle para receber o nome do idoso e seus cuidadores
    nomeIdoso[0] = '\0';
    nomeCuidador[0] = '\0';
    caractereNome = '\0';
    i = 0;

    while (!feof(f2)) {
        // recebendo o idoso 
        fscanf(f2, "%[^;];", nomeIdoso);

        while (fscanf(f2, "%c", &caractereNome) == 1) {

            // caso tenha um caractere de whitespace nos nomes, então ele continua lendo ate achar outro caracetere
            while (caractereNome==' ') fscanf(f2,"%c", &caractereNome);

            if (caractereNome == ';' || caractereNome == '\n' || caractereNome == ' ') {
                Idoso* a = ProcuraNomeIdosoLista(listaIdosos, nomeIdoso);
                Cuidador* b = ProcuraNomeCuidadorLista(listaCuidadores, nomeCuidador);

                // adicionando o cuidador ao idoso
                adicionaCuidador(a, b);
                
                // depois q o nome foi lido e o cuidador registrado, 
                // reseta-se as variaveis de controle
                i = 0;

                // caso seja o ultimo cuidador fecha-se o while
                if (caractereNome == '\n' || caractereNome == ' ') break;
    
            
            //caso o caracter seja diferente de ';' e '/n', significa que
            //o nome ainda está sendo lido, portanto o caracter é acrescentado
            //no nome e um \0 é adicionado ao final, para caso seja a ultima letra do nome
            } else {
                nomeCuidador[i] = caractereNome;
                nomeCuidador[i+1] = '\0';
                i++;
            }
        }      

        if (caractereNome != '\n') { // para o último cuidador da última linha (seu final não é '\n', e sim feof)
            Idoso* a = ProcuraNomeIdosoLista(listaIdosos, nomeIdoso);
            Cuidador* b = ProcuraNomeCuidadorLista(listaCuidadores, nomeCuidador);

            // adicionando o cuidador ao idoso
            adicionaCuidador(a, b);  
        }
    }


    /*===== Programa em si =====*/

    int qtdLeituras = atoi(argv[1]);

    FazLeituraIdosos(listaIdosos, qtdLeituras);


    /*===== Liberação de memória =====*/

    DestroiLista_I(listaIdosos, 0);
    DestroiLista_C(listaCuidadores, 0);

    fclose(f); // apoio.txt
    fclose(f2); // cuidadores.txt

    return 0;
}