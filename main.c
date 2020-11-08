
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
  // Fila *SE = NULL, *XP = NULL, *XC = NULL, *NP = NULL, *NC = NULL;
  int opcao, ok;
  int dado, limite;
  char perfil, tipo;

  Fila *XP = criar_fila();
  Fila *XC = criar_fila();
  Fila *NP = criar_fila();
  Fila *NC = criar_fila();
  Fila *SE = criar_fila();

  printf("\n Digite o limite de senhas: ");
  scanf("%d", &limite);
  ok = criar_fila_se(SE, limite);
  if(ok){
    printf("\n Filas criadas com sucesso!");
  }else{
    printf("\n Filas não criadas!");
  }

  // menu de opções para execuções de operações sobre a fila
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Retirar senha");
    printf("\n2 - Imprimir filas");
    printf("\n3 - Chamar próxima senha");
    printf("\n4 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:

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

    case 2:
      imprimir_fila(SE, "SE");
      imprimir_fila(XP, "XP");
      imprimir_fila(XC, "XC");
      imprimir_fila(NP, "NP");
      imprimir_fila(NC, "NC");

      break;

    case 3:
      ok = chamar_senha(XP, XC, NP, NC);
      break;

    case 4:

      // libera memória e finaliza programa
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

    ok = usuarios_atendidos_fila(XP, XC, NP, NC, SE);
    if(ok){
      printf("Finalizando...");
      liberar_fila(SE);
      liberar_fila(XP);
      liberar_fila(XC);
      liberar_fila(NP);
      liberar_fila(NC);
      break;
    }

  } while (opcao != 4);

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