//in the name of god
// part a
#include <iostream>
#define ll long long
const int inf= 0x7FFFFFFF;
const int MX1=100+10;
using namespace std;
int mtrix[MX1][MX1];
int n,k;
void maker(int row,int rem){
    if(rem==0)return;
    rem--;
    mtrix[row][row]=1;
    int x=row+1;
    while(rem>1 && x<n ){
        rem-=2;
        mtrix[row][x]=1;
        mtrix[x][row]=1;
        x++;
    }
    row++;
    if(row<n){
        maker(row,rem);
    }else{
        return;
    }
}

int main(){
    cin>>n>>k;
    if(k<=n*n){
        maker(0,k);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mtrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<-1<<endl;
    }
}
