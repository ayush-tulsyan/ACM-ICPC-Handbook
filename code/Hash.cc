#include "template.h"

const int N = 1e5;

// fhash[i] stores hash of s from s[0] to s[i], bhash stores hash 
// for s[i] to s[n-1], calcFhash/CalcBhash, calculate hash from 
// s[l] to s[r] in forward/backward direction

struct HASH{
  pii fhash[N],bhash[N];
  pii p[N],ip[N];
  string s;
  int n;
  HASH(string str){
    s = str; n = s.size();
  }
  void init(){
    p[0] = ip[0] = mp(1,1);
    rep1(i,1,N-1){
      p[i].F = 31LL * p[i-1].F % Mod;
      p[i].S = 37LL * p[i-1].S % Mod;
      ip[i].F = 129032259LL * ip[i-1].F % Mod;
      ip[i].S = 621621626LL * ip[i-1].S % Mod;
    }
  }
  void infHash(){
    rep1(i,0,n-1){
      fhash[i].F = (1LL * s[i] * p[i].F + ( (i) ? fhash[i-1].F : 0 ) ) % Mod;
      fhash[i].S = (1LL * s[i] * p[i].S + ( (i) ? fhash[i-1].S : 0 ) ) % Mod;
    }
  }
  void inbHash(){
    rep2(i,n-1,0){
      bhash[i].F = (1LL * s[i] * p[n-i-1].F + ( (i<n-1) ? bhash[i+1].F : 0)) % Mod;
      bhash[i].S = (1LL * s[i] * p[n-i-1].S + ( (i<n-1) ? bhash[i+1].S : 0)) % Mod;
    }
  }
  pii CalcFhash(int l,int r){
    if(l > r)return mp(0,0);
    pii ret;
    ret.F = 1LL * (fhash[r].F - ((l)?fhash[l-1].F:0) + Mod) * ip[l].F % Mod;
    ret.S = 1LL * (fhash[r].S - ((l)?fhash[l-1].S:0) + Mod) * ip[l].S % Mod;
    return ret; 
  }
  pii CalcBhash(int l,int r){
    if(l > r)return mp(0,0);
    pii ret;
    ret.F = 1LL * (bhash[l].F - ((r<n-1)?bhash[r+1].F:0) + Mod)* ip[n-1-r].F % Mod;
    ret.S = 1LL * (bhash[l].S - ((r<n-1)?bhash[r+1].S:0) + Mod)* ip[n-1-r].S % Mod;
    return ret;
  }
};

int main() {return 0;}