#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=1000*1000;
const int MX2= 8193;
const int inf=0x7FFFFFFF;

vector<int> bin;
bool func(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first){
         return (a.first>b.first);
    }else if (a.first==b.first){
        return a.second<b.second;
    }
}
int gp[4]={7,13,21,30};
int poww(int a ,int b){
    int ans=1;
    while(b){
        ans*=a;
        b--;
    }
    return ans;
}
double ehtemal(int num){
    int tmp=num;
    double ehtem[6];
    double sum=1;
    int k=0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<4;j++){
            int a=gp[i],b=gp[j];
            int c=(tmp/poww(3,k))%3;
            int d=50-abs(a-b);
            if(c==0){//a bebare
                double kh=(double)b*(100-d);
                ehtem[k]=kh/(a+b);
            }else if(c==1){//mosavi
                ehtem[k]=d;
            }else if(c==2){//b bebare
                 double kh=(double)a*(100-d);
                ehtem[k]=kh/(a+b);
            }
            k++;
        }
    }sum= ehtem[0]/100;
    for(int i=1;i<6;i++){
        sum*=ehtem[i]/100;
    }
    return sum;
}
int main(){
    int x=729;
    double sum=0;
    for(int l=0;l<x;l++){
        double tmp=0;
        tmp = ehtemal(l);
        cout<<fixed<<setprecision(8);
        cout<<tmp<<endl;
        pair<int,int> emtiaz[4];
        emtiaz[0].first=0;emtiaz[1].first=0;emtiaz[2].first=0;emtiaz[3].first=0;
        emtiaz[0].second=7;emtiaz[1].second=13;emtiaz[2].second=21;emtiaz[3].second=30;
        sort(emtiaz,emtiaz+4,func);
        cout<<emtiaz[0].second;
        int k=0;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                int a=gp[i],b=gp[j];
                int c=(l/poww(3,k))%3;
                if(c==0){//a bebare
                    emtiaz[i].first+=3;
                }else if(c==1){//mosavi
                    emtiaz[i].first+=1;
                    emtiaz[j].first+=1;
                }else if(c==2){//b bebare
                    emtiaz[j].first+=3;
                }
                k++;
            }
        }
        sort(emtiaz,emtiaz+4,func);
        cout<<emtiaz[0].first<<" "<<emtiaz[0].second<<" "<<emtiaz[1].first<<" "<<emtiaz[1].second<<" ";
        if(emtiaz[1].second==21 || emtiaz[0].second==21){
            sum+=tmp;
        }
    }
    cout<<sum<<endl;
    ll ans=(ll)((double)sum*(double)10979*10979);
    cout<<ans;
    return 0;
}
