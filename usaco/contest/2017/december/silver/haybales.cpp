//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX = 100 * 1000 + 1000, inf = 0x7FFFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
ofstream fout("haybales.out");
ifstream fin("haybales.in");
int inp[MX],n,q;
int  bin(int x){
    int l = -1, r = n;
    while(r-l>1){
        int mid= (r+l)/2;
        if(inp[mid]>x){
            r = mid;
        }else{
            l = mid;
        }
    }
    return r;
}
int32_t main(){
    ios::sync_with_stdio(0);
    fin>>n>>q;
    for(int i=0;i<n;i++){
        fin>>inp[i];
    }
    sort(inp,inp+n);
    for(int i=0;i<q;i++){
        int l ,r;
        fin>>l>>r;
        l = bin(l-1);
        r = bin(r);
        fout<<r-l<<endl;
    }
}
