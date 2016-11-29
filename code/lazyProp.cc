#include "template.h"

/*
  A lazy tree implementation of Range Updation & Range Query
*/

ll Arr[Lim], Tree[4*Lim], lazy[4*Lim];

void build_tree(int Node, int a, int b) {
  // Do not forget to clear lazy Array before calling build

  if(a == b) {
    Tree[Node] = Arr[a];
  } else if (a < b) {
    int mid = (a+b)>>1, left=Node<<1, right=left|1;
    build_tree(left, a, mid); build_tree(right, mid+1, b);
    Tree[Node] = Tree[left]+Tree[right];
  }
}

void Propogate(int Node, int a, int b) {
  int left=Node<<1, right=left|1;
  Tree[Node]+=lazy[Node]*(b-a+1);
  if(a != b) {
    lazy[left]+=lazy[Node];
    lazy[right]+=lazy[Node];
  }
  lazy[Node] = 0;
}

void update_tree (int Node, int start, int end, ll value, int a, int b) {
  int mid=(a+b)>>1, left=Node<<1, right=left|1;
  if(lazy[Node] != 0)
    Propogate(Node, a, b);

  if(a > b || a > end || b < start) {
    return;
  } else {
    if(start <= a && b <= end) {
      if (a != b) {
        lazy[left] += value;
        lazy[right] += value;
      } 
      Tree[Node] += value * (b - a + 1);
    } else {
      update_tree(left, start, end, value, a, mid);
      update_tree(right, start, end, value, mid+1, b);
      Tree[Node]=Tree[left]+Tree[right];
    }
  }
}

ll query(int Node, int start, int end, int a, int b) {
  int mid=(a+b)>>1, left=Node<<1, right=left|1;
  if(lazy[Node] != 0)
    Propogate(Node, a, b);

  if (a > b || a > end || b < start) {
    return 0;
  } else {
    ll Sum1, Sum2;
    if (start <= a && b <= end) {
      return Tree[Node];
    } else {
      Sum1 = query(left, start, end, a, mid);
      Sum2 = query(right, start, end, mid + 1, b);
      return Sum1+Sum2;
    }
  }
}