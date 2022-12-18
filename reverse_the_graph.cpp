// for directed graph
#include <bits/stdc++.h>
#define fr(k,l) for(int i=k;i<l; i++)
using namespace std;
int main(){
    int v,e,x,y;
    cin>>v>>e;
    vector<vector<int>> graph(v);
    vector<vector<int>> rev_graph(v);
    fr(0,e){
           cin>>x>>y;
           graph[x-1].push_back(y-1);
           
    }
    fr(0,v){
          for(auto it = graph[i].begin(); it<graph[i].end(); it++){
                        rev_graph[*it].push_back(i);
                        cout<<(*it)+1<<" "<<i+1<<endl;
          }
     }

}