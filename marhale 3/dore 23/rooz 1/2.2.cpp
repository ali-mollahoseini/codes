#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=10271;
vector<int> row;
int cntr;
int sum[7];
int  poww(int a,int b){
    int ans=1;
    while(b){
        ans*=a;
        b-=1;
    }
    return ans;
}
void make(int n){

    if(n>0 && n<4){
        bool tf=1;
        for(int i=0; i<7; i++){
            if(sum[i]>3){
                tf=0;
            }
        }
        if(tf==0){
            //cout<<cntr<<" ";
        }
        if(tf==1 && n==1){
            for(int i=0; i<35; i++){
                    int tmp[7];
                for(int j=0; j<7; j++){
                    tmp[j]=sum[j]+(row[i]/poww(2,j))%2;
                }
                bool tff=1;
                for(int j=0; j<7; j++){
                    if(tmp[j]!=3){
                        tff=0;
                        break;
                    }
                }
                if(tff==0){
                    continue;
                }
                for(int j=0; j<7; j++){
                    sum[j]-=(row[i]/poww(2,j))%2;
                }
                if(tff){
                    cntr++;
                }
            }
        }else if(tf==1){
            //cout<<1<<" "<<n<<endl;
            for(int i=0; i<35; i++){
                for(int j=0; j<7; j++){
                    sum[j]+=(row[i]/poww(2,j))%2;
                }
                make(n-1);
                for(int j=0; j<7; j++){
                    sum[j]-=(row[i]/poww(2,j))%2;
                }
            }
        }
    }else if(n>=4){
        for(int i=0; i<35; i++){
            //cout<<row[i]<<endl;
            for(int j=0; j<7; j++){
                sum[j]+=(row[i]/poww(2,j))%2;
            }
            make(n-1);
            for(int j=0; j<7; j++){
                sum[j]-=(row[i]/poww(2,j))%2;
            }
        }
    }
    return ;
}

int adad(int a){
    int ans=0;
    while(a){
        ans+=a%2;
        a/=2;
    }
    return ans;
}
int main()
{
    for(int i=0; i<128; i++){
        if(adad(i)==3){
            row.push_back(i);
        }
    }
    make(7);
    cout<<cntr;
}
