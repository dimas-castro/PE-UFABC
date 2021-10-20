#include <stdio.h>

#define N 20000

int main() {
  int n = 0;
  double t[N], med, min = 100, max = -100, soma = 0;

  while(n < N && scanf("%lf", &t[n]) > 0) {
    if(t[n]>max){
      max=t[n];
    }
    if(t[n]<min){
      min=t[n];
    }
    soma=soma+t[n];
    n++;
  }
  
  med = soma / n;

  printf("med = %2.3f, min = %2.3f, max = %2.3f\n", med, min, max);
  
  int a, cont=0;
  double intervalo, media2, soma2;
  for(a=0; a<n; a++){
    if (t[a]>med){
      soma2=soma2+t[a];
      cont++;
    }
  }
  media2=soma2/cont;
  printf("Média das temperaturas acima da média: %.3lf\n", media2);
  intervalo=(max-min)/20;
  int aux[20]={0}, b, aster;
  double intaux=min+intervalo;
  for(a=0; a<20; a++){
    for(b=0; b<n; b++){
      if(t[b]<=intaux){
        if(t[b]>=(min+intervalo*a)){
          aux[a]++;
        }
      }
    }
    intaux=intaux+intervalo;
  }
  for(b=0; b<20; b++){
    printf("aux[%d] = %d\n", b, aux[b]);
  }
  for(b=0; b<20; b++){
    printf("Temperaturas entre ");
    if((min+intervalo*b)<10){
      printf("0%.3lf e",min+intervalo*b);
      if((min+intervalo*(b+1))<10){
        printf(" 0%.3lf:", (min+intervalo*(b+1)));
      }
      else{
        printf(" %.3lf:", (min+intervalo*(b+1)));
      }
    }
    if(((min+intervalo*(b+1))>=10)&&((min+intervalo*b)>=10)){
      printf("%6.3f e %6.3f: ", (min+intervalo*b), (min+intervalo*(b+1)));
    }
    aster=aux[b]/122;
    for(a=0; a<aster; a++){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
