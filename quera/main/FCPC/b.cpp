#include <stdio.h>
#define KMX  5000
int mat[KMX][KMX];
int n;
int mksqr(int l, int x){
    for(int i = l; i < l + (1<<(x+1))-1; i++){
            mat[l][i] = 1;
            mat[i][l] = 1;
            mat[l + (1<<(x+1))-2][i] = 1;
            mat[i][l + (1<<(x+1))-2] = 1;
    }
}
int mkrhmb(int l, int x){
    for(int i = 0 ; i < (1<<(x+1))-1; i++){
            //cout << ((1<<n)-1 +i) << ' ' <<l+i <<endl;
            mat[(1<<n)-1+i][l+i] = 1;
            //cout << ((1<<n) -i) << ' '<<l-i <<endl;
            mat[(1<<n)-1-i][l+i] = 1;
            mat[(1<<n)-1-i][l+(1<<(x+2))-4-i] = 1;
            mat[(1<<n)-1+i][l+(1<<(x+2))-4-i] = 1;
    }
}
int main(){
    scanf("%d", &n);
    int lst = 0;
    for(int j = n ; j > n/2 ;j--){
        mksqr(lst,j);
        lst += (1 << (j-1));
    }
    lst = 1;
    for(int j = n-1 ; j >= (n+1)/2 ;j--){
        mkrhmb(lst,j);۱
        lst += (1 << (j));
    }
    for(int i = 0; i < (1 << (n+1)) -1; i++){
        for(int j = 0; j < (1 << (n+1)) -1; j++){
            if(mat[i][j]){
                printf("#");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
}
