#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 73;


long long n;
vector<int> adj[N];

long long ft[N];

void up(int u, int val) {
    while (u < N) {
        ft[u] += val;
        u += u & -u;
    }
    return;
}

long long q(int u) {
    long long res = 0;
    while (u > 0) {
        res += ft[u];
        u -= u & -u;
    }
    return res;
}

long long c[N], t[N];
int root = 0;

long long ans[N];
long long si[N];

long long sdfs(int u, int p = -1) {
    si[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        si[u] += sdfs(v, u);
    }
    return si[u];
}


void add(int u, int p, int s){
    for (int v : adj[u]) {
        if (v == p) continue;
        add(v, u, s);
    }
    up(c[u], s * t[u]);
}

void dfs(int u, int p = -1, int keep = 0) {
    int big = -1;
    long long mx = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        if (si[v] > mx) {
            big = v;
            mx = si[v];
        }
    }

    for (int v : adj[u]) {
        if (v == p || v == big) continue;
        dfs(v, u, 0);
    }

    if (~big) dfs(big, u, 1);

    for (int v : adj[u]) {
        if (v == p || v == big) continue;
        add(v, u, 1);
    }
    up(c[u], t[u]);

    //---------------

    ans[u] = q(c[u] - 1);


    if (!keep) {
        up(c[u], -t[u]);
        for (int v : adj[u]) {
            if (v == p) continue;
            add(v, u, -1);
        }
    }
}


int32_t main(){

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m >> c[i] >> t[i];
        if (m == -1) {
            root = i;
            continue;
        }
        m--;
        adj[i].push_back(m);
        adj[m].push_back(i);
    }
    sdfs(root);
    dfs(root);

    for (int i = 0; i < n; i++) cout << ans[i] << "\n";

}

