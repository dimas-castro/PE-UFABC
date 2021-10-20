#include <stdio.h>
#include <string.h>
int a=0;
int eh_palindroma(int n, char *p) {
  if(a==n){
    return 1;
  }else if(p[a]!=p[n-1]){
    return 0;
  }else if(a==n-1){
    return 1;
  }
  a++;
  return eh_palindroma(n-1, p);
}
int main() {
  int n;
 
  // Vetor com espaço para 1002 carcteres (1001 da palavra mais '\0')
  char palavra[1002];
 
  // Lê uma palavra, não mais que 1001 caractéres
  scanf("%1001s", palavra);
 
  n = strlen(palavra);
 
  if (eh_palindroma(n, palavra)==1) 
    printf("SIM");
  else 
    printf("NAO");
 
  return 0;
}