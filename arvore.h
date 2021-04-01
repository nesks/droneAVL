
#ifndef ARVORE_H
#define	ARVORE_H

typedef struct arvore
{
    float raiz;
    int bal;
    struct arvore *esq;
    struct arvore *dir;
    struct arvore *pai;
}arvore;

// Incializa �rvore
arvore * criaArvore();
// Insere novo n� na �rvore
void insereNo(arvore *A, float num);
// Remove n� da �rvore
void removeNo(arvore *A,float num);
// troca valores(raiz) de dois n�s
void trocaDados(arvore *a, arvore *b);
// Obter elemento da extrema direita
arvore *maisDireita(arvore *a);
// Obter elemento da extrema esquerda
arvore *maisEsquerda(arvore *a);
// Percorre �rvore em ordem
void percorreOrdem (arvore *A);
// Percorre �rvore em pr�-ordem
void percorrePreOrdem(arvore *A);


#endif	/* ARVORE_H */
