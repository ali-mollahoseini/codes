#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000*1000;

vector<int> fibo;

int aza[6];
int check(){
    int a=1<<6;
    bool sums[101];
    for(int i=0;i<101;i++){
        sums[i]=0;
    }
    int cntr=0;
    for(int i=0;i<a;i++){
        int tmp=i;
        int sum=0;
        for(int j=0;j<6;j++){
            bool tf=tmp%2;
            tmp/=2;
            if(tf==1){
                sum+=aza[j];
            }
        }
           // cout<<sum;
        if(sums[sum]==0){
            cntr++;
            sums[sum]=1;
        }
    }
    return cntr;
}
int main() {
    int mx=0;
    for(int a=10;a<25;a++){
        for(int b=10;b<25;b++){
            for(int c=10;c<25;c++){
                if(a+b+c<=70){
                    for(int d=10;d<25;d++){
                        if(a+b+c+d<=80){
                            for(int e=10;e<25;e++){
                                if(a+b+c+d+e<=90){
                                    for(int f=10;f<25;f++){
                                        if(a+b+c+d+e+f==100){
                                            aza[0]=a;
                                            aza[1]=b;
                                            aza[2]=c;
                                            aza[3]=d;
                                            aza[4]=e;
                                            aza[5]=f;
                                            //cout<<1;
                                            int ways=check();
                                            mx=max(ways,mx);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<mx*mx*mx%delta;
    return 0;
}
