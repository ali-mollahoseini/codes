/*
ID: ali.mol1
LANG: C++
TASK: fracdec
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#define MAXN 100000

using namespace std;

bool visited[MAXN];
int mod[MAXN];

string itoa(int n)
{
    if(n==0) return "0";
    string ans="";
    while(n)
    {
        ans+=(n%10+'0');
        n=n/10;
    }
    reverse(ans.begin(),ans.end());;//字符串反转函数
    return ans;
}

int main()
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    string ans,t;
    int n,m,cnt,p,i;
    while(cin>>n>>m)
    {
        memset(visited,false,sizeof(visited));
        ans=itoa(n/m);
        ans+='.';
        p=ans.length();
        n=n%m;
        cnt=1;
        if(n==0)
        {
            ans+='0';
            cout<<ans<<endl;
            continue;
        }
        while(n)
        {
            if(!visited[n])
            {
                mod[cnt++]=n;
                visited[n]=true;
                ans+=itoa(n*10/m);
                n=n*10%m;
            }
            else
            {
                ans+=')';
                for(i=cnt-1;i>=1;i--)
                    if(mod[i]==n) break;
                ans.insert(i+p-1,"(");
                break;
            }
        }
        for(i=0;i<ans.length();i++)
        {
            cout<<ans[i];
            if((i+1)%76==0)cout<<endl;
        }
        if((i+1)%76!=0) cout<<endl;
    }
    return 0;
}
