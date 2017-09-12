///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1=1000*1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int n;
int pre[MX1],in[MX1];
vector<int> post;
int findd(int x,int l1,int r1){
    for(int i=r1-1;i>=l1;i--){
        if(in[i]==x){
            return i;
        }
    }
    cout << "Bi Adab!!!!" << endl;
    return 0;//wtf!
}
void postOrder(int l, int r,int l2,int r2){
    if(l>=r || l >= n || r > n){return ;}
    int x = pre[l];
    int mid = findd(x,l2,r2);
    post.pb(x);
    int dist = mid - l2;
    postOrder(dist+l+1, r,l2+dist+1,r2);
    postOrder(l+1, dist+l+1,l2,l2+dist);
    //cout << "chert : " << l << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    postOrder(0,n,0,n);
    reverse(post.begin(),post.end());
    for(int i=0;i<n;i++){
        cout<<post[i]<<" ";
    }
    cout<<endl;
    return 0;
}
