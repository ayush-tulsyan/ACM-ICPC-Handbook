/*  Edmond's Algorithm for finding an aborescence
 *  Produces an aborescence (directed analog of a minimum
 *  spaning tree) of least weight in O(m*n) time
 */

#include "template.h"
#define sz size()
#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) if(1) cout << __LINE__ <<" "<< #x " = " << (x) \
  <<", " << #y " = " << (y) << endl;
typedef vector<vi> vvi;
#define SZ(x) ((x).size())
int N;

vi match;
vi vis;

void couple(int n, int m) { match[n]=m; match[m]=n; }

// returns true if something interesting has been found, thus a
// augmenting path or a blossom (if blossom is non-empty).
// the dfs returns true from the moment the stem of the flower is
// reached and thus the base of the blossom is an unmatched node.
// blossom should be empty when dfs is called and
// contains the nodes of the blossom when a blossom is found.
bool dfs(int n, vvi &conn, vi &blossom) {
  vis[n]=0;
  rep(i, N) {
    if(conn[n][i]) {
      if(vis[i]==-1) {
        vis[i]=1;
        if(match[i]==-1 || dfs(match[i], conn, blossom)) { couple(n,i); return true; }
      }
      if(vis[i]==0 || SZ(blossom)) {  // found flower
        blossom.pb(i); blossom.pb(n);
        if(n==blossom[0]) { match[n]=-1; return true; }
        return false;
      }
    }
  }
  return false;
}

// search for an augmenting path.
// if a blossom is found build a new graph (newconn) where the
// (free) blossom is shrunken to a single node and recurse.
// if a augmenting path is found it has already been augmented
// except if the augmented path ended on the shrunken blossom.
// in this case the matching should be updated along the appropriate
// direction of the blossom.
bool augment(vvi &conn) {
  rep(m, N) {
    if(match[m]==-1) {
      vi blossom;
      vis=vi(N,-1);
      if(!dfs(m, conn, blossom)) continue;
      if(SZ(blossom)==0) return true; // augmenting path found

      // blossom is found so build shrunken graph
      int base=blossom[0], S=SZ(blossom);
      vvi newconn=conn;
      rep1(i, 1, S-1) rep(j, N) newconn[base][j]=newconn[j][base]|=conn[blossom[i]][j];
      rep1(i, 1, S-1) rep(j, N) newconn[blossom[i]][j]=newconn[j][blossom[i]]=0;
      newconn[base][base]=0; // is now the new graph
      if(!augment(newconn)) return false;
      int n=match[base];
      D(base);
      // if n!=-1 the augmenting path ended on this blossom

      if(n!=-1) rep(i, S) if(conn[blossom[i]][n]) {
        couple(blossom[i], n);
        if(i&1) for(int j=i+1; j<S; j+=2) couple(blossom[j],blossom[j+1]);
        else for(int j=0; j<i; j+=2) couple(blossom[j],blossom[j+1]);
        break;
      }
      return true;
    }
  }
  return false;
}

int edmonds(vvi &conn) {  //conn is the Adjacency matrix
  int res=0;
  match=vi(N,-1);
  while(augment(conn)) res++;
  return res;
}

int main() {
  vvi conn(10, vi(10, 0));  // Adjacency matrix
#define addEdge(x,y) conn[x][y]=conn[y][x] = 1;
  addEdge(1,2);
  addEdge(2,3);
  addEdge(2,5);
  addEdge(5,3);
  addEdge(3,4);
  addEdge(5,6);
  N = conn.size();
  D(edmonds(conn));
  return 0;
}
