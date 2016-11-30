#include "template.h"

// This function runs Prim's algorithm for constructing minimum
// weight spanning trees.
//
// Running time: O(|V|^2)
//
//   INPUT: w[i][j] = cost of edge from i to j
//
//  NOTE: Make sure that w[i][j] is nonnegative and 
//  symmetric.  Missing edges should be given -1 weight.
//            
//   OUTPUT:  edges = list of pair<int,int> in minimum
//            spanning tree return total weight of tree

typedef double T;
typedef vector<T> vt;
typedef vector<vt> vvt;
typedef vector<vi> vvi;

T Prim (const vvt &w, vii &edges){
  int n = w.size();
  vi found (n);
  vi prev (n, -1);
  vt dist (n, 1000000000);
  int here = 0;
  dist[here] = 0;
  
  while (here != -1){
    found[here] = true;
    int best = -1;
    for (int k = 0; k < n; k++) if (!found[k]){
      if (w[here][k] != -1 && dist[k] > w[here][k]){
        dist[k] = w[here][k];
        prev[k] = here;
      }
      if (best == -1 || dist[k] < dist[best]) best = k;
    }
    here = best;
  }
  
  T tot_weight = 0;
  for (int i = 0; i < n; i++) if (prev[i] != -1){
    edges.push_back (make_pair (prev[i], i));
    tot_weight += w[prev[i]][i];
  }
  return tot_weight;
}
