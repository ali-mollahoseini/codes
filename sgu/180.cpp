//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int out[MX1],inp[MX1],n, sum;
void unify(int fst,int lst){
    int mid=(fst+lst)/2, pt1=fst, pt2=mid, cnt=fst;
    while(pt1<mid || pt2<lst){
        int val1 = (pt1<mid?inp[pt1]:inf);
        int val2 = (pt2<lst?inp[pt2]:inf);
        if(val2<val1){
            //cerr<<sum<<" "<<pt1<<" "<<pt2<<" "<<pt2-pt1<<endl;
            sum+=mid-pt1;
            out[cnt++]=inp[pt2++];
        }else{
            out[cnt++]=inp[pt1++];
        }
    }
    for(int i = fst; i < lst; i++){
        inp[i] = out[i] ;
    }
}
void mergeSort(int fst, int lst){
    if(fst == lst - 1) return ;
    int mid = (fst + lst) / 2;
    mergeSort(fst, mid);
    mergeSort(mid, lst);
    unify(fst, lst);
}
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    mergeSort(0,n);
    cout<<sum<<endl;
    /*for(int i=0;i<n;i++){
        cerr<<inp[i]<<" ";
    }*/
}

