#include "template.h"

template<typename T>
struct segTree {
  T Tree[4*Lim];
  T combine(int l, int r) {
    T ret;
    ret=min(l, r);  // TODO
    return ret;
  }
  void buildST(int Node, int a, int b) {
    if (a==b)
      Tree[Node]=0; // TODO
    else if (a<b) {
      int left=Node<<1, right=(Node<<1)|1, mid=(a+b)>>1;
      buildST(left, a, mid); buildST(right, mid+1, b);
      Tree[Node]=combine(Tree[left], Tree[right]);
    }
  }
  void buildST(int Node, int a, int b, vi Arr) {
    if (a==b)
      Tree[Node]=Arr[a];
    else if (a<b) {
      int left=Node<<1, mid=(a+b)>>1, right=(Node<<1)|1;
      buildST(left, a, mid, Arr); buildST(right, mid+1, b, Arr);
      Tree[Node]=combine(Tree[left], Tree[right]);
    }
  }
  T query(int Node, int a, int b, int S, int E) {
    if (E < a || b < S) return 0;   // TODO
    else if (a==b) return Tree[Node];
    int left=Node<<1, mid=(a+b)>>1, right=(Node<<1)|1;
    if (S <= a && b <= E) return Tree[Node];
    return combine(query(left, a, mid, S, E), query(right, mid+1, b, S, E));
  }
  void update(int Node, int a, int b, int val, int I1, int I2) {
    if (I2 < a || b < I1) return;
    if (I1 <=a && b <= I2) return void(Tree[Node]=val);   // TODO
    int left=Node<<1, mid=(a+b)>>1, right=(Node<<1)|1;
    update(left, a, mid, val, I1, I2), update(right, mid+1, b, val, I1, I2);
    Tree[Node]=combine(Tree[left], Tree[right]);
  }
};

int main() {return 0;}
