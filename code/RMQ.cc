/* matrix structure for finding the range minima in O(1) time using O(n)  log(n)) space */
#include "template.h"
#define better(a,b) A[a]<A[b]?(a):(b)
int A[100100], H[1100][1100];	//A is the Array and H is the lookup matrix
int make_dp(int n) { // N log N
    rep(i,n) H[i][0]=i;
    for(int l=0,k; (k=1<<l) < n; l++) for(int i=0;i+k<n;i++)
        H[i][l+1] = better(H[i][l], H[i+k][l]);
}
int query_dp(int a, int b) {
	int l = __lg(b-a);
	return better(H[a][l], H[b-(1<<l)+1][l]);
}