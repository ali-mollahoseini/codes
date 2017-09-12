#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=1000*100+100;
const int MX2= 1000*1000+100;
const int inf=2*1000*1000*100;
pair<int,int> ar[MX1];
int n;

int main(){
    cin>>n;
    int last;
    for(int i=0;i<n;i++){
        cin>>ar[i].first;
        ar[i].second=i;
    }
    sort(ar,ar+n);
    last=n;
    //cout<<n<<endl;
    for(int i=0;i<n;i++){
        if(ar[last-1].second==i){
            cout<<last<<" ";
            int cntr=1;
            while(ar[last-cntr-1].second<i &&last-cntr-1>-1){
                cout<<last-cntr<<" ";
                cntr++;
            }
            last=last-cntr;
            cout<<endl;
        }else{
            cout<<endl;
        }
    }
}
