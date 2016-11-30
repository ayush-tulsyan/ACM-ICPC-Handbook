#include "template.h"
bool works(int m){
  // if Array[m] is the value to be searched, return true
  // else return false
}

// The property is increasing
int BinarySearch(int l, int h){
  int m;
  while(l <= h){ m = (l+h) / 2; if(works(m))  l=m+1; else h=m-1; }
  return l-1;
}
// The property is decreasing
// while(l <= h){ m = (l+h) / 2; if(works(m))  h=m-1; else l=m+1; }
// return h+1;