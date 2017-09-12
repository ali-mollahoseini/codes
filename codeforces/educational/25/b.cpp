//in the name of Allah
#include <iostream>
#define ll long long
const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;

using namespace std;

int ar[20][20];
bool ans=0;
int main(){
    for(int i=0;i<12;i++){
        ar[0][i]=3;
        ar[i][0]=3;
        ar[11][i]=3;
        ar[i][11]=3;
    }
    for(int i=0;i<10;i++){
        string s;
        cin>>s;
        for(int j=0;j<10;j++){
            if(s[j]=='X'){
                ar[i+1][j+1]=1;
            }else if( s[j]=='O'){
                ar[i+1][j+1]=2;
            }
        }
    }
    for(int i =1;i<11;i++){
        for(int j=1;j<11;j++){
            if(ar[i][j]!=2){
                bool tf=1;
                int sum=0;
                for(int k=0;k<5;k++){
                    if(ar[i][j+k]==2){
                        tf=0;
                        break;
                    }
                    if(ar[i][j+k]==3){
                        tf=0;
                        break;
                    }
                    if(ar[i][j+k]==1){
                        sum++;
                    }
                }
                if(sum!=4){
                    tf=0;
                }
                if(tf==1){
                    ans=1;
                }
                sum=0;
                tf=1;
                for(int k=0;k<5;k++){
                    if(ar[i+k][j]==2){
                        tf=0;
                        break;
                    }
                    if(ar[i+k][j]==3){
                        tf=0;
                        break;
                    }
                    if(ar[i+k][j]==1){
                        sum++;
                    }
                }
                if(sum!=4){
                    tf=0;
                }
                if(tf==1){
                    ans=1;
                }
                sum=0;
                tf=1;
                for(int k=0;k<5;k++){
                    if(ar[i+k][j+k]==2){
                        tf=0;
                        break;
                    }
                    if(ar[i+k][j+k]==3){
                        tf=0;
                        break;
                    }
                    if(ar[i+k][j+k]==1){
                        sum++;
                    }
                }
                if(sum!=4){
                    tf=0;
                }
                if(tf==1){
                    ans=1;
                }
                sum=0;
                tf=1;
                for(int k=0;k<5;k++){
                    if(ar[i-k][j+k]==2){
                        tf=0;
                        break;
                    }
                    if(ar[i-k][j+k]==3){
                        tf=0;
                        break;
                    }
                    if(ar[i-k][j+k]==1){
                        sum++;
                    }
                }
                if(sum!=4){
                    tf=0;
                }
                if(tf==1){
                    ans=1;
                }
            }
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
