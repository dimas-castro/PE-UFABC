#include <stdio.h>
#include <string.h>
#include "item.h"
#include "lista.h"

// Lê da entrada padrão uma lista de números e 
// popula uma lista ligada com esses números.
no *le_lista_inicial() {
  int n;

  scanf("%d", &n);

  no *lista = NULL;
  no *ultimo = NULL;

  for (int i = 0; i < n; i ++) {
    item dado;
    scanf("%d", &dado);

    no *x = cria(dado);

    if (lista == NULL) 
      lista = x;
    else
      ultimo->prox = x;
    ultimo = x;
  }

  return lista;
}


int main() {
  char operacao[20];
  no *lista = le_lista_inicial();  
  
  while (scanf("%s", operacao) == 1) {
    if (strcmp(operacao, "is_empty") == 0) {
      // imprime "TRUE\n" se a lista estiver vazia
      // e "FALSE\n" caso contrário
      if(lista==NULL){
        printf("TRUE\n");
      }else{
        printf("FALSE\n");
      }

    } else if (strcmp(operacao, "push_front") == 0) {
      // lê um item x, cria novo nó com dado = x e
      // insere nó criado no início da lista
      item dado;
      scanf("%d", &dado);
      no *x = cria(dado);
      x -> prox = lista;
      lista = x;

    } else if (strcmp(operacao, "push_back") == 0) {
      // lê um item x, cria novo nó com dado = x e
      // insere nó criado no final da lista
      item dado;
      scanf("%d", &dado);
      no *x = cria(dado);
      if(lista==NULL){
        lista = x;
      }else{
        no *y = final(lista);
        y->prox=x;
      }

    } else if (strcmp(operacao, "pop_front") == 0) {
      // remove o primeiro nó da lista, imprime o
      // campo dado (seu item) na saída padrão e
      // exclui o nó removido
      // imprime "IMPOSSIBLE\n" se a lista estiver vazia

      if(lista==NULL){
        printf("IMPOSSIBLE\n");
      }else{
        no *z = lista->prox;
        imprime(lista -> dado);
        printf("\n");
        lista = z;
      }

    } else if (strcmp(operacao, "pop_back") == 0) {
      // remove o último nó da lista, imprime o
      // campo dado (seu item) na saída padrão e
      // exclui o nó removido
      // imprime "IMPOSSIBLE\n" se a lista estiver vazia
      if(lista==NULL){
        printf("IMPOSSIBLE\n");
      }else{
        no *fim;
        no *com=lista;
        while(com->prox!=NULL){
          fim = com;
          com = com->prox;
        }
        fim->prox=NULL;
        imprime(com->dado);
        printf("\n");
      }


      
    } else if (strcmp(operacao, "print") == 0) {
      // imprime os itens na lista na ordem
      // da esquerda para a direita
      // imprime só o '\n' se a lista estiver vazia

      imprime_lista(lista);
      
    } else if (strcmp(operacao, "search") == 0) {
      // lê um item x e busca por x na lista
      // imprime -1 se x não for encontrado ou
      // o índice do nó que contem o dado x
      // (0 se for 1º nó, 1 se for o segundo, etc.)
      // sempre imprimir o '\n' no final
      item dado;
      no *res;
      scanf("%d", &dado);
      res = busca(lista, dado);
      if(res==NULL){
        printf("-1\n");
      }else{
        no *tmp=lista;
        int cont=0;
        while(tmp!=NULL && tmp->dado!=dado){
            tmp = tmp->prox;
            cont++;
        }
        printf("%d\n", cont);
      }
      
    } else if (strcmp(operacao, "clear") == 0) {
      // exclui todos os nós da lista, deixando-a vazia

      no *x = lista;
      while(x!=NULL){
        exclui(x);
        x = x->prox;
      }

    } else {
      // Nesse caso a operação lida não é válida
      
      printf("INVALID OPERATION\n");
    }
  }

  return 0;
}
