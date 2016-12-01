/* Algorithm for sorting the quries in an order which minimizes the time required from O(n^2) to O(nsqrt(n))log(n) + QlogQ This is done by sorting the queries in order of range on which they are performed */
S = the max integer number which is less than sqrt(N);
bool cmp(Query A, Query B)
{
  if (A.l / S ！= B.l / S) return A.l / S < B.l / S;
  return A.r > B.r
}