/*
ID: ali.mol1
LANG: C++
TASK: maze1
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
const int MX1=101;
const int MX2= 39;
const int inf=1000*1000*1000;
ifstream fin ("maze1.in");
ofstream fout ("maze1.out");
int   ans[MX1][MX2];
bool visited[MX1][MX2][2];
bool seen[MX1][MX2][2];
int   dis[MX1][MX2][2];
pair<int,int> source[2];
int w,h;
pair<int ,int> out[2];

map<pair<int,int>,vector<pair<int,int> > > mp;
void dijkstra(int mn);
void inp(){
    fin>>w>>h;
    int mn=0;
    char x[200];
    fin.getline(x,256);
    for(int i=0;i<2*h+1;i++){
        char tmp[2*w+1];
        fin.getline(tmp,256);
        for(int j=0;j<2*w+1;j++){
            if(i==0 || i==2*h || j==2*w || j==0){
                if(tmp[j]==' '){
                    if(j==0){
                        visited[(i+1)/2-1][0][mn]=1;
                        source[mn]={(i+1)/2-1,0};
                        dis[(i+1)/2-1][0][mn]=1;
                        mn++;
                    }else if(i==0){
                        visited[0][(j+1)/2-1][mn]=1;
                        source[mn]={0,(j+1)/2-1};
                        dis[0][(j+1)/2-1][mn]=1;
                        mn++;
                    }else{
                        visited[(i+1)/2-1][(j+1)/2-1][mn]=1;
                        source[mn]={(i+1)/2-1,(j+1)/2-1};
                        dis[(i+1)/2-1][(j+1)/2-1][mn]=1;
                        mn++;
                    }
                }
            }else if(i%2!=j%2){
                if(tmp[j]==' '){
                    if(j%2==0 ){
                        mp[{(i/2),(j/2)-1}].push_back({(i/2),(j/2)});
                        mp[{(i/2),(j/2)}].push_back({(i/2),(j/2)-1});
                    }else if(j%2==1){
                        mp[{(i/2)-1,(j/2)}].push_back({(i/2),(j/2)});
                        mp[{(i/2),(j/2)}].push_back({(i/2)-1,(j/2)});
                    }
                }
            }

        }
    }
}
int main (){
    for(int i=0;i<MX1;i++){
        for(int j=0;j<MX2;j++){
            dis[i][j][0]=inf;
            dis[i][j][1]=inf;
        }
    }
    inp();
    dijkstra(0);
    dijkstra(1);
    int mx=-1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
           // cout<<dis[i][j][0]<<" ";
            ans[i][j]=min(dis[i][j][0],dis[i][j][1]);
        }
        //cout<<endl;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            //cout<<ans[i][j]<<" ";
            mx=max(ans[i][j],mx);
        }
        //cout<<endl;
    }
    fout<<mx<<endl;
}
void dijkstra(int mn){
    bool tf=1;
    for(int i=0;tf;i++){
        tf=0;
        for(int j =0;j<h;j++){
            for(int k =0;k<w;k++){
                if(visited[j][k][mn]==1&&seen[j][k][mn]==0){
                    for(vector<pair<int,int> >::iterator it= mp[{j,k}].begin();it!=mp[{j,k}].end();it++){
                        int ii=it->first,jj=it->second;
                        //cout<<j<<" "<<k<<"   "<<ii<<" "<<jj<<endl;
                        if(dis[ii][jj][mn]>dis[j][k][mn]+1){
                            visited[ii][jj][mn]=1;
                            dis[ii][jj][mn]=dis[j][k][mn]+1;
                            //cout<<dis[ii][jj][mn]<<" "<<dis[j][k][mn]+1<<endl;
                        }
                    }
                    seen[j][k][mn]=1;
                }else if(visited[j][k][mn]==0){
                    tf=1;
                }
            }
        }
    }
}
