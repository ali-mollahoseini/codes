
#include <bits/stdc++.h>
#define ll long long

//const int MX1=100+10;
using namespace std;
/*int ar[MX1],n,m;
//int perm[MX1];
int find_x(int a, int b){
    int ans=0;
    if(b<=a){
        b+=n;
    }
    ans=b-a;
    return ans;
}*/
//int main(){
    //sol_b
    /*
    cin>>n>>m;
    int tmp[max(n,m)+10];
    bool tf=1;
    memset(tmp,1,m);
    for(int i=0;i<n+10;i++){
        tmp[i]=1;
    }
    for(int i=0;i<m;i++){
        cin>>ar[i];
        if(i!=0){
            int w=find_x(ar[i-1],ar[i]);
            if(tmp[w-1]){
                if(perm[ar[i-1]-1]==0){
                    tmp[w-1]--;
                    perm[ar[i-1]-1]=w;
                }else{
                    cout<<-1;
                    tf=0;
                    break;
                }
            }else{
                if(perm[ar[i-1]-1]!=w){
                    cout<<-1;
                    tf=0;
                    break;
                }
            }
        }
    }
    int cntr=0;
    for(int i=0;i<n&&tf;i++){
        if(perm[i]==0){
            while(tmp[cntr]==0){
                cntr++;
                if(cntr>n){
                    cerr<<-1;
                }
            }
            cerr<<tmp[cntr]<<endl;
            tmp[cntr]--;
            perm[i]=cntr+1;
        }else{
            cerr<<i<<" "<<perm[i]<<endl;
        }
    }
    for(int i=0;i<n&&tf;i++){
        cout<<perm[i]<<" ";
    }
    */
    //sol_d();
//}
