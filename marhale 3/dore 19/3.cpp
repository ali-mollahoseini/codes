#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10733;
ifstream fin ("contact.in");
ofstream fout ("contact.out");

ll ar[1000];
vector<pair<int,int> > anss;
int main(){
    int cntr=0;
    for(int i=2;i<3166;i++){
        bool tf=1;
        for(int j=2;j*j<i;j++){
            if(i%j==0){
                tf=0;
                break;
            }
        }
        if(tf==1){
            ar[cntr]=i;
            cntr++;
        }
    }
    cout<<ar[30]<<endl;
    for(int i=5*1000*1000+1;i<1000*1000*10;i++){
        map<int,int> tmp;
        int x=i;
        for(int j=0;j<30;j++){
            while(x%ar[j]==0){
                tmp[ar[j]]++;
                x/=ar[j];
            }
        }
        int ans=1;
        for(map<int,int>::iterator it=tmp.begin();it!=tmp.end();it++){
            ans*=(it->second+1);
        }
        if(ans>400){
            anss.push_back({ans,i});
        }
    }
    sort(anss.begin(),anss.end());
    for(vector<pair<int,int> >::iterator it=anss.begin();it!=anss.end();it++){
        cout<<it->first<<" "<<it->second%delta<<endl;
    }
    cout<<9979200%delta<<endl;
}
