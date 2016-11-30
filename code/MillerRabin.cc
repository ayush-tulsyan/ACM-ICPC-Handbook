// Randomized Primality Test (Miller-Rabin):
//   Error rate: 2^(-TRIAL)
//   Almost constant time. srand is needed
#include "template.h"

ll ModularMultiplication(ll a, ll b, ll m) {
  ll ret=0, c=a;
  while(b) {
    if(b&1) ret=(ret+c)%m;
    b>>=1; c=(c+c)%m;
  }
  return ret;
}

ll ModularExponentiation(ll a, ll n, ll m) {
  ll ret=1, c=a;
  while(n) {
    if(n&1) ret=ModularMultiplication(ret, c, m);
    n>>=1; c=ModularMultiplication(c, c, m);
  }
  return ret;
}

bool Witness(ll a, ll n) {
  ll u=n-1;
  int t=0;
  while(!(u&1)){u>>=1; t++;}
  ll x0=ModularExponentiation(a, u, n), x1;
  for(int i=1;i<=t;i++) {
    x1=ModularMultiplication(x0, x0, n);
    if(x1==1 && x0!=1 && x0!=n-1) return true;
    x0=x1;
  }
  if(x0!=1) return true;
  return false;
}

ll Random(ll n) {
  ll ret=rand(); ret*=32768;
  ret+=rand(); ret*=32768;
  ret+=rand(); ret*=32768;
  ret+=rand();
  return ret%n;
}

bool IsPrimeFast(ll n, int TRIAL) {
  while(TRIAL--) {
    ll a=Random(n-2)+1;
    if(Witness(a, n)) return false;
  }
  return true;
}
