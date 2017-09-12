/*
ID: ali.mol1
LANG: C++
TASK: lamps
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=200;
const int inf=1000*1000*1000;
#define inf 1000*1000*1000
ifstream fin ("lamps.in");
ofstream fout ("lamps.out");

int n,on[MX1],off[MX1],c,cntr;
bool ar[20][200];
pair<int,int> pa[16];
map<int,int> mp;

int one(int a){
    int ans=0;
    while(a){
        ans+=a%2;
        a/=2;
    }
    return ans;
}
int poww(int a,int b){
    int ans=1;
    while(b!=0){
        ans*=a;
        b--;
    }
    return ans;
}
int act(int a,int pos){
    if(a%2==1){
        for(int i=0;i<n;i++){
            ar[pos][i]=!ar[pos][i];
        }
        a-=1;
    } if(a%4==2){
        for(int i=0;i<n;i++){
            if(i%2==0){
                ar[pos][i]=!ar[pos][i];
            }
        }
        a-=2;
    }if(a%8==4){
        for(int i=0;i<n;i++){
            if(i%2==1){
                ar[pos][i]=!ar[pos][i];
            }
        }
        a-=4;
    }if(a%16==8){
        for(int i=0;i<n;i++){
            if(i%3==0){
                ar[pos][i]=!ar[pos][i];
            }
        }
        a-=8;
    }
}
int main (){
    fin>>n>>c;
    int ons=0,offs=0;
    while(1==1){
        int tmp;
        fin>>tmp;
        if(tmp==-1){
            break;
        }
        on[ons]=tmp;
        ons++;
    }
    while(1==1){
        int tmp;
        fin>>tmp;
        if(tmp==-1){
            break;
        }
        off[offs]=tmp;
        offs++;
    }
        memset(ar,1,sizeof(ar));
    for(int i=0;i<16;i++){
        bool tf=1;
        int x=one(i);
        int w=act(i,i);

        if(x>c || x%2!=c%2){
            tf=0;
        }
        for(int j=0;j<ons&&tf==1;j++){
            if(ar[i][on[j]-1]==0){
                tf=0;
                break;
            }
        }
        for(int j=0;j<offs&&tf==1;j++){
            if(ar[i][off[j]-1]==1){
                tf=0;
                break;
            }
        }
        if(tf==1){
            for(int j=0;j<n;j++){
                if(j<6){
                    pa[cntr].first=pa[cntr].first*2+ar[i][j];
                    pa[cntr].second=i;
                }
            }
            cntr++;
        }
    }
    sort(pa,pa+cntr);
    cout<<pa[0].first;
    if(cntr==0){
        fout<<"IMPOSSIBLE"<<endl;
    }else{
        for(int i=0;i<cntr;i++){
            for(int j=0;j<n;j++){
                fout<<ar[pa[i].second][j];
            }
            fout<<endl;
        }


    }
}
