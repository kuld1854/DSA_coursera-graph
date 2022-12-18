// to check bipartite
// give tle
#include <bits/stdc++.h>
#define fr(k,l) for(int i=k;i<l; i++)
using namespace std;
bool bfs(vector<vector<int>> graph , int v , int j,bool visit[]){
   int dis[v];
    fr(0,v)
         dis[i] = INT32_MAX;
    queue<int> q;
    q.push(j);
    dis[j] = 0;
    visit[j] = true;
    while(!q.empty()){
          int in = q.front();
          q.pop();
          for( auto it = graph[in].begin(); it< graph[in].end(); it++){
                   if(dis[*it] == INT32_MAX){
                           dis[*it] =dis[in]+1;
                            q.push(*it);
                            visit[*it] = true;
                        }
                     else if (dis[*it] == dis[in])
                           return false;
                                  
          }
    }
    return true;
}
int main(){
    int v,e,x,y;
    cin>>v>>e;
    vector<vector<int>> graph(v);
    fr(0,e){
           cin>>x>>y;
           graph[x-1].push_back(y-1);
           graph[y-1].push_back(x-1);      
    }
      bool visit[v] = {false};
      bool ans = true;
    fr(0,v){
    if(visit[i]==false)
         if( bfs(graph,v,i,visit) == false )
            {    cout<<"0"<<endl;
                  ans = false; 
                 break;
           }
         }
      if(ans)
         cout<<"1"<<endl;
}