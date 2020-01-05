#include <bits/stdc++.h>
using namespace std;
#define int long long
const int V = 1 << 18, mod =1e9+7;
int seg[V * 2 + 1], p[V * 2 + 1][2];
int n, q;
void build(int id = 1, int l = 0, int r = V){
    if(l == r-1)
        return;
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid, r);
    seg[id] = seg[id*2] +  seg[id*2+1];
}
void push(int id, int l , int r){
    int len = r - l;
    seg[id] = seg[id] + p[id][0]*len + (len)*(len-1)/2LL*p[id][1];
    if(id<V){
        p[id*2][1] += p[id][1];
        p[id*2][0] += p[id][0];
        p[id*2+1][1] += p[id][1];
//        cout<<(p[id][1]>0)<<' '<< p[id][1]<<' '<<id<<' '<<l<<' '<<r<<endl;
        p[id*2+1][0] += p[id][0] + len/2LL*p[id][1];
    }
    p[id][0] = p[id][1] = 0;
}
int update(int id, int l, int r, int s, int e){
    if(e <= l || r <= s)
        return 0;
    push(id, l, r);
    if(s <= l && r <= e){
        int f = l - s + 1;
        int len  = r - l;
        p[id][0] += f;
        p[id][1] += 1;
        return (f + f+len-1)*(len)/2LL;
    }
    int mid = (l+r)/2;
    int ret = update(id*2, l, mid, s, e)+
            update(id*2+1, mid, r, s, e);
    seg[id] += ret;
    return ret;
}
int sum(int id, int l, int r, int s, int e){
    if(e <= l || r <= s)
        return 0;
    push(id, l, r);
    if(s <= l && r <= e){
        //cout<<id<<' '<<l<<' '<<r<<' '<<seg[id]<<endl;
        return seg[id];
    }
    int mid = (l+r)/2;
    return sum(id*2, l, mid, s, e) +
        sum(id*2+1, mid, r, s, e);
}
int32_t main(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin >> seg[V+i];
    }
    build();
    for(int i=0;i<q;i++){
        string t;
        int l ,r;
        cin>>t>>l>>r;
        l--;
        if(t[1]=='s'){
            cout<<sum(1, 0, V, l, r)%mod<<endl;;
        }else{
            update(1, 0, V, l, r);
        }
    }
}
