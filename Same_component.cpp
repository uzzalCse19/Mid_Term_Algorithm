#include <bits/stdc++.h>
using namespace std; 
char ch[1001][1001];
bool vis[1001][1001];
int test=0,di,dj,n,m;
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
bool vd(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || ch[i][j]=='-') return false;
    else return true;
}
void sme_component(int si,int sj)
{
    if(si==di && sj==dj) 
    {
        cout<<"YES"<<endl;
        test=2;
    }
    vis[si][sj]=true;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(vd(ci,cj)==true && vis[ci][cj]==false) 
        {
            sme_component(ci,cj);
        }
    }
    
}
int main()
{
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ch[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj>>di>>dj;
    memset(vis,false,sizeof(vis));
   sme_component(si,sj);
   if(test==0) cout<<"NO"<<endl;
    return 0;
}