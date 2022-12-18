// number of scc
// giving tle
#include <bits/stdc++.h>
#define fr(k,l) for(int i=k;i<l; i++)
using namespace std;
void explore(vector<vector<int>> graph,bool visited[],int x,vector<int> &post){
    visited[x] = true;
    for(auto it = graph[x].begin(); it<graph[x].end(); it++){
             if(visited[*it]==false)
                   explore(graph,visited,*it , post);
    }
    post.push_back(x);
}
void explore(vector<vector<int>> graph,bool visited[],int x){
    visited[x] = true;
    for(auto it = graph[x].begin(); it<graph[x].end(); it++){
             if(visited[*it]==false)
                   explore(graph,visited,*it);
    }
}
int main(){
    int v,e,x,y;
    cin>>v>>e;
    vector<vector<int>> graph(v);
    vector<vector<int>> rev_graph(v);
    fr(0,e){
           cin>>x>>y;
           graph[x-1].push_back(y-1);
           rev_graph[y-1].push_back(x-1);      
    }
    bool visited[v] = {false};
    vector<int> post;
   fr(0,v){
         if(visited[i]==false){
          explore(rev_graph,visited,i,post);
          }
          }
    fr(0,v)
          visited[i] = false;
   int count = 0;   
   fr(0,v){
          if(visited[post[v-i-1]] == false){
                    count++;
                    explore(graph,visited ,post[v-i-1]);
          } 
         }

       cout<<count<<endl;

}