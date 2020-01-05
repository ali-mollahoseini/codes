#include <bits/stdc++.h>
using namespace std;
#define int  long long
const int MX = 1e6+100;
int inp[MX];
int nxt[MX][2];
int32_t main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    deque<int> deq;
    pair<int,int> tp[2]= {{0, 1}, {n-1, -1}};
    for(int j = 0; j < 2; j++){
        while(deq.size())deq.pop_back();
        for(int i = tp[j].first; i != tp[!j].first + tp[j].second ; i += tp[j].second){
            while(deq.size() && deq.back() < inp[i])
                deq.pop_back();
            if(deq.size()==0)
                nxt[i][j] = -1;
            else
                nxt[i][j] = deq.front();
            deq.push_back(inp[i]);
        }
    }
    int ans = 0;
    for(int i=0; i<n;i++){
        if(nxt[i][0] > 0 && nxt[i][1] > 0)
            ans += min(nxt[i][0], nxt[i][1])-inp[i];
//        cout<<nxt[i][0]<<' '<<nxt[i][1]<<endl;
    }
    cout<<ans<<endl;
}
