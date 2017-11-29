//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 50*1000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
ofstream fout("fencedin.out");
ifstream fin("fencedin.in");
int A, B, n,m;
int a[MX],b[MX];
int32_t main(){
    fin>>A>>B>>n>>m;
    for(int i=0;i<n;i++)
        fin>>a[i];
    for(int i=0;i<m;i++)
        fin>>b[i];

    sort(a,a+n+1);
    sort(b,b+m+1);
    for(int i=0;i<n;i++)
        a[i]= a[i+1]-a[i];
    a[n] = B-a[n];
    for(int i=0;i<m;i++)
        b[i]= b[i+1]-b[i];
    b[m] = A-b[m];
    int sum = 0;

    n++;m++;
    sort(a,a+n);
    sort(b,b+m);
    sum += a[0]*(m-1) + b[0]*(n-1);
    for(int vi  = 1, hi=1; hi<m &&vi<n; ){
        if(a[vi]<b[hi]){
            sum += a[vi++]*(m-hi);
        }else{
            sum += b[hi++]*(n-vi);
        }
    }
    fout<<sum<<endl;
}
