//in the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;


const int mod=1000*1000*1000+7;
const int MX1=1000+100;
const int MX2= 2000+100;
const int inf=2*1000*1000*1000*1000*1000*1000;

int n,k,m;
int  a[MX1];
int  b[MX2];
int  man,
bool check(int lmid,int nmid){


}
int main(){
    cin>>n>>m>>k;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0 ; i<(n+n-1)/k ; i++){
        if(a[i*k+k-1]<i){
            cout<<-1;
            return 0;
        }
    }
    for(int i =0;i<k;i++){
        cin>>b[i];
    }
    sort(b,b+n,greater<int>());
    int last,lstmid,first;
    while(first<last){
        int mid=(last+first)/2;
        if(check(first,mid)){
            first=mid;
        }else{
            last=mid-1;
        }
    }
    cout<<first+1;
}
