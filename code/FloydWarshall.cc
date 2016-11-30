#include "template.h"

typedef double T;
typedef vector<T> vt;
typedef vector<vt> vvt;
typedef vector<vi> vvi;

// This function runs the Floyd-Warshall algorithm for all-pairs
// shortest paths.  Also handles negative edge weights.  Returns true
// if a negative weight cycle is found.
//
// Running time: O(|V|^3)
//
//   INPUT:  Alist[i][j] = Alisteight of edge from i to j
//   OUTPUT: Alist[i][j] = shortest path from i to j
//           prev[i][j] = node before j on the best path starting at i

bool FloydWarshall (vvt &Alist, vvi &prev) {
  int n = Alist.size();
  prev = vvi(n, vi(n, -1));

  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (Alist[i][j] > Alist[i][k] + Alist[k][j]){
          Alist[i][j] = Alist[i][k] + Alist[k][j];
          prev[i][j] = k;
        }
      }
    }
  }
 
  // check for negative weight cycles
  for(int i=0;i<n;i++)
    if (Alist[i][i] < 0) return false;
  return true;
}