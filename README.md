# droneAVL

Trabalho feito em 2017.

Trabalho Prático - Parte 2 - Turma 33

Será utilizado o mesmo TAD DRONE1 do TP1, com as mesmas características (Figura 1 - TAD DRONE1):
1. Peso em Kg com duas casas decimais
2. Nome do fabricante com no máximo 40 caracteres
3. Nome do modelo do drone com no máximo 20 caracteres
4. Capacidade de fornecimento de corrente das baterias em mAH, exemplo: 1200 mAH, 8000 mAH e 10000 mAh
5. Tempo máximo que o drone consegue se manter no ar, no formato hh:mm:ss (sempre armazenado assim)


![image](https://user-images.githubusercontent.com/37150386/113354058-f260ef00-9314-11eb-93e7-5909ef8ad65d.png)

Figura 1: TAD DRONE1

Para cada grupo de alunos, fazer um sistema que possua no programa principal os itens de execução na ordem
abaixo (menu):
1. Ler todos os drones gravados em um arquivo texto de nome “drones-tp2.txt”, arquivo do TP1 com conteúdo
alterado FORNECIDO PELO PROFESSOR. Inserir cada um na mesma estrutura definida para cada
grupo do TP1.
A ordem de leitura de cada linha é a ordem do item que será inserido no TAD (lista,fila, deque ou pilha) que
foi determinada para cada grupo de alunos. Ou seja, o primeiro drone que é lido é o primeiro elemento da
lista, da fila, da pilha ou do deque, mas no caso da pilha, é o primeiro elemento a ser empilhado (PUSH).
As estruturas (todas obrigatoriamente com alocação dinâmica de memória) poderão ser: listas encadeadas,
listas duplamente encadeadas, filas encadeadas, filas duplamente encadeadas, deques e pilhas. Esta é a
primeira parte (ler o arquivo e inserir na mesma estrutura do TP1).
2. Exibir, à partir do primeiro elemento da estrutura (de cada grupo) montada em memória, todos os drones,
cada um em uma linha na tela.
3. Árvore AVL
(a) Montar uma árvore de pesquisa binária balanceada - árvore AVL - à partir da estrutura do TP1 do
item anterior, conforme o campo chave definido para cada grupo, que poderá ser: pelo fabricante, pelo
modelo, pelo peso, pela capacidade de corrente ou pelo tempo máximo. Atenção, não haverão campos
chaves iguais pois cada chave é única. Todos os itens da estrutura do TP1 serão inseridos na árvore à
partir de seu primeiro item (início ou head) até o último, conforme estiverem na memória.
(b) Exibir a árvore na tela.
(c) Remover um drone de acordo com o campo definido para cada grupo. Por exemplo: Remover o drone
cujo peso foi digitado como 1.00 Kg ou remover o drone do fabricante PARROT1. Caso não existir,
exibir na tela que não foi encontrado.
(d) Inserir um drone na árvore AVL (conforme a chave definida para cada grupo). Ao inserir, exibir o
número de comparações executadas até que o drone seja inserido na árvore.

MINISTÉRIO DA EDUCAÇÃO
Universidade Federal de Ouro Preto
Departamento de Computação e Sistemas
Campus João Monlevade

(e) Buscar e exibir um drone segundo a chave designada para cada grupo, por exemplo o nome do fabri-
cante, que é digitada via teclado.

(f) Liberar a estrutura da memória.
4. Heap
(a) Montar o heap definido para cada grupo, que poderá ser um heap máximo ou um heap mínimo à partir
da estrutura do TP1, conforme o campo chave definido para cada grupo, que poderá ser: pelo modelo,
pelo peso, pelo capacidade de corrente ou pelo tempo máximo. Atenção, não haverão campos chaves
iguais pois cada chave é única. Todos os itens da estrutura do TP1 serão inseridos no heap à partir de
seu primeiro item (início ou head) até o último, conforme estiverem na memória.
(b) Exibir o heap na tela.
(c) Remover o drone que está na raiz do heap e exibir a chave removida.
(d) Inserir um drone no heap máximo ou mínimo definido para cada grupo. Ao inserir, exibir o número
de comparações executadas até que o drone seja inserido no heap.
(e) Buscar e exibir um drone segundo a chave designada para cada grupo, por exemplo o nome do modelo,
que é digitada via teclado.
(f) Remover e exibir na tela cada chave raiz do heap, ao final o heap não mais existirá na memória.
5. Encerrar o programa liberando todas as estruturas alocadas dinamicamente.

SUGESTÃO

Montar um menu com quatro opções:
1 - Parte 1 do Trabalho Prático
2 - Parte 2 do Trabalho Prático
3 - Parte 3 do Trabalho Prático
4 - Terminar
Ao ser digitada a opção 2, o seguinte menu irá ser exibido:
01 - Ler os drones do arquivo texto e inserir na estrutura “X” definida para cada grupo
02 - Exibir os drones
03 - Montar árvore AVL pela chave “tal”, definida para cada grupo
04 - Exibir a árvore AVL pela chave definida para cada grupo
05 - Remover da árvore AVL um drone segundo a chave que foi digitada
06 - Buscar e exibir um drone segundo a chave digitada pelo usuário
07 - Liberar a árvore AVL da memória
08 - Montar o heap máxim ou mínimo com a chave definida para cada grupo
09 - Exibir o heap máximo ou mínimo na tela
10 - Remover o drone raiz do heap e exibir a chave removida
11 - Inserir no heap um drone que será digitado e exibir quantas comparações foram feitas
12 - Remover e exibir sucessivamente na tela o conteúdo da chave de cada elemento raiz do heap, até que o
heap não mais exista
