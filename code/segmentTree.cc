#include "template.h"
/*
  Segment Tree for Range Minima Query, Can be modified easily for 
  other cases. 

  Deal Everything in one based indexing
*/

ll Arr[Lim], Tree[4*Lim];

void buildTree(int Node, int a, int b) {
  if(a == b) {
    Tree[Node]=Arr[a];
  } else if (a < b) {
    int mid=(a+b)>>1, left=Node<<1;
    int right=left|1;
    buildTree(left, a, mid);
    buildTree(right, mid+1, b);
    Tree[Node] = min(Tree[left], Tree[right]);
  }
}

void updateTree(int Node, ll value, int a, int b, int index) {
  if (a > index || b < index) {

  } else if (a == b) {
    Tree[Node] = value;
    Arr[index] = value;
  } else if (a <= index && b >= index) {
    int mid=(a+b)>>1, left=Node<<1;
    int right=left|1;
    updateTree(left, index, value, a, mid);
    updateTree(right, index, value, mid+1, b);
    Tree[Node]=min(Tree[left], Tree[right]);
  }
 }

ll queryTree(int Node, int start, int end, int a, int b) {
  int mid=(a+b)>>1, left=Node<<1;
  int right=left|1;
  ll Ans = Inf;
  if (start <= a && b <= end) {
    return Tree[Node];
  } else {
    if(mid >= start)
      Ans = queryTree(left, start, end, a, mid);

    if(mid < end)
      Ans = min(Ans, queryTree(right, start, end, mid+1, b));

    return Ans;
  }
}