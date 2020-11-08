// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>

#include "filaEncadeada.h"

int ctrlPerfil = 2;
int qtdXP = 0; int qtdXC = 0; int qtdNP = 0; int qtdNC = 0;

//criando elemento
struct elemento
{
  int dado;
  struct elemento *prox;
};

//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor
{
  Elemento *inicio;
  Elemento *fim;
  int quant;
};


int criar_dado(int *dado)
{
  printf("\nDigite um número inteiro: ");
  scanf("%d", dado);

  return 1;
}

int criar_fila_se(Fila *SE, int limite)
{
  int ignore;

  for (int i = 0; i < limite; i++)
  {
    ignore = enfileirar(SE, i + 1);
  }

  return ignore;
}

// função para alocar memória do tipo Fila
Fila *criar_fila()
{
  Fila *fi = (Fila *)malloc(sizeof(Fila));
  if (fi != NULL)
  {
    fi->inicio = NULL;
    fi->fim = NULL;
    fi->quant = 0;
  }
  return fi;
}

// função para liberar memória
int liberar_fila(Fila *fi)
{

  if (fi == NULL)
  {
    return 0;
  }

  Elemento *atual;

  while (fi->inicio != NULL)
  {
    atual = fi->inicio;
    fi->inicio = fi->inicio->prox;
    fi->quant--;
    free(atual);
  }

  free(fi);

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento *criar_elemento()
{
  return (Elemento *)malloc(sizeof(Elemento));
}

// função para inserir elemento no final da fila
int enfileirar(Fila *fi, int dado)
{
  if (fi == NULL)
  {
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if (no == NULL)
  {
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = NULL;

  // se a fila estiver vazia, insere no início da fila
  if (fi->inicio == NULL)
  {
    fi->inicio = no;

    // senão insere elemento no final da fila
  }
  else
  {
    (fi->fim)->prox = no;
  }

  fi->fim = no;
  fi->quant++;

  return 1;
}

// função para remover elemento do início da fila
int desenfileirar(Fila *fi)
{
  if (fi == NULL)
  {
    return 0;
  }

  // fila vazia, não remove nada
  if (fi->inicio == NULL)
  {
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
  if (fi->inicio == NULL)
  {
    fi->fim = NULL;
  }

  return 1;
}

// função para consultar o primeiro elemento
int consultar_inicio_fila(Fila *fi, int *dado)
{
  // verifica se a fila foi criada corretamente e se não está vazia
  if (fi == NULL || fi->inicio == NULL)
  {
    return 0;
  }

  // copia o dado do início da fila
  *dado = fi->inicio->dado;

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_fila(Fila *fi)
{
  if (fi == NULL)
  {
    return -1;
  }
  return fi->quant;
}

// função que imprime a fila
void imprimir_fila(Fila *fi, char *prefix)
{
  if (fi != NULL && fi->inicio != NULL)
  {
    Elemento *aux;
    aux = fi->inicio;
    printf("\nFila %s: ", prefix);
    while (aux->prox != NULL)
    {
      printf("%s%d, ", prefix, aux->dado);
      aux = aux->prox;
    }

    printf("%s%d\n", prefix, aux->dado);
  }
}

int usuarios_atendidos_fila(Fila *XP, Fila *XC, Fila *NP, Fila *NC, Fila *SE){
  if(XP->quant == 0 && XC->quant == 0 && NP->quant == 0 && NC->quant == 0 && SE->quant == 0){
    printf("\nFila XP atendeu %d clientes\n", qtdXP);
    printf("\nFila XC atendeu %d clientes\n", qtdXC);
    printf("\nFila NP atendeu %d clientes\n", qtdNP);
    printf("\nFila NC atendeu %d clientes\n", qtdNC);

    return 1;
  }

  return 0;
}

int chamar_senha(Fila *XP, Fila *XC, Fila *NP, Fila *NC)
{
  if (XP == NULL && XC == NULL && NP == NULL && NC == NULL)
    return 0;

  int value = 0;
  char * prefix = NULL; 
  int ctrlTipo = rand()%2; // 0 = negocial; 1 = caixa

  if(XP->quant == 0 && NP->quant == 0){
      ctrlPerfil = 0;
  }

  if((ctrlPerfil == 1 || ctrlPerfil == 2) && (XP->quant > 0 || NP->quant > 0)){
    if(XP->quant > 0 && ctrlTipo == 1){
      consultar_inicio_fila(XP, &value);
      desenfileirar(XP);
      prefix = "XP";
      qtdXP++;
    }else if(NP->quant > 0 && ctrlTipo == 0){
      consultar_inicio_fila(NP, &value);
      desenfileirar(NP);
      prefix = "NP";
      qtdNP++;
    }

    ctrlPerfil--;

  }else if((ctrlPerfil == 0) && (XC->quant > 0 || NC->quant > 0)){
    if(XC->quant > 0 && ctrlTipo == 1){
      consultar_inicio_fila(XC, &value);
      desenfileirar(XC);
      prefix = "XC";
      qtdXC++;
    }else if(NC->quant > 0 && ctrlTipo == 0){
      consultar_inicio_fila(NC, &value);
      desenfileirar(NC);
      prefix = "NC";
      qtdNC++;
    }

    ctrlPerfil = 2;
  }

  printf("Senha á ser atendida: %s%d", prefix, value);

  return 1;
}
