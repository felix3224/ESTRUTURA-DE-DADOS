#include "TAD_LISTA.h"
#include<stdio.h>
#include<stdlib.h>

Lista* lst_cria(void)
{
return NULL;
}

Lista* lst_insere(Lista* l, int i)
{
Lista* new=(Lista*)malloc(sizeof(Lista));

if(!new){
    printf("erro de alocacao de memori");
    exit(1);
}

new->info=i;  // valor atrbuido
new->prox=l; // a ponta para a lista anterio pq ele foi inserido antes dela

return new;
}   

void lst_imprime(Lista* l)
{
    Lista* p;

    for( p=l; p != NULL;  p = p->prox)
    {
    printf(" infor:%d\n",p->info);
    }
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int lst_vazia (Lista* l)
{
    return (l==NULL);
}

Lista* lst_busca(Lista* l, int v)
{
    Lista* p;

    for(p=l; p != NULL && p->info <= v; p=p->prox){
        if(p->info == v )
        return p;
    }
    return NULL; //Nao encontrou o elemento
}
    
/* função retira: retira elemento da lista */
Lista* lst_retira (Lista* l, int v)
{
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l;      /* ponteiro para percorrer a lista */

    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    /* verifica se achou elemento */
    if (p == NULL)
        return l; /* não achou: retorna lista original */

    /* retira elemento */
    if (ant == NULL) {
        /* retira elemento do início */
        l = p->prox;
    }
    else {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

void lst_libera (Lista* l)
{
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox; /* guarda referência p/ próx. elemento */
        free(p);            /* libera a memória apontada por p */
        p = t;              /* faz p apontar para o próximo*/
     }
    }

// função insere_ordenado: insere elemento em ordem
Lista* lst_insere_ordenado(Lista* l, int v) {
    Lista* novo;
    Lista* ant = NULL; // ponteiro para elemento anterior
    Lista* p = l;      // ponteiro para percorrer a lista

    // procura posição de inserção
    while (p != NULL && p->info < v) {
        ant = p;
        p = p->prox;
    }

    // cria novo elemento
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;

    // encadeia elemento
    if (ant == NULL) { // insere elemento no início
        novo->prox = l;
        l = novo;
    } else { // insere elemento no meio da lista
        novo->prox = p;
        ant->prox = novo;
    }
    return l;
}

Lista* lst_remove_duplicatas(Lista* l){
    Lista* p=NULL;
    Lista* atual=l;
    Lista* ant=NULL;

    while(atual != NULL){
        p = atual->prox;
        ant=atual;
        while(p != NULL){
            
            if(atual->info == p->info){
                
                ant->prox=p->prox;
                free(p);
                p=ant->prox;
            }else{
                ant=p;
                p= p->prox;
            }
        }
        atual= atual->prox;
    }
    return l;
}

 int lst_maiores(Lista* l, int n){
    int i=0;

    while(l != NULL){
        if( l->info > n)
        i++;
        l= l->prox;
    }
    return i;
}

int lst_comprimento(Lista* l){
    int i=0;

    while(l != NULL){
        i++;
        l= l ->prox;
    }
    return i;
}

Lista* lst_ultimo(Lista* l){
    Lista* ant=NULL;

    while(l != NULL){
        ant=l;
        l=l->prox;
    }
    return ant;
}

Lista* lst_concatena(Lista* l1, Lista* l2){
    Lista* ulti = lst_ultimo(l1);
    ulti->prox=l2;

    return l1;
}
Lista* lst_retira_n(Lista* l, int n){
    Lista* ant=NULL;
    Lista* p=l;

    while(p != NULL){
        if(p->info == n){
            if(ant == NULL){
                l=p->prox;
                free(p);
                p=l;
            }else{
                ant->prox = p->prox;
                free(p);
                p=ant->prox;
            }
        }
        else{
            ant=p;
            p= p->prox;
        }
    }
    return l;
}

Lista* lst_separa(Lista* l, int n){
    
    Lista* p = l;

    while(p != NULL && p->info != n){
        p=p->prox;
    }
    if(p==NULL)
    return NULL;   

    Lista* nov=p->prox;
    p->prox= NULL;
    return nov;
}

Lista* lst_merge(Lista* l1, Lista* l2){
   Lista* p1=l1;
   Lista* p2= l2;

   Lista* nova_lista=NULL;
   Lista* fim=NULL;

   while(p1 != NULL || p2 != NULL){
    if(p1 != NULL){
        Lista* new=(Lista*)malloc(sizeof(Lista));
        new->info = p1->info;
        new->prox = NULL;

        if(nova_lista== NULL){
            nova_lista=new;
            fim       = new;
        }else{
            fim->prox= new;
            fim= fim->prox;
        }
        p1=p1->prox;
    }
    if(p2 != NULL){
        Lista* new=(Lista*)malloc(sizeof(Lista));
        new->info=p2->info;
        new->prox=NULL;

        if(nova_lista == NULL){
            nova_lista = new;
                   fim = new;
        }else{
            fim->prox=new;
            fim= fim->prox;
        }
        p2= p2->prox;
    }
   }
   return nova_lista;
}

Lista* lst_inverte(Lista* l){
    Lista* ant= NULL;
    Lista* atual= l;
    Lista* p=NULL;

    while(atual != NULL){
        p=atual->prox;
        atual->prox=ant;
        ant=atual;

        atual=p;
    }
    return ant;
}
int lst_igual(Lista* l1, Lista* l2){
   
    while( l1!=NULL && l2!=NULL){
        if(l1->info != l2->info)
        return 0;
        l1=l1->prox;
        l2=l2->prox;
    }
    return l1==l2;
}

Lista* lst_copy(Lista* l) {
    if (l == NULL) {
        return NULL; // Retorna NULL se a lista de entrada estiver vazia
    }

    // Cria um novo nó para a cabeça da lista copiada
    Lista* novo = (Lista*)malloc(sizeof(Lista));

    novo->info = l->info; // Copia a informação do primeiro nó
    novo->prox = NULL; // Inicializa o próximo como NULL

    Lista* fim = novo; // Ponteiro para o último nó na nova lista
    Lista* p = l->prox; // Ponteiro para percorrer a lista original

    while (p != NULL) {
        Lista* nova = (Lista*)malloc(sizeof(Lista)); // Cria um novo nó
    
        nova->info = p->info; // Copia a informação do nó atual
        nova->prox = NULL; // Inicializa o próximo como NULL

        fim->prox = nova; // Liga o novo nó ao final da nova lista
        fim = fim->prox; // Move o ponteiro para o último nó na nova lista

        p = p->prox; // Move para o próximo nó na lista original
    }

    return novo; // Retorna a cabeça da lista copiada
}

/*ESSA LISTA E PRA COPIAR CARACTER*/

Li_STR* lst_copy_str(Li_STR* l){
    if (l == NULL) {
        return NULL; 
    }
    
    Li_STR* novo=(Li_STR*)malloc(sizeof(Li_STR));
    int i;
    for(i=0; l->str[i] != '\0';i++ ){
        novo->str[i] = l->str[i];
    }
    novo->str[i]='\0';
    Li_STR* fim=novo;
    Li_STR* p= l->prox;
    

    while(p != NULL){
        Li_STR* nova=(Li_STR*)malloc(sizeof(Li_STR));

        for( i=0; p->str[i] != '\0'; i++)
        nova->str[i] = p->str[i];
        
         nova->prox = NULL;

        nova->str[i]='\0';
        fim->prox=nova;
        fim=nova;
    
    p=p->prox;
}
return novo;
}

int lst_igual_str(Li_STR* l1,Li_STR* l2){
    
    while(l1 != NULL && l2 != NULL){

        int i=0;
        while(l1->str[i] != '\0' ||  l2->str[i] != '\0'){
        if(l1->str[i] != l2->str[i])
        return 0;
        i++;  
        }
        
        l1=l1->prox;
        l2=l2->prox;
    }

    if(l1==NULL && l2==NULL)
    return 1;
    else
    return 0;
}

Lista* oredem_crescente(Lista* l){
    
    Lista* atual = l;
    Lista* p=NULL;

    while(atual != NULL){
        p=atual->prox;

        while(p != NULL){
            if(atual->info > p->info){
                float aux=atual->info;
                atual->info=p->info;
                p->info=aux;
            } 
                p=p->prox;       
        }
    atual=atual->prox;
    }
    return l;
}

Lista* lst_remove_todos_menores(Lista* l, int n) {
    Lista* ant = NULL;
    Lista* p = l;

    while (p != NULL) {
        if (p->info < n) {
            
            if (ant == NULL) {
                l = p->prox;
                free(p);
                p = l;
            } else {
                ant->prox = p->prox;
                free(p);
                p = p->prox;
            }
        } else {
            ant = p;
            p = p->prox;
        }
    }
    return l;
}

Lista* lst_intersecao(Lista* l1, Lista* l2) {
    Lista* novo = NULL;
    Lista* fim=NULL;
   

    for (Lista* p1 = l1; p1 != NULL; p1 = p1->prox) {
        for (Lista* p2 = l2; p2 != NULL; p2 = p2->prox) {
            if (p1->info == p2->info) {
                // evita duplicados
                Lista* busca = lst_busca(novo, p1->info);
                if (busca == NULL){
                   Lista* new=(Lista*)malloc(sizeof(Lista));
                   new->info=p1->info;
                   new->prox=NULL;

                   if(novo== NULL){
                     novo=new;
                     fim=new;
                  }else{
                    fim->prox=new;
                    fim=fim->prox;
                  }
                }
                break;
            }
        }
    }
    return novo;
}

Lista* lst_copy(Lista* l, int n) {
    if (l == NULL) {
        return NULL; // Retorna NULL se a lista de entrada estiver vazia
    }

    // Cria um novo nó para a cabeça da lista copiada
    Lista* novo = NULL;

   
    Lista* fim = NULL; // Ponteiro para o último nó na nova lista
    Lista* p = l; // Ponteiro para percorrer a lista original

    while (p != NULL && p->info < n) {
        
        Lista* new = (Lista*)malloc(sizeof(Lista)); // Cria um novo nó
    
        new->info = p->info; // Copia a informação do nó atual
        new->prox = NULL; // Inicializa o próximo como NULL

        if(novo==NULL){
            novo=new;
            fim=new;
        }else{
        fim->prox = new; // Liga o novo nó ao final da nova lista
        fim = fim->prox; // Move o ponteiro para o último nó na nova lista
        }
    
        p = p->prox; // Move para o próximo nó na lista original
    }
return novo;
}

    Lista* p1=NULL;
    Lista* atual=novo;
    Lista* ant=NULL;

    while(atual != NULL){
        p1=atual->prox;
        atual->prox= ant;
        ant= atual;

        atual=p1;
    }
    return ant;
}