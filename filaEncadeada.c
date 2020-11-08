// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>

#include "filaEncadeada.h"

int ctrlPerfil = 2;

//criando elemento
struct elemento{
    int dado;
    struct elemento *prox;
};

//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    Elemento *inicio;
    Elemento *fim;
    int quant;
};


// função para alocar memória do tipo Fila
Fila* criar_fila()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->quant = 0;
    }
    return fi;
}

// função para liberar memória
int liberar_fila(Fila *fi)
{

  if(fi == NULL){    
    return 0;
  }

  Elemento *atual;

  while(fi->inicio != NULL){    
    atual = fi->inicio;
    fi->inicio = fi->inicio->prox;
    fi->quant--;
    free(atual);
  }

  free(fi);  

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
    return (Elemento*) malloc(sizeof(Elemento));
}


// função para inserir elemento no final da fila 
int enfileirar(Fila *fi, int dado)
{
  if(fi == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = NULL;

  // se a fila estiver vazia, insere no início da fila
  if(fi->inicio == NULL){    
    fi->inicio = no;  

  // senão insere elemento no final da fila  
  }else{
    (fi->fim)->prox = no;    
  }

  fi->fim = no;
  fi->quant++;

  return 1;
}

// função para remover elemento do início da fila
int desenfileirar(Fila *fi)
{
  if(fi == NULL){
    return 0;
  }

  // fila vazia, não remove nada
  if(fi->inicio == NULL){
    return 0;
  }

  // remove elemento do início da fila
  Elemento *no;
  no = fi->inicio;
  fi->inicio = fi->inicio->prox;
  fi->quant--;

  // libera Elemento no
  free(no);

  // se a fila ficou vazia
  if(fi->inicio == NULL){
    fi->fim = NULL;
  }

  return 1;
}

// função para consultar o primeiro elemento
int consultar_inicio_fila(Fila *fi, int *dado)
{
  // verifica se a fila foi criada corretamente e se não está vazia
  if(fi == NULL || fi->inicio == NULL){
    return 0;
  }

  // copia o dado do início da fila
  *dado = fi->inicio->dado;

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_fila(Fila *fi)
{
    if(fi == NULL){
        return -1;
    }
    return fi->quant;
}

// função que imprime a fila
void imprimir_fila(Fila *fi, char * prefix){
    if(fi != NULL && fi->inicio != NULL){
        Elemento *aux;
        aux = fi->inicio;
        printf("\nFila %s: ", prefix);
        while(aux->prox != NULL){
            printf("%s%d, ", prefix, aux->dado);
            aux = aux->prox;
        }

        printf("%s%d\n", prefix, aux->dado);
    }
}

int chamar_senha_aleatoria(Fila *XP, Fila *XC, Fila *NP, Fila *NC, Fila *SE){
  if(XP == NULL || XC == NULL || NP == NULL || NC == NULL){
    return 0;
  }

  int response;

  if(ctrlPerfil == 1 || ctrlPerfil == 2){
    if(XP->inicio == NULL && NP->inicio == NULL){
      ctrlPerfil = 0;
    }else {
      if(XP->inicio == NULL){
        printf("\nSenha: NP%d", NP->inicio->dado);
        response = desenfileirar(NP);
      }else{
        printf("\nSenha: XP%d", XP->inicio->dado);
        response = desenfileirar(XP);
      }

      ctrlPerfil--;
      return 1;
    }
  }else if(ctrlPerfil == 0){
    if(XC->inicio == NULL){
      printf("\nSenha: NC%d", NC->inicio->dado);
      response = desenfileirar(NC);
    }else{
      printf("\nSenha: XC%d", XC->inicio->dado);
      response = desenfileirar(XC);
    }

    ctrlPerfil = 2;

  }else{
    ctrlPerfil = 2;
  }

  return 1;
}

