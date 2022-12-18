// dfs 
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
    int v,e,x,y;
    cin>>v>>e;
    vector<vector<int>> list(v);
    fr(0,e){
           cin>>x>>y;
           list[x-1].push_back(y-1);
           list[y-1].push_back(x-1);      
    }
      cin>>x>>y;
    bool visited[v] = {false};
    explore(list,visited,x-1);
    if(visited[y-1] == true)
         cout<<"1"<<endl;
    else
          cout<<"0"<<endl;
    

}