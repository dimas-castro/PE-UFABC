#include <stdio.h>
#include <string.h>
void reverter(int n, char *p) {
  int com, m;
  char aux2;
  com = strlen(p)-n;
  m =strlen(p)/2;
  if(com==m){
    return ;
  }
  aux2 = p[com];
  p[com]=p[n-1];
  p[n-1]=aux2;
  reverter(n-1, p);
}
int main() {
  int n;
 
  // Vetor com espaço para 1002 carcteres (1001 da palavra mais '\0')
  char palavra[1002];
 
  // Lê uma palavra, não mais que 1001 caractéres
  scanf("%1001s", palavra);
 
  n = strlen(palavra);
  reverter(n, palavra);
 
  printf("%s\n", palavra);
 
  return 0;
}