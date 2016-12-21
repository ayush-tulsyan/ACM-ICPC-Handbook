#include "template.h"

// Array u acts as visited bool array, d stores DFN No., low
// stores lowest DFN no reachable, par stores parent node's DFN no.

int gl = 0;
const int N = 10010;
int u[N],d[N],low[N],par[N];
vi G[N];
void dfs1(int node,int dep){ //find dfs_num and dfs_low
  u[node]=1;
  d[node]=dep;low[node]=dep;
  for(int i = 0; i < G[node].size(); i++){
    int it = G[node][i];
    if(!u[it]){
      par[it]=node;
      dfs1(it,dep+1);
      low[node]=min(low[node],low[it]);
      /*if(low[it] > d[node] ){
          node-it is cut edge/bridge
      }*/
      /*
      if(low[it] >= d[node] && (par[node]!=-1 || sz(G[node]) > 2)){
          node is cut vertex/articulation point
      }
      */
    }else if(par[node]!=it) low[node]=min(low[node],low[it]); 
    else par[node]=-1;
  }
}
int main(){
  return 0;
}