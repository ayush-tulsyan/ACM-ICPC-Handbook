#include "template.h"

struct Edge;
typedef list<Edge>::iterator iter;

struct Edge {
  int next_vertex;
  iter reverse_edge;

  Edge(int next_vertex) :next_vertex(next_vertex)
    { }
};

const int max_vertices = 10;
// int num_vertices = 6;
list<Edge> adj[max_vertices];   // adjacency list

vector<int> path;

void find_path(int v) {
  while(adj[v].size() > 0) {
    int vn = adj[v].front().next_vertex;
    adj[vn].erase(adj[v].front().reverse_edge);
    adj[v].pop_front();
    find_path(vn);
  }
  path.push_back(v);
}

void add_edge(int a, int b) {
  adj[a].push_front(Edge(b));
  iter ita = adj[a].begin();
  adj[b].push_front(Edge(a));
  iter itb = adj[b].begin();
  ita->reverse_edge = itb;
  itb->reverse_edge = ita;
}

int main() {
  int total=0, start_vertex = 0;
  rep(i, max_vertices)
    if(adj[i].size()&1)				// if the size is odd then increment 'total'
      total++, start_vertex=i;		// put the starting vertex as an odd degree vertex
  if(total==0||total==2) {			// necessary and sufficient condition to check the existence of an EC
    find_path(start_vertex);
    rep(i, path.size()) cout << path[i] << " ";
  }
  else
    cout << "No Eulerian Circuit\n";
  return 0;
}