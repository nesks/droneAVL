#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0
#include "Heap.h"
#include "Fila.h"



void inicializarHeap(HEAP * h, int tamanhoMax){
  h->A = (struct Drone*) malloc(sizeof(struct Drone)*(tamanhoMax+1));
  h->tamanhoAtual = 0;
  h->tamanhoMaximo = tamanhoMax;
}

void destruirHeap(HEAP * h){
  int tamanho = h->tamanhoMaximo;
  free(h->A);
  h->tamanhoMaximo=0;
  h->tamanhoAtual=0;
}

int pai(int i){
  return i/2;
}

int filhoEsquerda(int i){
  return 2*i;
}

int filhoDireita(int i){
  return 2*i + 1;
}

/* metodo auxiliar que pressupoe que o heap para qualquer j>i estah ordenado
   porem o elemento i nao eh necessariamente maior que seus filhos           */
void maxHeapify(HEAP * h, int i){
  int esq = filhoEsquerda(i);
  int dir = filhoDireita(i);
  int temp;
  int maior = i;
  if ((esq <= h->tamanhoAtual) && (h->A[esq].peso>h->A[i].peso)) maior = esq;
  if ((dir <= h->tamanhoAtual) && (h->A[dir].peso>h->A[maior].peso)) maior = dir;
  if (maior != i) {
     temp = h->A[i].peso;
     h->A[i] = h->A[maior];
     h->A[maior].peso = temp;
     maxHeapify(h,maior);
  }
}

// Constroi heap a partir do arranjo usando o metodo maxHeapify
void construirHeapMaximo(HEAP * h){
  int i;
  int metadeTamanho = h->tamanhoAtual/2;
  for (i=metadeTamanho;i>0;i--) maxHeapify(h,i);
}

// no final do arranjo do heap
bool inserirForaDeOrdem(HEAP * h, struct Drone valor){
  if (h->tamanhoAtual < h->tamanhoMaximo){
    (h->tamanhoAtual)++;
    h->A[h->tamanhoAtual] = valor;
    return true;
  }
  return false;
}


// Imprime o arranjo (na ordem que estiver)
void imprimirArranjo(HEAP h){
  int tamanho = h.tamanhoAtual;
  int i;
  for (i=0;i<=tamanho;i++) printf("%.2f ",h.A[i].peso);
  printf("\n");
}


// Imprime elementos em ordem decrescente e esvazia o heap
void heapSort(HEAP * h){
  int tamanho = h->tamanhoAtual;
  int i;
  struct Drone temp;
  construirHeapMaximo(h);  // se o arranjo jah for um heap, nao precisa desta linha
  for (i=tamanho;i>1;i--){
     temp = h->A[1];
     h->A[1] = h->A[i];
     h->A[i]= temp;
     //printf("%d ",temp);
     (h->tamanhoAtual)--;
     maxHeapify(h,1);
  }
  //printf("\n");
  h->tamanhoAtual = tamanho;
}

bool inserirHeap(HEAP * h, struct Drone chave){
  int i;
  struct Drone temp;
  if (h->tamanhoAtual == h->tamanhoMaximo) return false;


  (h->tamanhoAtual)++;
  i = h->tamanhoAtual;

  h->A[i] = chave;
  while ((i>0) && (h->A[pai(i)].peso<h->A[i].peso)){
     temp = h->A[i];
     h->A[i] = h->A[pai(i)];
     h->A[pai(i)] = temp;
     i = pai(i);
  }
  return true;
}

int percursoPreOrdem(HEAP* h, int atual){
  if (atual <= h->tamanhoAtual){
    printf("%i ", h->A[atual]);
    percursoPreOrdem(h, filhoEsquerda(atual));
    percursoPreOrdem(h, filhoDireita(atual));
  }
}

int alturaHeap(HEAP* h){
  int altura = -1;
  int i = 1;
  while (i <= h->tamanhoAtual){
    i = filhoEsquerda(i);
    altura++;
  }
  return altura;
}


