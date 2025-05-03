#include<stdio.h>
#include<stdlib.h>
float** criar(int linha,int coluna);
void preencher(float** matriz , int linha, int coluna);
void imprimir(float** matriz, int linha , int coluna);
void liberar(float** matriz , int linha);

// atividade matriz (transposta, soma, subtracao e produto)
float** transposta(float** matriz, int linha , int coluna);
float** matriz_operacao( int linha, int coluna, char op); 

int main(void){

   int l,c; // linhas e colunas
   printf("Digite a quantidade de linhas: ");
   scanf("%d", &l);
   printf("quantidade de colunas:");
   scanf("%d",&c);

   if(l<1 || c<1){
    printf("digite valores acima de 0\n");
    return 1;
   } 

    float** matriz=criar(l,c);
    if(!matriz){   
         printf("erro ao criar a matriz\n");
         liberar(matriz,l);
         return 1;
    }
   
    printf("preenchendo a matriz\n");
    preencher(matriz,l,c);

    printf("MATRIZ ORIGINAL:\n");
    imprimir(matriz,l,c);

    
    float** matriz_transposta=transposta(matriz,l,c);
    if(!matriz_transposta){
        printf("erro ao criar a matriz transposta\n");
        liberar(matriz,l);
        exit(1);
    }
    printf("MATRIZ TRANSPOSTA:\n");
    imprimir(matriz_transposta,c,l);

    printf("MATRIZ DE OPERACAO ESCOLHA:\n SOMA(+), SUB(-), MULTI(*) e DIVI(/)\n");
    char op;
    scanf(" %c",&op);

    while(op!='+' && op!='-' && op!='*' && op!='/'){
        printf("invalido digite novamente\n");
        scanf(" %c",&op);       
    }

    float** matriz_resultado=matriz_operacao(l,c,op);
    if(!matriz_resultado){
        printf("erro ao criar a matriz resultado\n");
        liberar(matriz,l);
        exit (1);
    }
    printf("MATRIZ RESULTADO:\n");
    imprimir(matriz_resultado,l,c);
    
    liberar(matriz_transposta,c);
    liberar(matriz,l);
    liberar(matriz_resultado,l);
    return 0;
}

float** criar(int linha,int coluna){
  
    float** matriz=(float**)malloc(linha *sizeof(float*));
    if(!matriz){
        printf("erro de alocacao de memoria\n");
        exit(1);
    }
    for(int i=0;i<linha;i++){  
     
        matriz[i]=(float*)malloc(coluna * sizeof(float));
        if(!matriz[i]){
            printf("erro de alocacao\n");
            exit(1);
        }
    }
    return matriz;
}
void preencher(float** matriz , int linha, int coluna){
for( int i=0;i<linha;i++){
    for(int j=0;j<coluna;j++){
        printf(" [%d][%d]= ",i,j);
        scanf("%f",&matriz[i][j]);
    }
}
}

float** transposta(float** matriz, int linha, int coluna){   
    
    float** matriz_t=(criar(coluna,linha));
    if(!matriz_t){
        printf("erro de alocacao de memoria\n");
        exit(1);
    }
    for( int i = 0;i<coluna;i++){
        for(int j = 0; j<linha;j++){
            matriz_t[i][j]=matriz[j][i];
        }
    }
    return matriz_t;
}

float** matriz_operacao(int linha , int coluna, char op){
float** matriz_a=(criar(linha,coluna));
if(!matriz_a){
    printf("erro de alocacao\n");
    exit(1);
}

printf("MATRIZ A:\n");
preencher(matriz_a,linha,coluna);
imprimir(matriz_a,linha,coluna);

printf("MATRIZ B:\n");
float** matriz_b=(criar(linha,coluna));
if(!matriz_b){
    printf("erro de alocacao\n");
    exit(1);
}

preencher(matriz_b,linha,coluna);
imprimir(matriz_b,linha,coluna);

float** matriz_resultado=(criar(linha,coluna));
if ((!matriz_resultado)){
    printf("erro de alocacao\n");
    exit(1);
}

switch (op){
    case '+':
    for ( int i =0 ; i < linha; i++){
         for ( int j = 0 ; j < coluna ; j++){
            matriz_resultado[i][j]= matriz_a[i][j] + matriz_b[i][j];
         }
    }
    return matriz_resultado;
    
    case'-':
    for ( int i = 0; i < linha; i++){
        for(int j= 0 ; j< coluna ; j++){
            matriz_resultado[i][j] = matriz_a[i][j] - matriz_b[i][j];
        }
    }
    return matriz_resultado;
    
    case'*' :
    
    for( int i = 0; i < linha; i++){
        for( int j=0; j< coluna ;j++){
            matriz_resultado[i][j]= matriz_a[i][j] * matriz_b[i][j];
        }
    }
    return matriz_resultado;
    
    case'/':
    for(int i = 0 ; i< linha; i++){
        for( int j=0; j< coluna; j++){
            if(matriz_b[i][j]==0){
                printf("ouve uma divisao por 0 na [%d][%d]\n",i,j);
                matriz_resultado[i][j]=0;
                // o valo que divisao e invalida vai volta 0
            }
            else{
                matriz_resultado[i][j]= matriz_a[i][j] / matriz_b[i][j];
            }
        }
    }
    return matriz_resultado;
}

liberar(matriz_a,linha);
liberar(matriz_b,linha);
}

void imprimir(float** matriz, int linha , int coluna){
    for(int i=0;i<linha;i++){
     for(int j=0;j<coluna;j++)
     {
    printf("[%d][%d]=[%.2f]",i,j,matriz[i][j]);
  }   
  printf("\n");
 }
}
void liberar(float** matriz, int linha){
    for( int i = 0; i < linha ; i++){
    free(matriz[i]);
    }
    free(matriz);
}