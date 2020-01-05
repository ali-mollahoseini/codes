#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d;
    int aa, bb, cc, dd;
    cin >> a >> b >> c >> d;
    aa = a, bb = b, cc = c, dd = d;
    //cout << b << endl;
    b-=a;
    a=0;
    c-=d;
    d=0;
    if(b < 0 || c < 0){
        if((b == -1 && cc == 0) || (c == -1 && bb == 0)){
        }else{
            cout << "NO\n";
            return 0;
        }
    }
    b = max(b, 0);
    c = max(c, 0);
    int mn = max(min(c, b), 0);
    c -= mn;
    b -= mn;
    //cout << b << endl;
    if(c > 1 || b > 1){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if(b == 1)
        cout << 1 << ' ';
    for(int i = 0; i < aa - 1; i++)
        cout << "0 1 ";
    if(aa > 0 ){
        cout << "0 ";
        bb -= aa -1;
    }
    //cout << bb << endl;
    bb -= b ;
    //cout << bb << endl;
    for(int i = 0; i < bb - 1; i++)
        cout << "1 2 ";
    if(bb> 0){
        cout << "1 ";
        cc -= bb - 1;
    }
    if(cc> 0)
        cout << "2 ";
    cc--;
    for(int i = 0; i < dd - 1; i++)
        cout << "3 2 ";
    if(dd> 0){
        cout << "3 ";
        cc -= dd - 1;
    }
    if(cc > 0)
        cout << "2 ";
}
