#ifndef _TAD_LISTA_
 #define _TAD_LISTA_

//Estrutura exportada
 struct lista{
    int info;
    struct lista* prox;
};
struct lis_str{
    char str[10];
    struct lis_str* prox;
};
 /* TAD: lista de inteiros */
typedef struct lista Lista;
typedef struct lis_str Li_STR;


Lista* lst_cria (void);
  void lst_libera (Lista* l);

Lista* lst_insere (Lista* l, int i);
Lista* lst_retira (Lista* l, int v);

   int lst_vazia (Lista* l);
Lista* lst_busca (Lista* l, int v);
  void lst_imprime (Lista* l);

Lista* lst_insere_ordenado(Lista* l, int v);
Lista* lst_remove_duplicatas(Lista* l);
   int lst_maiores(Lista* l, int n);
   int lst_comprimento(Lista* l);
Lista* lst_ultimo(Lista* l);
Lista* lst_concatena(Lista* l1, Lista* l2);
Lista* lst_retira_n(Lista* l, int n); 
Lista* lst_separa(Lista* l, int n);
Lista* lst_merge(Lista* l1, Lista* l2); //OK
Lista* lst_inverte(Lista* l); 
Lista* lst_copy(Lista* l);             //
int lst_igual(Lista* l1, Lista* l2); 
Li_STR* lst_copy_str(Li_STR* l);//copiar de lista de caracteres
int lst_igual_str(Li_STR* l1,Li_STR* l2);

#include "TAD_LISTA.c"
#endif   