#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define F first
#define S second
typedef pair<int, int> pii;
bool comp(pii a, pii b) {
    return a.F < b.F;
}
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
        tree_order_statistics_node_update> iset;
const int V = 1LL << 17;
iset seg[V * 2];
void upd(int t, int s, int e, int c, int id = 1, int l = 0, int r = V){
    if (e <= l || r <= s)
        return ;
    if (s <= l && r <= e){
        seg[id].insert({t, c});
        return;
    }
    int mid = (l+r)/2;
    upd(t, s, e, c, id*2, l, mid);
    upd(t, s, e, c, id*2+1, mid, r);
}
pii ask(int t, int v, int id = 1, int l = 0, int r = V){
    int mid = (l+r)/2;
    pii ret = {0,0};
    int pos = seg[id].order_of_key({t, 0LL});
    pos--;
    if(pos>-1){
        auto it = seg[id].find_by_order(pos);
        ret = *it;
    }
    if(id >= V)
        return ret;
    if(v < mid){
        pii tmp = ask(t, v, id*2, l, mid);
        if(tmp.F>ret.F)
            ret = tmp;
    }else{
        pii tmp = ask(t, v, id*2+1, mid, r);
        if(tmp.F>ret.F)
            ret = tmp;
    }
    return ret;
}
int32_t main(){
    int n, q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        char type;
        cin >> type;
        if(type == '~'){
            int t, l, r, c;
            cin >> t >> l >> r >> c;
            l--;
            upd(t, l, r, c);
        }else{
            int t, x;
            cin >> t >> x;
            x--;
            cout << ask(t, x).S << endl;;
        }
    }
}
