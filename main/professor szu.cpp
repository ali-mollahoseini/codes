///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 01 |   CF Round 431   | 10 |
///    +----+------------------+----+

#include <bits/stdc++.h>
//#define ll long long
#define int unsigned short int
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*1000 + 10;
const int inf = 0x7FFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
void solution();
bool used[MX];
int n,m;
vector<int> adj[MX],jda[MX];
vector<int> comp[MX],ans;
int mark[MX];
bool cyc,cycl[MX];
int32_t main(){
    Init
    solution();
}
void dfs(int v,vector<int> poshte){
    mark[v]=1;
    for(auto e : adj[v]){
        if(!mark[e]){
            dfs(e,poshte);
        }
    }
}
void sfd(int v, int c,vector<int>*revcomp){
    mark[v]= c;
	comp[c].pb(v);
	for(auto e : jda[v]){
		if(!mark[e]){
			sfd(e,c,revcomp);
			cyc=1;
			cycl[c]=1;
		}else if (c != mark[e] ){
			revcomp[c].pb(mark[e]);
		}else{
		    cycl[c]=1;
			cyc=1;
		}
	}
}
void cycle(int v, bool ok,vector<int>*revcomp){
	used[v]=1;
	if(!ok && cycl[v]){ok=1;}
	if(ok){
		for(auto e: comp[v]){
			ans.pb(e);
		}
	}
	for(auto e:revcomp[v]){
    cout<<poshte.size()<<endl;
		if(!used[e]){
			cycle(e,ok,revcomp);
		}
	}
}
int scc(){
    vector<int> poshte,revcomp[n];
    for(int i=0;i<n;i++){
        if(!mark[i]){
            dfs(i,poshte);
        }
    }
    fill(mark,mark+MX,0);
    int cnt=1;
    while(poshte.size()){
            cout<<">_<"<<endl;
        int b = poshte.back();poshte.pop_back();
        if(!mark[b]){
			sfd(b,cnt,revcomp);
			cnt++;
        }
	}
    cout<<cnt<<endl;
	if(cyc){
        cycle(mark[n],0,revcomp);
	}
	return cnt;
}
int topo(int v){
	used[v] = 1;
	int mx = mark[v];
    for(auto e:adj[v]){
        jda[e].pop_back();
        if(!used[e]){
            int x = topo(e);
            if(!(mx>36500)){
                mx += x;
            }
        }else {
            if(!(mx>36500)){
                mx += mark[e];
            }
        }
    }
	mark[v] = mx;
	return mx;
}
void solution(){
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        adj[--u].pb(--v);
        jda[v].pb(u);
    }
    int cnt = scc();
	if(cyc){
		cout<<"zawsze"<<endl;
		cout<<ans.size()<<endl;
		sort(ans.begin(),ans.end());
		for(int e:ans){
			cout<<e+1<<" ";
		}
        return;
	}else{
	    cout<<1<<endl;
		memset(mark,0,sizeof(mark));
		memset(used,0,sizeof(used));
		mark[n]=1;
		int mx = 0;
		for(int j=0;j<n;j++){
            if(!jda[j].size() &&!used[j]){
                mx = max(topo(j),mx);
            }
        }
        if(mx>36500){
			cout<<"zawsze"<<endl;
			for(int i=0;i<n;i++){
				if(mark[i]>36500){
                    ans.pb(i);
				}
			}			cout<<ans.size()<<endl;
			for(auto e:ans){
                cout<<e+1<<" ";
			}
		}else{
            cout<<mx<<endl;
			for(int i=0;i<n;i++){
				if(mark[i]==mx){
                    ans.pb(i);
				}
			}
			cout<<ans.size()<<endl;
			for(auto e:ans){
                cout<<e+1<<" ";
			}
		}
		return ;
	}
}
