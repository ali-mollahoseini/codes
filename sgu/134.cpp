//in the name of Allah
//Ali Mollahoseini
#include <bits/stdc++.h>

#define int long long
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf= 0x7F7FFFFF;
const int MX1 = 17000;

int n;
map<int,vector<int> >adj;
int par[MX1];
int que[MX1];
int head, tail;
bool mark[MX1];
int stree[MX1];
int dp[MX1];
void bfs(int v){
	par[v]=-1;
	que[tail++] = v;
	while(head<tail){
		int tmp = que[head++];
        mark[tmp] = 1;
		for(int i=0;i<adj[tmp].size();i++){
			int &pt= adj[tmp][i];
			if(!mark[pt]){
				mark[pt]=1;
				par[pt]=tmp;
				que[tail++] = pt;
			}
		}
	}
}
int32_t main(){
    cin>>n;
    for(int i=0, u, v;i<n-1;i++){
        cin>> u >> v ;
		adj[--u].pb(--v);
		adj[v].pb(u);
    }
	bfs(0);
	for(int i=tail-1;i>-1;i--){
		int tmp = que[i];
		stree[tmp]=1;
		int mx=0;
		for(int j=0;j<adj[tmp].size();j++){
			int &pt = adj[tmp][j];
			if(pt !=  par[tmp]){
				//cout<<tmp<<endl;
				stree[tmp] += stree[pt];
				mx = max(mx, stree[pt]);
			}
		}
		dp[tmp]= max(n - stree[tmp],mx);
	}
	vector<int> ans;
	int mn=inf;
	for(int i=0;i<n;i++){
		if(dp[i]<=mn){
			if(dp[i]<mn){

				ans.clear();
			}
			ans.pb(i+1);
			mn = dp[i];
		}
	}
	cout<<mn<<" "<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

