#include "template.h"
const int N = 100 * 1000;
struct node { int value, weight, ch[2], size; } T[ N+10 ] ; int nodes;
#define Child(x,c) T[x].ch[c]
#define Value(x) T[x].value
#define Weight(x) T[x].weight
#define Size(x) T[x].size
#define Left Child(x,0)
#define Right Child(x,1)
int update(int x) { if(!x)return 0; Size(x) = 1+Size(Left)+Size(Right); return x; }
int newnode(int value, int prio) {
  T[++nodes]=(node){value,prio,0,0};
  return update(nodes);
}
void split(int x, int by, int &L, int &R)
{
  if(!x) { L=R=0; }
  else if(Value(x) < Value(by)) { split(Right,by,Right,R); update(L=x); }
  else { split(Left,by,L,Left); update(R=x); }
}
int merge(int L, int R)
{
  if(!L) return R; if(!R) return L;
  if(Weight(L)<Weight(R)) { Child(L,1) = merge(Child(L,1), R); return update(L);}
  else { Child(R,0) = merge( L, Child(R, 0)); return update(R); }
}
int insert(int x, int n)
{
  if(!x) { return update(n); }
  if(Weight(n)<=Weight(x)) {split(x,n,Child(n,0),Child(n,1)); return update(n);}
  else if(Value(n) < Value(x)) Left=insert(Left,n); else Right=insert(Right,n);
  return update(x);
}
int del(int x, int value)
{
  if(!x) return 0;
  if(value == Value(x)) { int q = merge(Left,Right); return update(q); }
  if(value < Value(x)) Left = del(Left,value); else Right = del(Right, value);
  return update(x);
}
int find_GE(int x, int value) {
  int ret=0;
  while(x) { if(Value(x)==value)return x;
    if(Value(x)>value) ret=x, x=Left; else x=Right; }
  return ret;
}
int find(int x, int value) {
  for(; x; x=Child(x,Value(x)<value)) if(Value(x)==value)return x;
    return 0;
}
int findmin(int x) { for(;Left;x=Left); return x; }
int findmax(int x) { for(;Right;x=Right); return x; }
int findkth(int x, int k) {
  while(x) {
    if(k<=Size(Left)) x=Left;
    else if(k==Size(Left)+1)return x;
    else { k-=Size(Left)+1; x=Right; }
  }
}
int queryrangekth(int &x, int a1, int a2, int k) {
  a1 = find(x, a1); a2 = find(x, a2);
  assert(a1 && a2);
  int a,b,c; split(x,a1,a,b); split(b,a2,b,c);
  int ret = findkth(b,k);
  x = merge(a, merge(b,c));
  return Value(ret);
}
int main(){
  return 0;
}