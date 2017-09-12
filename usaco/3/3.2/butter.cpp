/*
ID: ali.mol1
LANG: C++11
TASK: butter
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MXE =1600;
const int inf=0x7FFFFFF;
ifstream fin ("butter.in");
ofstream fout ("butter.out");
int n,p,c;
int ncow[MXE];
vector<pair<int,int> > vec[MXE];
int pointer[MXE];
int parent(int i){ return ((i+1)/2)-1; }
int right(int i){ return i*2+2; }
int left(int i){ return i*2+1; }
int total[MXE];

void heapify(pair<int,int> ar[],int a,int siz){
    int l= left(a), r= right(a);
    int smallest=0;
    if(l<siz && ar[l].first <ar[a].first ){
        smallest =  l;
    }else{
        smallest = a;
    }
    if(r<siz && ar[r].first<ar[smallest].first){
        smallest = r ;
    }
    if(smallest!=a){
        swap(pointer[smallest],pointer[a]);
        swap(ar[smallest],ar[a]);
        heapify(ar,smallest,siz);
    }
}


void build_heap(pair<int,int> ar[],int siz  ){
    for(int i= siz/2-1;i>-1;i--){
        heapify(ar,i,siz);
    }
}


pair<int,int> extract_heap(pair<int,int> ar[],int siz){
    if(siz<1){
        return {inf,inf};
    }
    pair<int,int> ans = ar[0] ;
    pointer[ar[siz-1].second]=0;
    ar[0].first=ar[siz-1].first;
    ar[0].second=ar[siz-1].second;
    ar[siz-1].first=0;
    ar[siz-1].second=0;
    heapify(ar,0,siz-1);

    return ans;
}


void dec_key(pair<int,int> ar[],int i,int key){
    //cout<<"here is the bug:)"<<endl;
    if(key>=ar[i].first){
    //cout<<"here is the bug:)"<<endl;
        return ;
    }
    ar[i].first=key;
    while(i>0 && ar[parent(i)].first>ar[i].first){
        swap(pointer[i],pointer[parent(i)]);
        swap(ar[parent(i)],ar[i]);
        i = parent(i);
            //cout<<key<<endl;
    }
}


void ins_heap(pair<int,int> ar[],int siz ,int key,int num){
    ar[siz].first=inf;
    ar[siz].second=num;
    //cout<<num<<endl;
    pointer[num]=siz;
    dec_key(ar,siz,key);
}


void dijkstra(int v){
    bool visited[MXE];
    int sum=0;
    int dis[MXE];
    for(int i=0;i<MXE;i++){
        visited[i]=0;
        dis[i]=inf;
    }
    dis[v]=0;
    pair<int,int> alist[MXE];
    visited[v]=1;
    int cur=v;
    int siz=0;
    //cout<<v<<endl;
    for(int i=1;i<p;i++){
        for(int j=0;j<vec[cur].size();j++){
            if(visited[vec[cur][j].first]==0  ){
                int w=dis[cur]+vec[cur][j].second;
                //cout<<" line 1: "<<cur<<" "<<vec[cur][j].first<<" "<<vec[cur][j].second<<endl;
                //cout<<" line 2: "<<vec[cur][j].first<< " "<<dis[vec[cur][j].first]<<endl;
                if(dis[vec[cur][j].first]==inf){
                    cout<<" line w: "<<w<<" "<<dis[cur]<<endl;;
                    ins_heap(alist,siz,w,vec[cur][j].first);
                    siz++;
                    dis[vec[cur][j].first]=w;
                }else if(w<dis[vec[cur][j].first]){
                    dec_key(alist,pointer[vec[cur][j].first],w/*,vec[cur][j].first*/);
                    dis[vec[cur][j].first]=min(dis[vec[cur][j].first],w);
                }
                //cout<<" list 0: "<<alist[0].first<<" "<<alist[0].second<<endl;
                //cout<<" list 1: "<<alist[1].first<<" "<<alist[1].second<<endl;
                //cout<<" list 2: "<<alist[2].first<<" "<<alist[2].second<<endl;
                //cout<<" list 3: "<<alist[3].first<<" "<<alist[3].second<<endl;
            }
        }
        pair<int,int> tmp=extract_heap(alist,siz);

        siz--;
        //cout<<" line 4: "<<tmp.first<<" "<<tmp.second<<endl;
        visited[tmp.second]=1;
        cur= tmp.second;
    }
    //cout<<"way way"<<endl;
    for(int i=0;i<p;i++){
        total[i]+=dis[i];
    }
}
int main(){
    fin>>n>>p>>c;
    for(int i=0;i<n;i++){
        fin>>ncow[i];
        ncow[i]--;
    }
    for(int i=0;i<c;i++){
        int tmp[3];
        fin>>tmp[0]>>tmp[1]>>tmp[2];
        tmp[0]--;tmp[1]--;
        vec[tmp[0]].push_back({tmp[1],tmp[2]});
        vec[tmp[1]].push_back({tmp[0],tmp[2]});

    }
    int mn=inf;
    for(int i=0;i<n;i++){
        dijkstra(ncow[i]);
    }
    for(int i=0;i<p;i++){
        mn=min(mn,total[i]);
        //cout<<total[i];
    }
    cout<<"ans : "<<mn<<endl;
    fout<<mn<<endl;
}
