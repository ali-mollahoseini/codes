//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
ofstream fout("cbarn.out");
ifstream fin("cbarn.in");
int n;
int inp[MX];
int32_t main(){
    fin>>n;
    int c=0;
    for(int i=0;i<n;i++){
        fin >> inp[i];
        c = max(0LL, c + inp[i] - 1);
    }
    for(int i=0;i<n;i++){
        if(!c){
            rotate(inp,inp+i,inp+n);
            break;
        }
        c = max(0LL, c + inp[i] - 1);
    }
    int sum=0;
    queue<int > q;
    for(int i=0;i<n;i++){
        while(inp[i]--)
            q.push(i);
        sum+=(i-q.front())*(i-q.front());
        q.pop();
    }
    fout<<sum<<endl;
}
