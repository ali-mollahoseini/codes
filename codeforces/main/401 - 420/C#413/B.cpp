#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=101;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000;
map<int,int> a,b,c;
int ar[MX2];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=0,tmp;i<n;i++){
        cin>>tmp;
        if(tmp==1){
            a[ar[i]]=1;
        }else if(tmp==2){
            b[ar[i]]=1;
        }else if(tmp==3){
            c[ar[i]]=1;
        }
    }
    for(int i=0,tmp;i<n;i++){
        cin>>tmp;
        if(tmp==1){
            a[ar[i]]=1;
        }else if(tmp==2){
            b[ar[i]]=1;
        }else if(tmp==3){
            c[ar[i]]=1;
        }
    }
    int q;
    cin>>q;
    for(int i=0,tmp;i<q;i++){
        cin>>tmp;
        if(tmp==1){
            int p=a.begin()->first;
            a.erase(a.begin()->first);
            b.erase(p);
            c.erase(p);
            if(p==0){
                cout<<-1<<" " ;
                continue;
            }
            cout<<p<< " ";
        }else if(tmp==2){
            int p=b.begin()->first;
            b.erase(b.begin()->first);
            a.erase(p);
            c.erase(p);
            if(p==0){
                cout<<-1<< " ";
                continue;
            }
            cout<<p<<" ";
        }else{
            int p=c.begin()->first;
            c.erase(c.begin()->first);
            a.erase(p);
            b.erase(p);
            if(p==0){
                cout<<-1<< " ";
                continue;
            }
            cout<<p<<" ";
        }
    }
    cout<<endl;
}
