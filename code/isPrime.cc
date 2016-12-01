// O(sqrt(x)) Exhaustive Primality Test
#include "template.h"
bool IsPrimeSlow (ll x){
  if(x<=1) return false;
  if(x<=3) return true;
  if (!(x%2) || !(x%3)) return false;
  ll s=(ll)(sqrt((double)(x))+eps);
  for(ll i=5;i<=s;i+=6){
    if (!(x%i) || !(x%(i+2))) return false;
  }
  return true;
}