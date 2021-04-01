#include "Fila.h"

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, struct Drone drone);
int remove_ArvAVL(ArvAVL *raiz, struct Drone valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, int valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);
int imprime_arvore(ArvAVL *raiz, int i);

/*
// Rota��o a esquerda
void leftRotate(arvore *x);
// Rota��o a direita
void rightRotate(arvore *x);
// Realiza as rota��es necess�rias avaliando os fatores de balanceamento, em caso de rota��o dupla atualiza o balanceamento do n� que desbalanceou dependendo do valor do neto
void balanceamento(arvore *no);
//atualiza o FB at� chegar na raiz ou at� realizar rota��es
void atualizaBal(arvore *no,float num);
// Realiza as rota��es necess�rias avaliando os fatores de balanceamento e atualiza o FB dos envolvidos em rota��es tanto simples quanto dupla
void balanceamentoRemocao(arvore * no);
//atualiza o FB at� chegar na raiz, ou encontrar o FB = 1 ou -1 do n� que desbalanceou a �rvore ap�s o balanceamento desta
void atualizaBalRemocao(arvore *no,float num);
#endif	/* AVL_H */

