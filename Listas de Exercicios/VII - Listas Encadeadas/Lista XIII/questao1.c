/*
QUESTÃO 01:
Considere uma lista encadeada com a seguinte configuração na memória principal, onde L, aux1
e aux2 são do tipo TLista:

    10 5 11 2 4
L      ;    ;   
      aux1 aux2
*/

/*
a. O que os seguintes elementos armazenam?
i. L        ii. aux1->prox->
iii. aux1->valor        iv. aux2->prox->prox

b. Qual o resultado (explique com detalhes) da execução dos comandos a seguir (considerando
que os mesmos não são executados em sequência)?
i. aux2 = aux1->prox; ii. free (aux2->prox);
iii. aux1->prox = aux2->prox; iv. L->prox = NULL;
*/

/*
A)

1. O elemento L armazena o endereço do primeiro elemento da lista (10).
2. aux1->prox-> armazena o endereço do quarto elemento da lista (2).
3. aux1->valor armazena o valor do segundo elemento da lista (5).
4. aux2->prox->prox armazena o endereço do sexto elemento da lista (NULL).
*/

/*
B)


*/