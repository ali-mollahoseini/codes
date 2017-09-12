#include<iostream>
using namespace std;
int n,i,j,t,s,b,a[51][51];
bool ans;

int main()
{
cin>>n;

for(i=0;i<n;i++)
for(j=0;j<n;j++)
cin>>a[i][j];
for(i=0;i<n;i++)
for(j=0;j<n;j++){
if(a[i][j]!=1) {
ans=false;
for(t=0;t<n;t++)
for(s=0;s<n;s++)
if(a[i][j]==a[i][s]+a[t][j]) ans=true;
if(!ans){cout<<"No"; return 0;
}
}
}
 cout<<"Yes";
}
