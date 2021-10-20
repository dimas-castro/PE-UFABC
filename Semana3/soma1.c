#include <stdio.h>

int soma(int n) {
  int resposta=0;
    resposta = resposta + n;
    if(n==1){
        return resposta;
    }
    return soma(n-1) + n;
}

int main() {
  int n;
  scanf("%d", &n);
 
  printf("%d\n", soma(n));
  return 0;
}