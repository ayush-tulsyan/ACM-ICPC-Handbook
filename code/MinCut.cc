// Adjacency matrix implementation of Stoer-Wagner min cut algorithm.
//
// Running time:
//     O(|V|^3)
//
// INPUT: 
//     - graph, constructed using AddEdge()
//
// OUTPUT:
//     - (min cut value, nodes in half of min cut)

#include "template.h"

typedef vector<vi> vvi;

const int INF = 1000000000;

pair<int, vi> GetMinCut(vvi &weights) {
  int N = weights.size();
  vi used(N), cut, best_cut;
  int best_weight = -1;
  
  for (int phase = N-1; phase >= 0; phase--) {
    vi w = weights[0];
    vi added = used;
    int prev, last = 0;
    for (int i = 0; i < phase; i++) {
      prev = last;
      last = -1;
      for (int j = 1; j < N; j++)
	if (!added[j] && (last == -1 || w[j] > w[last])) last = j;
      if (i == phase-1) {
	for (int j = 0; j < N; j++) weights[prev][j] += weights[last][j];
	for (int j = 0; j < N; j++) weights[j][prev] = weights[prev][j];
	used[last] = true;
	cut.push_back(last);
	if (best_weight == -1 || w[last] < best_weight) {
	  best_cut = cut;
	  best_weight = w[last];
	}
      } else {
	for (int j = 0; j < N; j++)
	  w[j] += weights[last][j];
	added[last] = true;
      }
    }
  }
  return make_pair(best_weight, best_cut);
}

// BEGIN CUT
// The following code solves UVA problem #10989: Bomb, Divide and Conquer
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int n, m;
    cin >> n >> m;
    vvi weights(n, vi(n));
    for (int j = 0; j < m; j++) {
      int a, b, c;
      cin >> a >> b >> c;
      weights[a-1][b-1] = weights[b-1][a-1] = c;
    }
    pair<int, vi> res = GetMinCut(weights);
    cout << "Case #" << i+1 << ": " << res.first << endl;
  }
}
// END CUT
