#include <bits/stdc++.h>
using namespace std;
const int N=10001;
long long int dis[N];
class Edge
{
    public:
    int u,v;
    long long int c;
    Edge(int u,int v,long long int c)
    {
        this->c=c;
        this->u=u;
        this->v=v;
    }
};
int main()
{
    int n,e;
    vector<Edge>EdgeList;
    cin>>n>>e;
    while(e--)
    {
int u,v;
long long int c;
cin>>u>>v>>c;
EdgeList.push_back(Edge(u,v,c));
    }
    int s;
    cin>>s;
    for(int i=1;i<=n;i++) dis[i]=LONG_LONG_MAX;
     dis[s]=0;
    for(int i=0;i<n;i++)
    {
        for(Edge ed:EdgeList)
        {
            int u,v;
            long long int c;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u]<LONG_LONG_MAX && dis[u]+c<dis[v])
            {
                dis[v]=dis[u]+c;
            }
        }
    }
   //for(int i=1;i<=n;i++) cout<<i<<">"<<dis[i]<<endl;
    int t;
    cin>>t;
    bool cycle =false;
    for(Edge ed:EdgeList)
        {
            int u,v;
            long long int c;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u]<LONG_LONG_MAX && dis[u]+c<dis[v])
            {
                cycle=true;
                break;
            }
        }
        int d[t];
        for(int i=0;i<t;i++)
        {
            cin>>d[i];
        }
        if(cycle) cout<<"Negative Cycle Detected"<<endl;
        else
        {
             for(int des:d)
             {
                //cout<<des<<" ";
                if(dis[des]==LONG_LONG_MAX) cout<<"Not Possible"<<endl;
                else cout<<dis[des]<<endl;
             }
        }
        return 0;
}