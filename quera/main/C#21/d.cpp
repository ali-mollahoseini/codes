//in the name of Allah
#include <iostream>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x77FFFFFF;
const int MX1 = 200*1000+1000;
const int mod = 1000*1000*1000+7;
using namespace std;

pair<bool,bool> r[MX1][26],l[MX1][26];
pair<bool,bool> cur[26];
pair<char,char> inp[MX1];
int maker(int lft,int rgt){
    int ans=26;lft-=2;
    for(int i=0;i<26;i++){
        int sum = 0;
        sum += ((r[rgt][i].F | l[lft][i].F)==1) ;
        sum += ((r[rgt][i].S | l[lft][i].S)==1) ;
        ans -= (sum == 2);
    }
    return ans;
}
int poww(int a,int p){
    if(p==0){
        return 1;
    }
    int ans=poww(a,p/2);
    if(a%2==1){ans = (ans*a)%mod;}
    return ans;
}
int32_t main(){
    int n, q;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i].F>>inp[i].S;
    }
    for(int i=0;i<n;i++){
        char a, b;
        for(int j=0;j<26;j++){
            l[i][j].F = l[min(0,i-1))][j].F;
            l[i][j].S= l[min(0,i-1))][j].S;
        }
        ci>>a>>b;
        l[i][(int)a-'a'].F=1;
        l[i][(int)a-'a'].F=1;

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){

        }
    }
    cin >> q;
    for(int i=0;i<)
}
