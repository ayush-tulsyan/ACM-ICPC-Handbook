/* Z algorithm for matching substrings. KMP's Brother */

vector<int> zfunction(char *s) {
  int N = strlen(s), a=0, b=0;
  vector<int> z(N, N);
  for (int i = 1; i < N; i++) {
    int k = i<b ? min(b-i, z[i-a]) : 0;
    while (i+k < N && s[i+k]==s[k]) ++k;
    z[i] = k;
    if (i+k > b) { a=i; b=i+k; }
  }
  return z;
}

Definition:
z[i] = max {k: s[i..i+k-1]=s[0..k-1]}
