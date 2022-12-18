// number of component in graph
#include <bits/stdc++.h>
#define fr(k,l) for(int i=k;i<l; i++)
using namespace std;
void explore(vector<vector<int>> list,bool visited[],int x){
    visited[x] = true;
    for(auto it = list[x].begin(); it<list[x].end(); it++){
             if(visited[*it]==false)
                   explore(list,visited,*it);
    }
}
int main(){
    int v,e,x,y,count=0;
    cin>>v>>e;
    vector<vector<int>> list(v);
    fr(0,e){
           cin>>x>>y;
           list[x-1].push_back(y-1);
           list[y-1].push_back(x-1);      
    }
      bool visited[v] = {false};
    fr(0,v){
         if(visited[i]==false){
          explore(list,visited,i);
           count++;
         }
          }
     cout<<count<<endl;
     return 0;

}