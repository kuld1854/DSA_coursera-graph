// number of cycle in  undirected graph
#include <bits/stdc++.h>
#define fr(k,l) for(int i=k;i<l; i++)
using namespace std;
bool explore(vector<vector<int>> list,bool visited[],int x,bool checked[]){
    visited[x] = true;
    checked[x] = true;
    for(auto it = list[x].begin(); it<list[x].end(); it++){
             if( visited[*it] == true && checked[*it] == true)
                           {  checked[*it] = true; 
                              return false;
                           }
             if(visited[*it]==false)
                  if( !explore(list,visited,*it,checked))
                             return false;
    }
    checked[x] = false;
    return true;
}
int main(){
    int v,e,x,y,count=0;
    cin>>v>>e;
    vector<vector<int>> list(v);
    fr(0,e){
           cin>>x>>y;
           list[x-1].push_back(y-1);      
    }
      bool visited[v] = {false};
      bool checked[v] = {false};
    fr(0,v){
         if(visited[i]==false){
          if(!explore(list,visited,i,checked)){
                   cout<<"1"<<endl;
                   return 0;
          }
         }
          }
     cout<<"0"<<endl;
     return 0;

}