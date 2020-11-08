
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "filaEncadeada.h"
// #include "filaEncadeada.c"

// protótipo da função que cria um dado
int criar_dado(int *dado);
int criar_fila_se(Fila *SE, int limite);

// funcao principal
int main(void)
{

  // no início a fila está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da fila
  Fila *SE = NULL, *XP = NULL, *XC = NULL, *NP = NULL, *NC = NULL, *fi = NULL;
  int opcao, ok;
  int dado, limite;
  char perfil, tipo;

  // menu de opções para execuções de operações sobre a fila
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar filas");
    printf("\n2 - Liberar filas");
    printf("\n3 - Retirar senha");
    // printf("\n4 - Remover senha");
    printf("\n5 - Consultar primeiro elemento da fila");
    printf("\n6 - Imprimir filas");
    printf("\n7 - Chamar próxima senha");
    printf("\n8 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:

      // criar fila
      XP = criar_fila();
      XC = criar_fila();
      NP = criar_fila();
      NC = criar_fila();
      SE = criar_fila();

      if (XP != NULL && XC != NULL && NP != NULL && NC != NULL)
      {
        printf("\n Digite o limite de senhas: ");
        scanf("%d", &limite);
        ok = criar_fila_se(SE, limite);

        printf("\n Filas criadas com sucesso!");
      }
      else
      {
        printf("\n Filas não criadas!");
      }
      break;

    case 2:

      // liberar fila
      ok = liberar_fila(XP);
      ok = liberar_fila(XC);
      ok = liberar_fila(NP);
      ok = liberar_fila(NC);
      ok = liberar_fila(SE);

      if (ok)
      {
        printf("\n Filas liberadas com sucesso!");
      }
      else
      {
        printf("\n Filas não liberadas!");
      }
      break;

    case 3:

      // enfileirar elemento
      printf("\nDigite seu tipo de atendimento: \n(X - Caixa, N - Negocial) \nInsira(X/N): ");
      scanf(" %c", &tipo);
      printf("\nDigite seu perfil de cliente: \n(P - Preferencial, C - Convencional) \nInsira(C/P): ");
      perfil = getc(stdin);
      scanf(" %c", &perfil);

      consultar_inicio_fila(SE, &dado);

      if ((tipo == 'X' || tipo =='x' ) && (perfil == 'C' || perfil == 'c'))
      {
        ok = enfileirar(XC, dado);
        printf("\nFila XC: ");
        imprimir_fila(XC, "XC");
      }
      else if ((tipo == 'X' || tipo =='x' ) && (perfil == 'P' || perfil == 'p'))
      {
        ok = enfileirar(XP, dado);
        printf("\nFila XP: ");
        imprimir_fila(XP, "XP");
      }
      else if ((tipo == 'N' || tipo =='n' ) && (perfil == 'C' || perfil == 'c'))
      {
        ok = enfileirar(NC, dado);
        printf("\nFila NC: ");
        imprimir_fila(NC, "NC");
      }
      else if ((tipo == 'N' || tipo =='n' ) && (perfil == 'P' || perfil == 'p'))
      {
        ok = enfileirar(NP, dado);
        printf("\nFila NP: ");
        imprimir_fila(NP, "NP");
      }
      else
      {
        printf("Erro ao fazer verificação! Tente novamente");
      }

      if (ok == 1)
      {
        printf("\n Inserção realizada com sucesso!");
        ok = desenfileirar(SE);
      }
      else
      {
        printf("\n Falha na inserção!");
      }

      break;

    case 4:

      // desenfileirar elemento
      // ok = desenfileirar(fi);

      // if (ok == 1)
      // {
      //   printf("\n Remoção realizada com sucesso!");
      // }
      // else
      // {
      //   printf("\n Falha na remoção!");
      // }
      // break;

    case 5:

      ok = consultar_inicio_fila(fi, &dado);

      if (ok)
      {
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento no início da fila: ");
        printf("%d", dado);
      }
      else
      {
        printf("\n Fila vazia!");
      }

      break;

    case 6:
      imprimir_fila(SE, "SE");
      imprimir_fila(XP, "XP");
      imprimir_fila(XC, "XC");
      imprimir_fila(NP, "NP");
      imprimir_fila(NC, "NC");

      break;

    case 7:
      ok = chamar_senha(XP, XC, NP, NC);
      break;

    case 8:

      // libera memória e finaliza programa
      liberar_fila(fi);
      liberar_fila(SE);
      liberar_fila(XP);
      liberar_fila(XC);
      liberar_fila(NP);
      liberar_fila(NC);

      printf("\nFinalizando...");
      break;

    default:
      printf("\nOpção inválida!");
      break;
    }

  } while (opcao != 8);

  return 0;
}

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