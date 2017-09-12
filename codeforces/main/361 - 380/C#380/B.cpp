#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=1000+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFFF;
int ar[MX1][MX1],n,m,ans[MX1][MX1];
int main(){
    ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>ar[i][j];
		}
	}
	for(int i=0;i<n;i++){
		bool tf=0;
		for(int j=0;j<m;j++){
			if(tf&&ar[i][j]==0){
				ans[i][j]++;
			}else if(ar[i][j]){
				tf=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		bool tf=0;
		for(int j=m-1;j>-1;j--){
			if(tf&&ar[i][j]==0){
				ans[i][j]++;
			}else if(ar[i][j]){
				tf=1;
			}
		}
	}
	for(int i=0;i<m;i++){
		bool tf=0;
		for(int j=0;j<n;j++){
			if(tf&&ar[j][i]==0){
				ans[j][i]++;
			}else if(ar[j][i]){
				tf=1;
			}
		}
	}
	for(int i=0;i<m;i++){
		bool tf=0;
		for(int j=n-1;j>-1;j--){
			if(tf&&ar[j][i]==0){
				ans[j][i]++;
			}else if(ar[j][i]){
				tf=1;
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sum+=ans[i][j];
		}
	}
	cout<<sum<<endl;;
}
