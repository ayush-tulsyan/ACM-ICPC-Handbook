#include "template.h"

#define NC 26       // No of characters
#define NP 10005
#define M 100005
#define MM 500005   // Max no of states

// b stores the strings in dictionary, g stores the trie using states, 
// a is the query string, lenb stores length of strings in b
// output stores the index of word which end at the corresponding state
// f stores the blue edge (largest suffix of current word), pre is useless!
// marked represent that this word occurs in string a

char a[M];
char b[NP][105];
int nb, cnt[NP], lenb[NP], alen;
int g[MM][NC], ng, f[MM], marked[MM];
int output[MM], pre[MM];

#define init(x) {rep(_i,NC)g[x][_i] = -1; f[x]=marked[x]=0; output[x]=pre[x]=-1; }

void match() {
  ng = 0;
  init( 0 );  
  // part 1 - building trie
  rep(i,nb) {
    cnt[i] = 0;
    int state = 0, j = 0;
    while(g[state][b[i][j]] != -1 && j < lenb[i]) state = g[state][b[i][j]], j++;
    while( j < lenb[i] ) {
      g[state][ b[i][j] ] = ++ng;
      state = ng;
      init( ng );
      ++j;
    }
    // if( ng >= MM ) { cerr <<"i am dying"<<endl; while(1);} // suicide 
    output[ state ] = i;
  }
  // part 2 - building failure function
  queue< int > q;
  rep(i,NC) if( g[0][i] != -1 ) q.push( g[0][i] );
  while( !q.empty() ) {
    int r = q.front(); q.pop();
    rep(i,NC) if( g[r][i] != -1 ) {
      int s = g[r][i];
      q.push( s );
      int state = f[r];
      while( g[state][i] == -1 && state ) state = f[state];
      f[s] = g[state][i] == -1 ? 0 : g[state][i];
    }
  }
  // final smash
  int state = 0;
  rep(i,alen) {
    while( g[state][a[i]] == -1 ) {
      state = f[state];
      if( !state ) break;
    }
    state = g[state][a[i]] == -1 ? 0 : g[state][a[i]];
    if( state && output[ state ] != -1 ) marked[ state ] ++; 
  }
  // counting
  rep(i,ng+1) if( i && marked[i] ) {
    int s = i;
    while( s != 0 ) cnt[ output[s] ] += marked[i], s = f[s];
  }
}