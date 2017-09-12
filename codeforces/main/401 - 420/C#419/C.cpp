/*
ID: ali.mol1
LANG: C++
TASK: humble
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=101;
const int MX2= 100*1000+10;
const int inf=2*1000*1000*1000+7;


int r,c;
int puzzle[MX1][MX1];
int mnr[MX1],mnc[MX1];
vector<pair<int,int> > rows;
vector<pair<int,int> > cols;
int sum;
void rower(){
    for(int i=0;i<r;i++){
        if(mnr[i]){
            for(int j=0;j<c;j++){
                puzzle[i][j]-=mnr[i];
            }
            rows.push_back({i,mnr[i]});
            sum+=mnr[i];
        }
    }
}
void coler(){
    for(int i=0;i<c;i++){
        if(mnc[i]){
            for(int j=0;j<r;j++){
                puzzle[j][i]-=mnc[i];
            }
            cols.push_back({i,mnc[i]});
            sum+=mnc[i];
        }
    }
}
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        mnr[i]=inf;
        for(int j=0;j<c;j++){
            int a;
            cin>>a;
            puzzle[i][j]=a;
            mnr[i]=min(mnr[i],a);
        }
    }
    if(r<c){
        for(int i=0;i<r;i++){
            mnr[i]=inf;
            for(int j=0;j<c;j++){
                mnr[i]=min(mnr[i],puzzle[i][j]);
            }
        }
        rower();
        for(int i=0;i<c;i++){
            mnc[i]=inf;
            for(int j=0;j<r;j++){
                mnc[i]=min(mnc[i],puzzle[j][i]);
            }
        }
        coler();
    }else{
        for(int i=0;i<c;i++){
            mnc[i]=inf;
            for(int j=0;j<r;j++){
                mnc[i]=min(mnc[i],puzzle[j][i]);
            }
        }
        coler();
        for(int i=0;i<r;i++){
            mnr[i]=inf;
            for(int j=0;j<c;j++){
                mnr[i]=min(mnr[i],puzzle[i][j]);
            }
        }
        rower();
    }
    bool tf=1;
    for(int i=0;i<r&&tf;i++){
        for(int j=0;j<c;j++){
            if(puzzle[i][j]!=0){
                sum=-1;
                tf=0;
                break;
            }
        }
    }
    cout<<sum<<endl;
    if(sum!=-1){
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<rows[i].second;j++){
                cout<<"row "<<rows[i].first+1<<endl;
            }
        }
        for(int i=0;i<cols.size();i++){
            for(int j=0;j<cols[i].second;j++){
                cout<<"col "<<cols[i].first+1<<endl;
            }
        }
    }
}
