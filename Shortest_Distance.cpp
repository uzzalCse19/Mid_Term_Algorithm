#include <bits/stdc++.h>

using namespace std;
const long long INF=1e18;
int main()
{
    // Write your code here
   long long int n,e;
  
    cin>>n>>e;
     long long int adj[n+1][n+1];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) adj[i][j]=0;
            else adj[i][j]=INF;
        }
    }

    while(e--)
    {
        int a,b;
        long long int w;
        cin>>a>>b>>w;
        adj[a][b]=min(w,adj[a][b]);

    }
    for(int k=1;k<=n;k++)
    {
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=n;j++)
             {
                if(adj[i][k]+adj[k][j]<adj[i][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
             }
         }
    }
    
int t;
cin>>t;
while(t--)
{
    int x,y;
    cin>>x>>y;
    if(adj[x][y]==INF) cout<<"-1"<<endl;
    else cout<<adj[x][y]<<endl;
}
    return 0;
}
