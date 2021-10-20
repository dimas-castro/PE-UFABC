#include <stdio.h>

int soma(int n, int *v) {
  if (n==0){
      return 0;
  }if(n==1){
      return v[n-1];
  }return v[n-1] + soma(n-1, v);
}


int main() {
  int n;
  scanf("%d", &n);
  
  int v[n];
  for (int i = 0; i < n; i ++)
  scanf("%d", &v[i]);
  
  printf("%d\n", soma(n, v));
  return 0;
}