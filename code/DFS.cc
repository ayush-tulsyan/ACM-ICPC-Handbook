#include "template.h"

vector<int> Alist[Lim];
int ComNum[Lim];
bool visited[Lim];

void DFS(int head){
  visited[head]=true;
  rep(i, Alist[head].size()) {
    if(!(visited[Alist[head][i]])) {
      ComNum[Alist[head][i]]=ComNum[head];
      DFS(Alist[head][i]);
    }
  }
}

void callDFS(int vertices){
  mem(visited, 0);
  int comp_no=0;
  rep1(i, 1, vertices) {
    if(!visited[i]){
      ComNum[i]= ++comp_no;
      DFS(i);
    }
  }
}

