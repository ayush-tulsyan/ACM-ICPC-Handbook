// Algorithm for sorting the quries in an order which
// minimizes the time required from O(n^2) to O((n + Q)sqrt(n))
// + QlogQ This is done by sorting the queries in
// order of range on which they are performed
// We store the queries and sort them using the compare
// function cmp. Also we need to make an add function to
// calculate the value of range (l,r+1) from value of range
// (l,r) and (l+1,r) from the value of (l,r), and a remove
// function to calculate the value of (l-1, r) from the value
// of (l,r) and (l,r-1) from the value of (l,r) in constant time

// S is the max integer number which is less than sqrt(N);
int S = (int)(sqrt(N));	// Here see if you want ll
bool cmp(Query A, Query B)
{
  if (A.l / S != B.l / S) return A.l / S < B.l / S;
  return A.r > B.r;
}
