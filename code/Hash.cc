struct HASH{
    ii fhash[N],bhash[N];
    ii p[N],ip[N];
    string s;
    int n;
    HASH(string str){
      s = str; n = sz(s);
    }
    void init(){
      p[0] = ip[0] = {1,1};
      FOR(i,1,N-1){
        p[i].F = 31LL * p[i-1].F % mod;
        p[i].S = 37LL * p[i-1].S % mod;
        ip[i].F = 129032259LL * ip[i-1].F % mod;
        ip[i].S = 621621626LL * ip[i-1].S % mod;
      }
    }
    void infHash(){
      FOR(i,0,n-1){
        fhash[i].F = (1LL * s[i] * p[i].F + ( (i) ? fhash[i-1].F : 0 ) ) % mod;
        fhash[i].S = (1LL * s[i] * p[i].S + ( (i) ? fhash[i-1].S : 0 ) ) % mod;
      }
    }
    void inbHash(){
      NFOR(i,n-1,0){
        bhash[i].F = (1LL * s[i] * p[n-i-1].F + ( (i<n-1) ? bhash[i+1].F : 0)) % mod;
        bhash[i].S = (1LL * s[i] * p[n-i-1].S + ( (i<n-1) ? bhash[i+1].S : 0)) % mod;
      }
    }
    ii CalcFhash(int l,int r){
      if(l > r)return {0,0};
      ii ret;
      ret.F = 1LL * (fhash[r].F - ((l)?fhash[l-1].F:0) + mod) * ip[l].F % mod;
      ret.S = 1LL * (fhash[r].S - ((l)?fhash[l-1].S:0) + mod) * ip[l].S % mod;
      return ret; 
    }
    ii CalcBhash(int l,int r){
      if(l > r)return {0,0};
      ii ret;
      ret.F = 1LL * (bhash[l].F - ((r<n-1)?bhash[r+1].F:0) + mod)* ip[n-1-r].F % mod;
      ret.S = 1LL * (bhash[l].S - ((r<n-1)?bhash[r+1].S:0) + mod)* ip[n-1-r].S % mod;
      return ret;
    }
};