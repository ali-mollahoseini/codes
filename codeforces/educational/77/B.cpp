#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        if(b > a*2){
            cout<<"NO\n";
            continue;
        }
        a-=b-a;
        if(a%3 == 0) {
            cout  << "YES\n";
        }else
            cout << "NO\n";
    }
}
