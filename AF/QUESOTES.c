#include<stdio.h>
#include<stdlib.h>
//#include "TAD_LIST/TAD_LISTA.h"

 struct aluno{
    char nome[20];
    char matri[10];
    float nota[3];

    struct aluno* prox;
};
typedef struct aluno Aluno;

Aluno* inserir(int n);
void aluno_passou(Aluno* l);
Aluno* copy_aluno_repro(Aluno* l);
void libera(Aluno* l);

int main(){

    Aluno* test=NULL;

    test=inserir(3);
    aluno_passou(test);
    Aluno* test2=copy_aluno_repro(test);
    aluno_passou(test2);

    libera(test2);
    libera(test);
    return 0;
}

Aluno* inserir(int n){
   Aluno* ini=NULL;
   Aluno* fim=NULL;

   for(int i=0; i<n; i++){
    Aluno* novo=(Aluno*)malloc( sizeof(Aluno));
   
    printf("informe nome:");
    scanf(" %29[^\n]", novo->nome);
    printf("informe matricula:");
    scanf(" %29[^\n]", novo->matri);
    
    for(int k=0; k<3;k++){
        printf("informe 3 nota:  ");
        scanf("%f",&novo->nota[k]);
    }
    novo->prox=NULL;

    if(ini == NULL){
        ini=novo;
        fim=novo;
    }else{
        fim->prox=novo;
        fim=novo;
    }
}
return ini;
}

void aluno_passou(Aluno* l){
    
    float media;
    while(l != NULL){

        media=0;
        for(int i=0; i<3; i++)
            media+= l->nota[i];
        
        media /= 3;
        if(media >= 7){
            printf("aprovado\n");
            printf("nome:¨%s\n",l->nome);
            printf("matri:¨%s\n",l->matri);
            printf("medeia:%.2f\n",media);    
        }
           l=l->prox; 
    }
}


Aluno* copy_aluno_repro(Aluno* l){
    Aluno* p=l;
    Aluno* ini=NULL;
    Aluno* fim=NULL;
    
    
    int media;
    

    while(p != NULL){
        media=0;
        for(int i=0; i<3; i++)
        media+= p->nota[i];

        media/=3;

         Aluno* rep=(Aluno*)malloc(sizeof(Aluno));

        if(media<7){
            int i=0;
          
           for( i=0; p->nome[i]!='\0';i++)
           rep->nome[i]=p->nome[i];
           rep->nome[i]='\0';
           
           int k=0;
           for(k=0; p->matri[k]!='\0';k++)
           rep->matri[k]=p->matri[k];
           rep->matri[k]='\0';

           for(int j=0; j<3; j++)
           rep->nota[j]=p->nota[j];

           rep->prox=NULL;
        }
        if(ini==NULL){
            ini=rep;
            fim=rep;
        }else{
            fim->prox=rep;
            fim=rep;
        }
         p=p->prox;
    }
return ini;
}
void libera(Aluno* l){
    Aluno* aux;
    while(l != NULL){
        aux=l->prox;
        free(l);
        l=aux;
    }
}