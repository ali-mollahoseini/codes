//be name khoda
//8)
//;)

#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back

const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;

using namespace std;
string s,t;
bool used[26][2];
map<char,char> adj;
int32_t main(){
    cin>>s>>t;
    int n=s.size();
    int et=0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            if(used[(int)s[i]-'a'][0]==0&& used[(int)t[i]-'a'][0]==0){
                adj[s[i]]=t[i];
                adj[t[i]]=s[i];
                used[(int)s[i]-'a'][0]=1;
                used[(int)t[i]-'a'][0]=1;
            }else if(adj[s[i]]==t[i]&&adj[t[i]]==s[i]){
            }else {
                cout<<"-1"<<endl;
                return 0;
            }
        }else{
            if(used[(int)s[i]-'a'][0]==1&&adj[s[i]]!=s[i]){
                cout<<"-1"<<endl;
                return 0;
            }
            if(used[(int)s[i]-'a'][0]==0){
                used[(int)s[i]-'a'][0]=1;
                used[(int)s[i]-'a'][1]=1;
                adj[s[i]]=s[i];
                et++;
            }
        }
    }
    cout<<(adj.size()-et)/2<<endl;;
    for(auto c: adj){
        if(used[(int)c.F-'a'][1]==0){
            cout<<c.F<<" "<<c.S<<endl;
            used[(int)c.F-'a'][1]=1;
            used[(int)c.S-'a'][1]=1;
        }else{
            continue;
        }
    }
    return 0;
}
