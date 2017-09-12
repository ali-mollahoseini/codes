#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFFF;
int n,m,ar[1000][1000];
pair<int,int> pos;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string tmp;
		cin>>tmp;
		for(int j=0;j<m;j++){
			if(tmp[i]=='S'){
				ar[i][j]=1;
			}else if(tmp[i]=='T'){
				pos.first=i;pos.second=j;
			}else if(tmp[i]=='*'){
				ar[i][j]=2;
			}
		}
	}
	for(int i=0;i<)
}
