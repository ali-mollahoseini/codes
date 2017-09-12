/*
ID: ali.mol1
LANG: C++11
TASK: butter
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

#define INF 9999999
#define pii pair<int,int>

FILE *in,*out;

int n,p,c;

int cows[501];
int g[802][802];

struct order2 {
 bool operator() (const pii &a, const pii &b) {
    if (a.second!= b.second) return a.second < b.second;
    return a.first < b.first;

 }
};


int total[802] = {0};

int dist[802];
int used[802];

void dijkstra(int k) {
    //priority_queue<pii,vector<pii>,order> pq;
    set<pii,order2> pq;
    for (int i = 1; i<= p; ++i) {
        dist[i] = g[k][i];
        used[i] = 0;
    }
    pq.insert(pii(k,0));
    int cnt = 0;
    while(!pq.empty()) {
        pii node = *pq.begin();
        pq.erase(pq.begin());
        if (used[node.first]==1) continue;
        used[node.first] = 1;
        ++cnt;
        if (cnt==p) break;
        for (int i = 1; i<= p; ++i) {
            if (dist[i]>=node.second+g[node.first][i] && g[node.first][i]<INF && used[i]==0) {
                dist[i]=node.second+g[node.first][i];
                pq.insert(pii(i,dist[i]));
            }
        }
    }
    for (int i = 1; i<= p; ++i) {
        //cout << dist[i] << endl;
        total[i]+=dist[i];
    }
}

int solve() {
    int ans = INF;
    for (int i = 0; i< n; ++i) {
        dijkstra(cows[i]);
    }
    for (int i = 1; i<= p; ++i) {
        ans = min(ans,total[i]);
    }
    return ans;
}

int main() {
    in = fopen("butter.in","r");
    fscanf(in,"%d%d%d",&n,&p,&c);
    for (int i = 0; i < n; ++i) {
        fscanf(in,"%d",&cows[i]);
    }
    int a,b,k;
    for (int i = 1; i<= p; ++i) {
        for (int j = i+1; j<=p; ++j) {
            g[i][j] = g[j][i] = INF;
        }
    }
    for (int i = 0; i < c; ++i) {
        fscanf(in,"%d%d%d",&a,&b,&k);
        g[a][b] = min(g[a][b],k);
        g[b][a] = g[a][b];
    }
    for (int i = 1; i<=p; ++i) g[i][i] = 0;
    fclose(in);

    out = fopen("butter.out","w");
    fprintf(out,"%d\n",solve());
    fclose(out);
    return 0;
}

