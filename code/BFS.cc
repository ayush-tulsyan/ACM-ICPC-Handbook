#include "template.h"

vector<int> AList[Lim];
int ComNum[Lim];
bool visited[Lim];

void BFS (int head, int ComIndex) {
  queue<int> Q;
  Q.push(head);
  int curr, tmp;
  while (!Q.empty()) {
    curr = Q.front();
    ComNum[curr] = ComIndex;
    for (int i = 0; i < AList[curr].size(); ++i) {
      tmp = AList[curr][i];
      if (!visited[tmp]) {
        Q.push(tmp);
        visited[tmp] = true;
      } 
    }
    Q.pop();
  }
  return;
}

void callBFS(int Nvertices) {
  memset(visited, 0, Nvertices);
  memset(ComNum, 0, 4*Nvertices);
  int Ncomponents = 0;
  for (int i = 0; i < Nvertices; ++i) {
    if (!visited[i]) {
      Ncomponents++;
      visited[i] = true;
      BFS(i, Ncomponents);
    } 
  }
}