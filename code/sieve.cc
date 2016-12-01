#include "template.h"
/*  
  isPrime stores the largest prime number which divides the index
  vector primeNum contains all the prime numbers
*/

vi primeNum;
int isPrime[Lim];

void pop_isPrime(int limit) {
  mem(isPrime, 0);
  rep1(i, 2, limit) {
    if (isPrime[i])
      continue;

    if (i <= (int)(sqrt(limit)+10))
      for(ll j = i*i; j <= limit; j += i)
        isPrime[j] = i;

    primeNum.pb(i);
    isPrime[i]=i;
  }
}

int main() {
  fast;
  pop_isPrime(500);
  rep1(i, 1, 500)
    cout << i << ' ' << isPrime[i] << '\n';
}