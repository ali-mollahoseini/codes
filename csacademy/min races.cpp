
//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 40,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
pair<int,int> inp[MX];//f=red
int n;
map<int,bool> mark;
map<int,map<int,int> > mp;
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i].F>>inp[i].S;
    }
    int fh=n/2,sh=n-fh;
    int r=1<<fh;
    for(int i=0;i<r;i++){
        pair<int,int> sum={0,0};//f:red
        int cntr=0;
        for(int j=0;j<fh;j++){
            if(i&(1<<j)){
                sum.F+=inp[j].F;
                cntr++;
            }else{
                sum.S+=inp[j].S;
            }
        }
        int dif2=fh-cntr;
        dif2=dif2-cntr;
        int dif1 =sum.S-sum.F;
        mark[dif1]=1;
        mp[dif1][dif2]=i;
    }
    pair<int,int> ans;
    bool tf=0;
    int mn = inf;
    r=1<<sh;
    for(int i=0;i<r;i++){
        pair<int,int> sum1={0,0};//f:red
        int cntr=0;
        for(int j=0;j<sh;j++){
            if(i&(1<<j)){
                sum1.F+=inp[j+fh].F;
                cntr++;
            }else{
                sum1.S+=inp[j+fh].S;
            }
        }
        int d2=sh-cntr;
        d2=d2-cntr;
        //cout<<"fu"<<endl;
        int d =sum1.S-sum1.F;

        if(mark[-d]){
            tf=1;
            auto it1 = mp[-d].lower_bound(-d2);
            auto it2 = mp[-d].upper_bound(-d2);
            int x;
            int val;
            int c;
            if(it1->S+d2<it2->S+d2){
                x=it1->S+d2;
                val=it1->F;
                c=it1->S;
            }else{
                c=it2->S;
                val=it2->F;
                x=it2->S+d2;
            }
            if(x<mn){
                mn=x;
                ans={i,mp[-d][c]};
            }
        }
        //cout<<"ck"<<endl;
    }
    if(tf){
        for(int i=0;i<fh;i++){
            if(ans.S&(1<<i)){
                cout<<0;
            }else{
                cout<<1;
            }
        }
        for(int i=0;i<sh;i++){
            if(ans.F&(1<<i)){
                cout<<0;
            }else{
                cout<<1;
            }
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}
