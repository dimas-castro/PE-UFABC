#include <stdio.h>
#include <stdlib.h>

int i=2;
void Fi(int n, int *v){
    v[0]=1;
    v[1]=1;
    for(i; i<=n; i++){
        int a = v[i-1]%i;
        int b = v[i-2]%i;
        v[i]=v[a]+v[b];
    }
}
int main(){
    int n, n1=0, *v;
    scanf("%d", &n);
    v = (int*) malloc((n+1)*sizeof(int));
    Fi(n, v);
    printf("%d\n", v[n]);
    n1=n;
    while(scanf("%d", &n)!=EOF){
        if(n>n1){
            v = (int*) realloc (v, (n+1)*sizeof(int));
            n1=n;
            Fi(n, v);
            printf("%d\n", v[n]);
        }
        else{
            printf("%d\n", v[n]);
        }
    }
}