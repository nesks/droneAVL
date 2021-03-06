#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Fila.h"
#include "avl.h"
#include "Heap.h"

void menuTrabalho1() //fun??o responsavel por exibir o menu e fazer todo o controle, desde ler os drones e alocar em filas at? liberar as mesmas.
{
    FILE * arq;
    float peso;
    char fabricante[41], modelo[21];
    int cap_mAH;
    char pesos[14], tempoar[9], linha[121];
    Fila f = q_new( ) ;
    int op;
    float aux;
    int sair = 0;

    while(sair!=1)
    {
        printf("\nTrabalho 1\n1 - Ler os drones do arquivo texto e inserir na estrutura");
        printf("\n2 - Exibir os drones");
        printf("\n3 - Buscar um drone pelo modelo");
        printf("\n4 - Remover drone pelo modelo");
        printf("\n5 - Inserir um drone");
        printf("\n6 - Buscar drone com o maior tempo maximo no ar");
        printf("\n7 - Exibir quantidade de drones, o peso medio e tempo maximo medio");
        printf("\n8 - Liberar as estruturas alocadas e voltar para a tela anterior");
        printf("\n");
        scanf("%d",&op);
        switch(op)
        {

        case 1: //l? os drones
            arq=fopen("drones.txt","r");
            fgets(linha,120,arq); /* L? uma linha que ? desprezada */

            while( fscanf(arq,"%s %s %s %d %s\n", pesos, fabricante, modelo, &cap_mAH, tempoar) != EOF )
            {
                printf("%s %s %s %d %s\n",pesos, fabricante, modelo, cap_mAH, tempoar);

                /* Ler o campo peso como string e converter para char */
                peso=atof(pesos);
                printf("Peso: %.2f\n",peso);  /* A vari?vel float ficar? com alguns n?meros ap?s as 2 casas decimais */
                /* Exibe o valor do peso que foi convertido em 2 casas decimais */
                printf("\n");
                q_enqueue(f,peso,fabricante,modelo,cap_mAH,tempoar);

            };
            fclose(arq);
            fflush(arq);
            break;
        case 2: //imprime os drones
            printf("\nImprimindo:");
            q_imprime(f);
            break;

        case 3: //busca drone pelo peso
            printf("\nDigite o peso do drone a ser pesquisado:\n");
            scanf("%f",&aux);
            int pesquisa = q_pesquisa(f,aux);
            if(pesquisa==0)
            {
                printf("\nNenhum resultado para o peso %.2f.",aux);
            }
            break;

        case 4: //remove drone pelo peso
            printf("\nDigite o peso do drone a ser removido:\n");
            scanf("%f",&aux);
            int removidos = q_remove(f,aux);
            if(removidos == 0)
            {
                printf("\nNenhum drone com o peso %.2f para ser removido.",aux);
            }
            break;
        case 5: //insere novo drone
            printf("\nPeso: ");
            fflush(stdin);
            scanf("%f",&peso);
            printf("Nome do fabricante: ");
            fflush(stdin);
            fgets(fabricante,41, stdin);
            fabricante[strlen(fabricante)-1]='\0';
            printf("Nome do modelo: ");
            fflush(stdin);
            fgets(modelo,21, stdin);
            modelo[strlen(modelo)-1]='\0';
            printf("Capacidade de corrente: ");
            fflush(stdin);
            scanf("%d",&cap_mAH);
            printf("Tempo Maximo no ar (formato HH:MM:SS): ");
            fflush(stdin);
            fgets(tempoar,10, stdin);
            tempoar[strlen(tempoar)-1]='\0';
            q_enqueue(f,peso,fabricante,modelo,cap_mAH,tempoar);
            break;
        case 6: //busca por tempo no ar
            q_imprime_tempoar_max(f);
            break;
        case 7: //Exibe quantidade de drones, o peso medio e tempo maximo medio
            q_estatisticas(f);
            break;
        case 8: //libera a estrutura e volta
            sair=1;
            q_free(f);
            break;
        default:
            printf("\nOpcao invalida");
            break;

        }

    }
}

