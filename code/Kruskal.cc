/*
Uses Kruskal's Algorithm to calculate the weight of the minimum spanning
forest (union of minimum spanning trees of each connected component) of
a possibly disjoint graph, given in the form of a matrix of edge weights
(-1 if no edge exists). Returns the weight of the minimum spanning
forest (also calculates the actual edges - stored in T). Note: uses a
disjoint-set data structure with amortized (effectively) constant time per
union/find. Runs in O(E*log(E)) time.
*/
#include "template.h"

typedef int T;
struct edge{
  int u, v;
  T d;
};

struct edgeCmp{
  int operator()(const edge& a, const edge& b) { return a.d > b.d; }
};

int find(vector <int>& C, int x) { return (C[x] == x)?x: C[x]=find(C, C[x]); }

T Kruskal(vii Alist[], int n){
  T weight = 0;
  
  vector <int> C(n), R(n);
  for(int i=0; i<n; i++) { C[i] = i; R[i] = 0; }
  
  vector <edge> T;
  priority_queue <edge, vector <edge>, edgeCmp> E;
  
  rep(i, n)
    rep(j, Alist[i].size()) {
      edge e;
      e.u = i, e.v = Alist[i][j].F, e.d = Alist[i][j].S;
      E.push(e);
    }
    
  while(T.size() < n-1 && !E.empty()) {
    edge cur = E.top(); E.pop();
    int uc = find(C, cur.u), vc = find(C, cur.v);
    if(uc != vc) {
      T.push_back(cur); weight += cur.d;
      if(R[uc] > R[vc])
        C[vc] = uc;
      else if(R[vc] > R[uc])
        C[uc] = vc;
      else
        C[vc] = uc; R[uc]++;
    }
  }
  return weight;
}

int main() {
  int n;
  cin >> n;
  vii Alist[Lim];
  cout << Kruskal(Alist, n) << endl;
}