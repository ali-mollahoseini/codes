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
int32_t main(){
    int n;
    cin>>n;
    int a=0;
    for(int i=0;i<n;i++){
        string s;int h;
        cin>>h>>s;
        if(a==0){
            if(s!="South"){
                cout<<"NO"<<endl;
                return 0;
            }else{
                a+=h;
                if(a>20000){
                    break;
                }
            }
        }else if(a==20*1000){
            if(s!="North"){
                cout<<"NO"<<endl;
                return 0;
            }else{
                a-=h;
                if(a<0){
                    break;
                }
            }
        }else if(s=="South"){
            a+=h;
            if(a>20000){
                break;
            }
        }else if(s=="North"){
            a-=h;
            if(a<0){
                break;
            }
        }
    }

    if(a==0){
        cout<<"YES"<<endl;
    }else{
        //cout<<a<<endl;
        cout<<"NO"<<endl;
    }
}
