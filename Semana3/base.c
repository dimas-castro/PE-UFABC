#include <stdio.h>
int cont=0, vetor[2000000000], i, sinal=1;
double a;
void imprimir_em_base(int n, int b) {
  if(n/b!=0){
    vetor[cont]=n%b;
    cont++;
    imprimir_em_base(n/b, b);
  }
  if(n/b==0){
    if(sinal==-1){
      printf("-");
    }
    a = ((double)n/b)*b;
    vetor[cont] = a;
    for(i=cont; i>=0; i=i-1){
      printf("%d", vetor[i]);
    }
  }
  return ;
}
int main() {
  int b, n;
  scanf("%d %d", &b, &n);
  if(n<0){
    n = n*(-1);
    sinal=-1;
  }
 
  imprimir_em_base(n, b);
  return 0;
}