void MOB(int n){
  vector<int> mob(n);
  for(int i = 1; i < n ; ++i)mob[i] = 1;
  for(int i = 2; i < N ; i++){
    if(pf[i] == i){
      if(1LL * i * i < N){
        for(int j = i*i ; j < N ; j += (i*i) ){
          mob[j] = 0;
        }
      }
      for(int j = i ; j < N ; j+=i){
        mob[j] *= -1;
      }
    }
  }
}