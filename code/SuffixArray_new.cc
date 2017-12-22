// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm

// SA = The suffix array. Contains the n suffixes of txt sorted in lexicographical order.
//       Each suffix is represented as a single integer (the SAition of txt where it starts).
// iSA = The inverse of the suffix array. iSA[i] = the index of the suffix txt[i..n)
//        in the SA array. (In other words, SA[i] = k <==> iSA[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix txt[i..n) is smaller
//        than txt[j..n) if and only if iSA[i] < iSA[j]
const int MAX = 1000100;
char txt[MAX]; //input
int iSA[MAX], SA[MAX]; //output
int cnt[MAX];
int nex[MAX]; //internal
bool bh[MAX], b2h[MAX];
 
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return txt[a] < txt[b];
}
 
void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    SA[i] = i;
  }
  sort(SA, SA + n, smaller_first_char);
  //{SA contains the list of suffixes sorted by their first character}
 
  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || txt[SA[i]] != txt[SA[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of SA[i-1] == the first h characters of SA[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      nex[i] = j; buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing txtings starting with the same h characters}
 
    for (int i = 0; i < n; i = nex[i]){
      cnt[i] = 0;
      for (int j = i; j < nex[i]; ++j){
        iSA[SA[j]] = i;
      }
    }
    cnt[iSA[n - h]]++;
    b2h[iSA[n - h]] = true;
    for (int i = 0; i < n; i = nex[i]){
      for (int j = i; j < nex[i]; ++j){
        int s = SA[j] - h;
        if (s >= 0){
          int head = iSA[s];
          iSA[s] = head + cnt[head]++; b2h[iSA[s]] = true;
        }
      }
      for (int j = i; j < nex[i]; ++j){
        int s = SA[j] - h;
        if (s >= 0 && b2h[iSA[s]]){
          for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      SA[iSA[i]] = i; bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i)
    iSA[SA[i]] = i;
}
// End of suffix array algorithm
 
 
// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
int lcp[MAX];
// lcp[i] = length of the longest common prefix of suffix SA[i] and suffix SA[i-1]
// lcp[0] = 0
void getlcp(int n)
{
  for (int i=0; i<n; ++i) 
    iSA[SA[i]] = i;

  lcp[0] = 0;

  for (int i=0, h=0; i<n; ++i) {
    if (iSA[i] > 0) {
      int j = SA[iSA[i]-1];
      while (i + h < n && j + h < n && txt[i+h] == txt[j+h]) 
          h++;
      lcp[iSA[i]] = h;
      if (h > 0)  h--;
    }
  }
}
// End of longest common prefixes algorithm
int main() {
  int len;
 // gets(txt);
  for(int i  = 0; i < 1000000; i++)
     txt[i] = 'a';
     txt[1000000] = '\0';
     len = strlen(txt);
     printf("%d",len);
     suffixSort(len);
     getlcp(len);
     return 0;
 }