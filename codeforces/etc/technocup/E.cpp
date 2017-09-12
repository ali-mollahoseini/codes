//in the name of Allah
//Ali Mollahoseini
#include <bits/stdc++.h>

#define int long long
#define F first
#define S second
#define pb push_back
#define Log(y,x) cerr << "Log: " << y << " " <<  x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int inf= 0x7F7FFFFF;
const int MX1 = 200*1000+1000;
int x[MX1];
int32_t main(){
    int n, s, inp[MX1];
    cin>>n>>s;
    int cntr=0,cnt=0;
    for(int i=0,tmp;i<n&&cnt<n;i++){
        cin>>tmp;
        if(i==s-1 ){
            //Log(i);
            if(tmp){++cntr;}
            continue;
        }
        x[tmp]++;
    }
    int cur=0;
    for(int i=1, j=1;j<n;i++){
        if(x[i]){
            j+=x[i];
        }else{
            j++;
            cntr++;
        }
    }
    cout<<cntr<<endl;
}