void  menuTrabalho2(){ // segunda parte do trabalho pratico
    FILE * arq;
    float peso;
    char fabricante[41], modelo[21];
    float cap_mAH;
    char pesos[14], tempoar[9], linha[121];
    Fila f = q_new( ) ;
    int op;
    float aux;
            arq=fopen("robos-tp2.txt","r");
            fgets(linha,120,arq); /* L? uma linha que ? desprezada */

            while( fscanf(arq,"%s %s %s %f %s\n", pesos, fabricante, modelo, &cap_mAH, tempoar) != EOF )
            {

                /* Ler o campo peso como string e converter para char */
                peso=atof(pesos);
                q_enqueue(f,peso,fabricante,modelo,cap_mAH,tempoar);

            };
            fclose(arq);
            fflush(arq);
            printf("\n\nEstrutura de robos-tp2.txt carregada com sucesso!\n\n\n");

                  q_imprime(f);
    int sair = 0;
    printf("\n Bem vindo a segunda parte do trabalho pratico!\n");
    printf("Nesta parte do trabalho, teremos arvore AVL e HEAP maximo\n");
    while (sair != 1){
    printf("Digite 1 para arvore AVL\nDigite 2 para HEAP maximo\n");
    int op = 0;
    scanf("%d",&op);
        if(op == 1){

    printf("\nBem vindo a arvore AVL!\n");
            int bye = 0;
            while(bye != 1){
            printf("Selecione a tarefa que deseja executar:\n");
            printf("1- Montar uma ?rvore de pesquisa bin?ria balanceada - ?rvore AVL\n");
            printf("2- Exibir a ?rvore na tela \n");
            printf("3- Remover um drone pelo peso \n");
            printf("4- Inserir um drone na ?rvore AVL \n");
            printf("5- Buscar e exibir um drone pelo peso \n");
            printf("6- Liberar arvore!\n");
            printf("7- Sair!\n");
            scanf("%d",&op);
            switch(op)
            {
            case 1:
                printf("\n\n\n\nMontar arvore avl!\n");//Montar uma ?rvore de pesquisa bin?ria balanceada - ?rvore AVL
                ArvAVL *a = cria_ArvAVL();
                    struct node* no = f->head;
                    while(no->next!=NULL){
                   insere_ArvAVL(a,no->drone);
                    no = no->next;
                    }
                printf("Criado com sucesso \n");
                //incompleto
                break;
            case 2:
                printf("Quanto maior a altura, mais acima da arvore se encontra, o maior valor e o raiz\n");//Exibir a ?rvore na tela
                emOrdem_ArvAVL(a);
                posOrdem_ArvAVL(a);
                preOrdem_ArvAVL(a);
                break;
            case 3:
                printf("EM constru??o!\n");//Remover um drone pelo peso
                break;
            case 4:
                printf("Em constru??o\n");//Inserir um drone na ?rvore AVL
                struct Drone d1;
                float x = 342432;
                d1.peso = x;
                break;
            case 5:
                printf("Em constru??o\n");//Buscar e exibir um drone pelo peso
                break;
            case 6:
                printf("EM constru??o\n");//Liberar arvore
                break;
            case 7:
                bye = 1;
                break;
            }
        }
        }

        else if(op == 2){
            printf("\nBem vindo ao HEAP!\n");
            int bye = 0;
            while (bye != 1){
                printf("Selecione a tarefa que deseja executar:\n");
                printf("1- Montar Heap Maximo\n");
                printf("2- Exibir o Heap\n");
                printf("3- Remover o drone raiz do heap\n");//exibir a chave removida
                printf("4- Inserir um drone no heap m?ximo\n");//Exibir o numero de compara??es
                printf("5- Buscar e exibir um drone pelo peso \n");
                printf("6- Remover e exibir o conte?do da chave de cada elemento raiz do heap\n");
                printf("7- Liberar Heap!\n");
                printf("8- Sair!\n");
                scanf("%d",&op);
            switch(op)
            {
            case 1:
                printf("Inicializando heap !\n");//Montar Heap Maximo
                HEAP meuHeap;
                  inicializarHeap(&meuHeap, q_size(f));
                    struct node* no = f->head;
                    do{
                   inserirHeap(&meuHeap,no->drone);
                    no = no->next;
                    }while(no->next!=NULL);
                    construirHeapMaximo(&meuHeap);
                printf("Criado com sucesso \n\n");
                break;
            case 2:
                printf("nao esta imprimindo o no raiz!\n");//Exibir o Heap
                 imprimirArranjo(meuHeap);
                break;
            case 3:
                printf("EM constru??o!\n");//Remover o drone raiz do heap
                break;
            case 4:
                printf("Em constru??o\n");//Inserir um drone no heap m?ximo
                break;
            case 5:
                printf("Em constru??o\n");//Buscar e exibir um drone pelo peso
                break;
            case 6:
                printf("EM constru??o\n");//Remover e exibir o conte?do da chave de cada elemento raiz do heap
                break;
            case 7:
                printf("Liberando \n");//Liberar Heap
                destruirHeap(&meuHeap);
                printf("liberado com sucesso\n");
                break;
            case 8:
                bye = 1;
                break;
            }
            }
            }
        else {
            printf("\nComando invalido!\n");
            sair = 1;
        }
    }

}

void main()
{
    int sair = 0;
    int op;
    while(sair!=1) //exibe as op??es para de sair ou entrar no trabalho.
    {
        printf("\nMenu\n1-Parte 1 do Trabalho Pratico\n2-Parte 2 do Trabalho pratico\n3-Sair!\n");
        scanf("%d",&op);
        if(op==1)
        {
            menuTrabalho1();
        }
        else if(op==2)
        {
            menuTrabalho2();
        }
        else if (op == 3)
        {
            sair = 1;
        }else{
            printf("\nParte 3 ainda n?o implementada!\n");
        }


    }
}
