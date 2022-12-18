// topological sorting
// giving tle
#include <bits/stdc++.h>
#define fr(k,l) for(int i=k;i<l; i++)
using namespace std;
void explore(vector<vector<int>> list,bool visited[],int x,vector<int> &vect){
    visited[x] = true;
    for(auto it = list[x].begin(); it<list[x].end(); it++){
             if(visited[*it]==false)
                   explore(list,visited,*it,vect);
    }
    vect.push_back(x+1);
}
int main(){
    int v,e,x,y;
    cin>>v>>e;
    vector<vector<int>> list(v);
    fr(0,e){
           cin>>x>>y;
           list[x-1].push_back(y-1);
           
    }
      cin>>x>>y;
    bool visited[v] = {false};
    vector<int> vect;
   fr(0,v){
         if(visited[i]==false){
          explore(list,visited,i,vect);
          }
          }
    for(auto it = vect.end()-1; it>=vect.begin();  it--)
           cout<<*it<<" ";
    cout<<endl;

}