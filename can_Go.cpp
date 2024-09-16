#include <bits/stdc++.h>

using namespace std;

const int N=10001;
vector<pair<int,long long int>>v[N];
long long int dis[N];
class cmp
{
    public:
    bool operator()(pair<int,long long int>a,pair<int,long long int>b)
    {
        return a.second>b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int,long long int>,vector<pair<int,long long int >>,cmp>pq;
    pq.push({src,0});
    dis[src]=0;
    while(!pq.empty())
    {
        pair<int,long long int>parent=pq.top();
        pq.pop();
        int node=parent.first;
       long long  int cost=parent.second;
        for(pair<int,long long int>child:v[node])
        {
            int childNode=child.first;
           long long int childCost=child.second;
            if(cost+childCost<dis[childNode])
            {
                dis[childNode]=cost+childCost;
                pq.push({childNode,dis[childNode]});
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        /* code */
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
 for (int i = 1; i <= n; i++)

 {
 dis[i] = INT_MAX;
 }
int s;
cin>>s;
 dijkstra(s);
int t;
cin>>t;
while(t--)
{
    long long int d,dw;
   cin>>d>>dw;
 if(dis[d]<=dw) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }

 return 0;

}
