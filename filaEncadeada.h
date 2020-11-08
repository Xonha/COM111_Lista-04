// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _FILA
#define _FILA

typedef struct descritor Fila;               

// funções para alocar e desalocar memória
Fila* criar_fila();                        
int liberar_fila(Fila *fi);   

// função para obter informação da fila
int tamanho_fila(Fila *fi);      

// funções para enfileirar e desenfileirar elementos da fila
int enfileirar(Fila *fi, int dado);        
int desenfileirar(Fila *fi);               

// função para consultar elemento no início da fila
int consultar_inicio_fila(Fila *fi, int *dado); 

// novas funcoes da lista
void imprimir_fila(Fila *fi, char * prefix);
int chamar_proxima_senha(Fila *XP, Fila *XC, Fila *NP, Fila *NC, Fila *SE);

#endif 