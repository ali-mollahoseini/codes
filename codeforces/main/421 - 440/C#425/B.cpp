#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;

string gd,s1;
map<char,bool> good;
map<int,char> mp1,mp2;
int main(){
    cin>>gd;
    cin>>s1;
    bool tf=0;
    for(int i=0;i<s1.size();i++){if(s1[i]=='*'){tf=1;break;}}
    for(int i=0;i<gd.size();i++){good[gd[i]]=1;}
    if(tf){
        bool mood=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='?'&&mood==0){
                mp1[i]='G';
                mp2[i]='G';
            }else if(s1[i]=='?'&&mood==1){
                mp1[i]=('G');//good
                mp2[i-1]=('G');//one back
                if(i!=s1.size()-1){
                    mp2[i]=(s1[i+1]);//not back
                }
            }else if(s1[i]=='*'){
                mood=1;
                if(i!=s1.size()-1){
                    if(s1[i+1]!='?'){
                        mp2[i]=(s1[i+1]);//not back
                    }
                }
            }else if(mood==1){
                mp1[i]=(s1[i]);
                if(i!=s1.size()-1){
                    mp2[i]=(s1[i+1]);//not back
                }
            }else{
                mp1[i]=(s1[i]);
                mp2[i]=(s1[i]);
            }
        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string tmp;
            cin>>tmp;
            bool ok=1;
            if(tmp.size()==s1.size()){
                for(map<int,char>  ::iterator it=mp1.begin();it!=mp1.end();it++){
                    if(it->second=='G'){
                        if(good[tmp[it->first]]==0){
                            ok=0;break;
                        }
                    }else{
                        if(tmp[it->first]!=it->second){
                            ok=0;break;
                        }
                    }
                }
            }else if(tmp.size()==s1.size()-1){
                for(map<int,char > ::iterator it=mp2.begin();it!=mp2.end();it++){
                    if(it->second=='G'){
                        if(good[tmp[it->first]]==0){
                            //cerr<<2<<endl;
                            ok=0;
                            break;
                        }
                    }else{
                        if(tmp[it->first]!=it->second){
                            //cerr<<3<<" "<<it->first<<endl;
                            ok=0;
                            break;
                        }
                    }
                }
            }else{
                ok=0;
            }
            if(!ok){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
    }else{
        //cerr<<"s";
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='?'){
                mp1[i]=('G');
            }else{
                mp1[i]=(s1[i]);
            }
        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string tmp;
            cin>>tmp;
            bool ok=1;
            if(tmp.size()==s1.size()){
                for(map<int,char>  ::iterator it=mp1.begin();it!=mp1.end();it++){
                    if(it->second=='G'){
                        if(good[tmp[it->first]]==0){
                            ok=0;
                        }
                    }else{
                        if(tmp[it->first]!=it->second){
                            ok=0;
                        }
                    }
                }
            }else{
                ok=0;
            }
            if(!ok){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
    }
}
