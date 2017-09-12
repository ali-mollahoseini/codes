//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;

const int inf= 0x7F7FFFFF;
const int MX1 = 30000+1000;
typedef pair<int,int> pii;
map<int,vector<int> > adj;
int mark[MX1];
int que[MX1];
int head, tail;
int dis[MX1];
int flag[MX1];///first:(0 not flaged; 1 loose; 2 win;)

int32_t main(){
    int n,k;
    cin>>n;
    if(n%3==0){
        cout<<3*(n/6)+1;
    }else{
        cout<<(n+1)/2;
    }
}
