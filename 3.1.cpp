// find shortest distance between two vartex
#include <bits/stdc++.h>
#define fr(k,l) for(int i=k;i<l; i++)
using namespace std;
int bfs(vector<vector<int>> graph , int v , int j , int target){
   if( j == target)
          return 0;
   int dis[v];
    fr(0,v)
         dis[i] = INT32_MAX;
    queue<int> q;
    q.push(j);
    dis[j] = 0;
    while(!q.empty()){
          int in = q.front();
          q.pop();
          for( auto it = graph[in].begin(); it< graph[in].end(); it++){
                   if(dis[*it] == INT32_MAX){
                           dis[*it] =dis[in]+1;
                            q.push(*it);
                           // cout<<*it<<" "<<dis[*it]<<endl;
                           if(*it == target)
                                 return dis[*it];
                          }
    }
    }
    return -1;
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
        cin>>x>>y;
     cout<<bfs(graph,v,x-1,y-1)<<endl;
}