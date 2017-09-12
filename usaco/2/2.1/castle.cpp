/*
ID: ali.mol1
LANG: C++
TASK: castle
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=53;
#define inf 1000*1000*1000
ifstream fin ("castle.in");
ofstream fout ("castle.out");
int m,n,col[MX1*MX1],mxroom,mxwall,iwall,jwall;
struct details{
    bool checked=0;
    int mark=0;
    int mx_p=0;
    char p;
};
details x[MX1][MX1];
int nummark[MX1*MX1];
map<pair<int,int>,vector<pair<int, int > > > adj;
void dfs(int vi,int vj,int rang){
    x[vi][vj].checked=1;
    x[vi][vj].mark=rang;
    for(int i=0;i<adj[{vi,vj}].size();i++){
        int fst=adj[{vi,vj}][i].first,scnd=adj[{vi,vj}][i].second;
        if(x[fst][scnd].checked==0){
            dfs(fst,scnd,rang);
        }
    }
}
int main (){
    fin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp;
            fin>>tmp;
            if(tmp%2==1){
                tmp-=1;
            }else{
                adj[{i,j}].push_back({i,j-1});
            }
            if(tmp%4==2){
                tmp-=2;
            }else{
                adj[{i,j}].push_back({i-1,j});
            }
            if(tmp%8==4){
                tmp-=4;
            }else{
                adj[{i,j}].push_back({i,j+1});
            }
            if(tmp%16==8){
                tmp-=8;
            }else{
                adj[{i,j}].push_back({i+1,j});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<adj[{i,j}].size()<<endl;
            for(int k=0;k<adj[{i,j}].size();k++){
                cout<<adj[{i,j}][k].first<<" "<<adj[{i,j}][k].second<<"       ";
            }
        }
        cout<<endl;
    }
    bool tf=1;
    int counter=1;
    while(tf){
        tf=0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(x[i][j].checked==0){
                    tf=1;
                    dfs(i,j,counter);
                    break;
                }
            }
            if(tf==1){
                break;
            }
        }
        counter++;
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<x[i][j].mark;
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            col[x[i][j].mark]++;
            mxroom=max(mxroom,col[x[i][j].mark]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            int tmp=x[i][j].mark;
            if(tmp!=x[i+1][j].mark&& i!=n-1){
                if(x[i][j].mx_p<col[x[i][j].mark]+col[x[i+1][j].mark]){
                    x[i][j].mx_p=col[x[i][j].mark]+col[x[i+1][j].mark];
                    x[i][j].p='N';
                }
            }
            if(tmp!=x[i-1][j].mark&&i!=0){
                if(x[i][j].mx_p<col[x[i][j].mark]+col[x[i-1][j].mark]){
                    x[i][j].mx_p=col[x[i][j].mark]+col[x[i-1][j].mark];
                    x[i][j].p='N';
                }
            }
            if(tmp!=x[i][j+1].mark&&j!=m-1){
                if(x[i][j].mx_p<col[x[i][j].mark]+col[x[i][j+1].mark]){
                    x[i][j].mx_p=col[x[i][j].mark]+col[x[i][j+1].mark];
                    x[i][j].p='E';
                }
            }
            if(tmp!=x[i][j-1].mark&&j!=0){
                if(x[i][j].mx_p<col[x[i][j].mark]+col[x[i][j-1].mark]){
                    x[i][j].mx_p=col[x[i][j].mark]+col[x[i][j-1].mark];
                    x[i][j].p='E';
                }
            }
            if(x[i][j].mx_p>mxwall){
                cout<<10000000;
                mxwall=x[i][j].mx_p;
                iwall=i;
                jwall=j;
            }else if(x[i][j].mx_p==mxwall){
                if(j<jwall){
                    cout<<20000000;
                    mxwall=x[i][j].mx_p;
                    iwall=i;
                    jwall=j;
                }else if(j==jwall){
                    if(i>iwall){
                    cout<<30000;
                        mxwall=x[i][j].mx_p;
                        iwall=i;
                        jwall=j;
                    }
                }
            }
        }
    }
    cout<<counter-2<<endl;
    cout<<mxroom<<endl;
    cout<<mxwall<<endl;
    cout<<iwall+1<<" "<<jwall+1<<" "<<x[iwall][jwall].p<<endl;
    fout<<counter-2<<endl;
    fout<<mxroom<<endl;
    fout<<mxwall<<endl;
    fout<<iwall+1<<" "<<jwall+1<<" "<<x[iwall][jwall].p<<endl;
    return 0;
}
