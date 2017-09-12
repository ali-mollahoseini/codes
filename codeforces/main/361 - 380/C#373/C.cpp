///in the name of Allah
///Ali Mollahoseini
#include <bits/stdc++.h>

#define int long long
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf= 0x7F7FFFFF;
const int MX1 = 17000;

int32_t main(){
    int n, t;string s;
    cin>>n>>t>>s;
    bool tf=1;
    bool dot=0;
    for(int i=0;i<n;i++){if(s[i]=='.'){dot=1;}}
    while(t-- && tf ){
        if(s.back()<'4'){
            tf=0;
        }else{
            s.pop_back();
            int tmp=1;
            s[s.size()-tmp]+=1;
            while(s[s.size()-tmp]>'9'&&tmp<=s.size()){
                if(dot){s.pop_back();}
                else{s[s.size()-tmp]='0',tmp++;}
                t--;
                if(s[s.size()-tmp]=='.'){s.pop_back(),dot=0;}
                s[s.size()-tmp]+=1;
            }
            if(tmp-1==s.size()){
                s.insert(s.begin(),'1');
            }
        }
    }
    cout<<s<<endl;
    return 0;
}

