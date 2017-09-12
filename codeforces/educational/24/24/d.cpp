#include <bits/stdc++.h>
//#define ll long long
const int MX1=1000*1000+100;
const int inf=0xFFFFFFF;
using namespace std;

int n,a;
int ar[MX1];

bool decreas(int a,int b){
    return (a>b);
}

int miz[MX1];
int mizz[MX1];
set<int> ans;
set<int> anstmp;
int cnta;

int main(){
    cin>>n>>a;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        if(ar[i]==a){
            cnta++;
        }else{
            mizz[ar[i]]++;
        }
    }
    for(int i=0;i<MX1;i++){
        if(mizz[i]>=cnta&&cnta!=0){
            //cerr<<i<<endl;
           ans.insert(i);
           anstmp.insert(i);
        }
    }
    if(cnta==0){
        int tmp=1;
        while(a==tmp){
            cerr<<1<<endl;
            tmp++;
        }
        cout<<tmp;
    }else{
        for(int i=0;i<n;i++){
            if(ar[i]==a){
                for(auto it = ans.begin() ; it != ans.end() ; it++){
                    //cerr<<2;
                    cerr<<*it<<endl;
                    if(miz[*it]!=-1){
                        miz[*it]--;
                        if(miz[*it]<0){
                            auto its=anstmp.find(*it);
                            anstmp.erase(its);
                        }
                    }
                }
                ans.clear();
                for(set<int>::iterator it = anstmp.begin() ; it != anstmp.end() ; it++){
                    ans.insert(*it);
                }
            }else{
                if(miz[ar[i]]!=-1&&mizz[ar[i]]>=cnta){
                    cerr<<777<<endl;
                    miz[ar[i]]++;
                }
            }
        }
        bool tf=0;
        for(set<int>::iterator it = ans.begin() ; it != ans.end() ; it++){
                cout<<*it;
                tf=1;
                break;
                cerr<<3<<endl;
        }
        if(tf==0){
            cout<<-1;
        }
    }
    return 0;
}
