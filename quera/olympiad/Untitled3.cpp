#include <stdio.h>
int a, b, c, A, B, C;
int min(int a, int b){
    if(a < b)
        return a;
    return b;
}
int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int main(){
    scanf("%d%d%d%d%d%d", &A, &B, &C, &a, &b, &c);
    int aa = a, bb = b, cc = c, AA = A, BB = B, CC = C;
    int ans = min(a, B) + min(b, C) + min(c, A);
    a -= min(aa, BB);
    b -= min(bb, CC);
    c -= min(cc, AA);
    A -= min(cc, AA);
    B -= min(aa, BB);
    C -= min(bb, CC);
    aa = min(a, A);
    bb = min(b, B);
    cc = min(c, C);
    a -= aa;
    b -= bb;
    c -= cc;
    ans -= a + b + c;
    printf("%d", ans);
}
