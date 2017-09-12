///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1=30*1000+100;
const int inf= 0x7FFFFFFF;
using namespace std;
int n;
struct val{
    int base=0;// num
    int lst=0;
    int head;//num in ind array
    int tail;
};
val det[MX1];
struct dsu{
    int num = 0;
    int par ;
    int pt;
};
int height(int x);
void setdef();
void Merge(int x , int y);
int meghdar(int x);
dsu ind[MX1];
int32_t main(){
    cin>>n;
    setdef();
    for(int i=0,u ,v ;i<n;i++){
        string s;
        cin>>s;
        if(s=="Height"){
            cin>>u;
            cout<<height(u)<<endl;
        }else{
            cin>>u>>v;
            Merge(u,v);
        }
    }
}
void setdef(){
    for(int i=0;i<MX1;i++){
        ind[i].pt = i;
        ind[i].par = i;
        det[ind[i].pt].head = i;
        det[ind[i].pt].tail = i;
    }
}
int height(int x){
    //cout << det[ind[x].pt].base << " " << ind[x].num << endl;
    return ind[x].num - det[ind[x].pt].base + 1;
}
int meghdar(int x){
    return (det[ind[x].pt].lst - det[ind[x].pt].base + 1);
}
void Merge(int x , int y){
    int yroot = det[ind[y].pt].head;
    int xroot = det[ind[x].pt].head;
    //cout << "yroot:" << yroot << endl;
    if (xroot == yroot){
        return ;
    }
    int cur;
    int tmp;
    //cout<< "m"<<meghdar(y)<<" "<< meghdar(x)<<endl;
    int ptx = ind[x].pt,pty = ind[y].pt;
    ind[xroot].par = det[pty].tail;// connect x to y
    if(meghdar(x)>meghdar(y)){
        //cout<<"b"<<endl;
        cur = det[pty].tail;// connect
        tmp = ind[xroot].num-1;
        int a = meghdar(y);
        for(int i=0;i<a;i++){
            ind[cur].num = tmp;
            ind[cur].pt = ptx;
            cur = ind[cur].par;
            tmp--;
        }
        det[ptx].head = yroot;
        det[ptx].base = tmp+1;
    }else{
        //cout<<"a"<<endl;
        int mn = det[pty].tail;
        cur = det[ptx].tail;
        tmp = ind[det[pty].tail].num+meghdar(x);
        det[pty].lst = tmp;
        while(cur!=mn){
            ind[cur].num = tmp;
            ind[cur].pt = pty;
            cur = ind[cur].par;
            tmp--;
        }
        det[pty].tail = det[ptx].tail;
    }
    return;
}
