#include "stdlib.h"
#include "stdio.h"
#include "Fila.h"




int q_isEmpty(const Fila f)  //testa se a fila est? vazia
{
    return f->size == 0 ? 1 : 0;
}

int q_size(Fila f) //retorna o tamanho da fila
{
    return f->size;
}

void q_enqueue( const Fila f, float peso,char* fabricante,char* modelo,float cap_mAH,char* tempoar) //cadastra drone na fila
{
    struct node* novo = ( struct node*) malloc( sizeof ( struct node) ) ;

    novo->drone.peso = peso;
    strcpy(&novo->drone.fabricante,fabricante);
    strcpy(&novo->drone.modelo,modelo);
    novo->drone.cap_mAH = cap_mAH;
    strcpy(&novo->drone.tempoar,tempoar);



    novo->next = NULL;
    if (q_isEmpty(f) )
    {
        f->head = novo;
        f->tail = novo;
    }
    else
    {
        f->tail->next = novo;
        f->tail = novo;
    }
    f->size++;
}

struct Drone q_dequeue(const Fila f) //retira done da fila
{
    if (q_isEmpty(f) ) //ERROR
        exit(1) ;
    struct node* first = f->head;
    f->head = first->next;
struct  Drone e = first->drone;
    free(first) ;
    f->size--;
    return e;
}
void imprime_drone(struct Drone d) //imprime um drone
{
    printf("\nPeso = %.2f Kg",d.peso);
    printf("\nNome do fabricante = %s",d.fabricante);
    printf("\nNome do modelo = %s",d.modelo);
    printf("\nCapacidade de corrente = %d mAH",d.cap_mAH);
    printf("\nTempo Maximo no ar = %s",d.tempoar);
    printf("\n");
}
void q_imprime(const Fila f) //imprime a fila
{
struct    Drone e;
    const Fila aux = q_new( ) ;
    while (q_isEmpty(f) == 0)
    {
        e = q_dequeue(f) ;
        imprime_drone(e);
        q_enqueue(aux,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }

    while (q_isEmpty(aux) == 0)
    {
        e = q_dequeue(aux) ;
        q_enqueue(f,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }
    free(aux->head);
}

int q_pesquisa(const Fila f,float peso) //pesquisa drone pelo seu peso
{
    int contador = 0;
struct    Drone e;
    Fila aux = q_new( ) ;

    while (q_isEmpty(f) == 0)
    {
        e = q_dequeue(f) ;
        if(e.peso==peso)
        {
            imprime_drone(e);
            contador++;
            printf("\n");
        }
        q_enqueue(aux,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }

    while (q_isEmpty(aux) == 0)
    {
        e = q_dequeue(aux) ;
        q_enqueue(f,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }
    free(aux->head);

    return contador;
}
int q_remove(const Fila f,float peso) //remove drone pelo peso
{
    int contador = 0;
struct    Drone e;
    Fila aux = q_new( ) ;

    printf("\nRemover drones\n");
    while (q_isEmpty(f) == 0)
    {
        e = q_dequeue(f) ;
        if(e.peso==peso)
        {
            imprime_drone(e);
            contador++;
            printf("\n");
        }
        else{
                printf("\n %.2f != de %.2f ",e.peso,peso);
            q_enqueue(aux,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
        }
    }

    while (q_isEmpty(aux) == 0)
    {
        e = q_dequeue(aux) ;
        q_enqueue(f,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }
    free(aux->head);

    return contador;
}

Fila q_new() //cria uma nova fila
{
    Fila f = (Fila) malloc( sizeof ( struct Fila) ) ;
    f->size = 0;
    f->head = NULL;
    f->tail = NULL;
    return f;
}

void n_free( struct node* n) //libera um no
{
    if (n == NULL)
        return ;
    n_free(n->next) ;
    free(n) ;
}

void q_free(Fila f) //libera a fila
{
    n_free(f->head) ;
    free(f) ;
}

void q_imprime_tempoar_max(const Fila f) //imprime o drone que tem maior tempo no ?r
{
struct    Drone e;
    Fila aux = q_new( ) ;
    float tempoar = q_encontra_maior_tempoar(f);
    while (q_isEmpty(f) == 0)
    {
        e = q_dequeue(f) ;
        if(charParaTempoTotal(e.tempoar)==tempoar)
        {
            imprime_drone(e);
        }
        q_enqueue(aux,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }

    while (q_isEmpty(aux) == 0)
    {
        e = q_dequeue(aux) ;
        q_enqueue(f,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }
    free(aux->head);
}
int charParaValor(char valor) //converte de char para int
{
    switch(valor)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
    }
    return -1;
}
float converteNumeroDuasCasas(char primeiro,char segundo,float fatorTempo) //converte para numero de duas casas
{
    float total = charParaValor(primeiro)*10+charParaValor(segundo);
    total  = total * fatorTempo;
    return total;
}
float charParaTempoTotal(char* valor) //converte de char para tempo total
{
    float total = converteNumeroDuasCasas(valor[0],valor[1],3600)+converteNumeroDuasCasas(valor[3],valor[4],60)+converteNumeroDuasCasas(valor[6],valor[7],1);
    return total;
}
float q_encontra_maior_tempoar(const Fila f) //encontra e retorna o maior tempo no ?r
{
struct    Drone e;
    Fila aux = q_new( ) ;
    float tempo = 0;
    while (q_isEmpty(f) == 0)
    {
        e = q_dequeue(f) ;
        float tempoar = charParaTempoTotal(e.tempoar);
        if(tempoar>tempo)
            tempo = tempoar;
        q_enqueue(aux,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }

    while (q_isEmpty(aux) == 0)
    {
        e = q_dequeue(aux) ;
        q_enqueue(f,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }
    free(aux->head);

    return tempo;
}
void q_estatisticas(const Fila f) //imprime estatisticas da fila
{
struct    Drone e;
    Fila aux = q_new( ) ;
    float peso=0,capacidade=0,tempo=0;
    while (q_isEmpty(f) == 0)
    {
        e = q_dequeue(f) ;
        q_enqueue(aux,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);

        peso+= e.peso;
        capacidade+=e.cap_mAH;
        tempo+=charParaTempoTotal(e.tempoar);
    }

    while (q_isEmpty(aux) == 0)
    {
        e = q_dequeue(aux) ;
        q_enqueue(f,e.peso,e.fabricante,e.modelo,e.cap_mAH,e.tempoar);
    }
    free(aux->head);

    tempo = tempo / (float)f->size;
    peso = peso / (float)f->size;
    capacidade = capacidade/ (float)f->size;

    printf("\nNumero de drones = %d",f->size);
    printf("\nPeso medio = %.2f kg",peso);
    printf("\nCapacidade de corrente media = %.2f ",capacidade);
    printf("\nTempo maximo medio em minutos = %.2f \n",tempo/60);
}
