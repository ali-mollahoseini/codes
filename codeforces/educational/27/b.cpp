//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
string str[MX1];
int32_t main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    bool tf=1,r=0,g=0,b=0;
    if(n%3 == 0){
        vector<char> tt;
        char def= str[0][0];
        tt.pb(def);
        for(int i=0;i<n/3;i++){
            for(int j =0;j<m;j++){
                if(str[i][j]!=def){
                    tf=0;
                }
            }
        }
        def= str[n/3][0];
        tt.pb(def);
        if(def==tt[0]){
            tf=0;
        }
        for(int i=n/3;i<n/3*2;i++){
            for(int j =0;j<m;j++){
                if(str[i][j]!=def){
                    tf=0;
                }
            }
        }
        def= str[n/3*2][0];
        if(def==tt[0]){
            tf=0;
        }
        if(def==tt[1]){
            tf=0;
        }
        for(int i=n/3*2;i<n;i++){
            for(int j =0;j<m;j++){
                if(str[i][j]!=def){
                    tf=0;
                }
            }
        }
    }else{
        tf=0;
    }
    if(tf){
        cout<<"YES"<<endl;
        return 0;
    }
    tf=1;
    if(m%3 == 0){
        vector<char> tt;
        char def= str[0][0];
        tt.pb(def);
        for(int i=0;i<n;i++){
            for(int j =0;j<m/3;j++){
                if(str[i][j]!=def){
                    tf=0;
                }
            }
        }
        def= str[0][m/3];
        tt.pb(def);
        if(def==tt[0]){
            tf=0;
        }
        for(int i=0;i<n;i++){
            for(int j =m/3;j<m/3*2;j++){
                if(str[i][j]!=def){
                    tf=0;
                }
            }
        }
        def= str[0][m/3*2];
        if(def==tt[0]){
            tf=0;
        }
        if(def==tt[1]){
            tf=0;
        }
        for(int i=0;i<n;i++){
            for(int j = m/3*2;j<m;j++){
                if(str[i][j]!=def){
                    tf=0;
                }
            }
        }
    }else{
        tf=0;
    }
    if(tf){
        cout<<"YES"<<endl;
        return 0;
    }else{
        cout<<"NO"<<endl;
        return 0;
    }
}
