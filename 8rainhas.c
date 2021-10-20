#include <stdio.h>

int N=8, res[8];
int dama(int n, int res[], int j);
int Rainhas(int n){
    int j, r;
    if(n==0){
        for(j=0; j<N; j++){
            printf("%d ", res[j]);
        }
        printf("\n");
        return 1;
    }else{
        for(j=0; j<N; j++){
            res[N-n] = j;
            if(dama(n, res, j)==0){
                r = Rainhas(n-1);
                if(r==1){
                    return 1;
                }
            }
        }
    }
    return 0;
}
int dama(int n, int res[], int j){
    int i, deltax, deltay, soma=0;
    for(i=0; i<(N-n); i++){
        deltax = (N-1-i)-(n-1);
        deltay = res[i] - j;
        if(deltax<0){
            deltax = deltax*(-1);
        }if(deltay<0){
            deltay = deltay*(-1);
        }if((deltax==deltay)||(N-i-1 == n-1)||(res[i]==j)){
            return -1;
        }
    }
    return 0;
}
void main(){
    int n=8;
    Rainhas(n);
}