                                 /* ...Bismillahir Rahmanir Raheem... */

#include<bits/stdc++.h>
using namespace std;
vector<int>keep[1000];
vector<int>vis(1000),level(1000),order;
void bfs(int s)
{
     queue<int>q;
     q.push(s);
     vis[s]=1;
     while (!q.empty())
     {
          int cur=q.front();
          q.pop();
          order.push_back(cur);
          for(int child: keep[cur])
          {
               if(!vis[child])
               {
                    q.push(child);
                    vis[child]=1;
                    level[child]=level[cur]+1;
               }
          }
     }     
}

int main()
{
     int n; cin>>n;
     for(int i=0; i<n-1; i++ )
     {
          int u,v; cin>>u>>v;
          keep[u].push_back(v);
          keep[v].push_back(u);
     }
     bfs(1);
     for(auto x: order){
          cout<<x<<" ";
     }
     cout<<endl;
     for(int i=1; i<=n; i++)
     {
          cout<<i<< " : " << "Level-> " <<level[i] <<endl;
     }
     

}