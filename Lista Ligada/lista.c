#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "lista.h"

no *cria(item dado) {
      no *x = (no*) malloc(sizeof(no));
      x -> dado = dado;
      x -> prox = NULL;
      return x;
}
  
void exclui(no *x) {
      free(x);
}

void imprime_lista(no *cabeca) {
  no *tmp = cabeca;
  
  while (tmp != NULL) {
    imprime(tmp->dado);
    tmp = tmp->prox;
  }

  printf("\n");
}

no *busca(no *cabeca, item dado) {
      no *tmp=cabeca;
      while(tmp!=NULL && tmp->dado!=dado){
            tmp = tmp->prox;
      }
      return tmp;
}

no *busca_rec(no *cabeca, item dado) {
      if(cabeca==NULL){
            return NULL;
      }
      if(cabeca->dado==dado){
            return cabeca;
      }
      return busca_rec(cabeca->prox, dado);

}

no *final(no *cabeca) {
      no *tmp = cabeca;
      while(tmp!=NULL){
            if(tmp->prox==NULL){
                  return tmp;
            }
            tmp  = tmp->prox;
      }
      return tmp;
}
