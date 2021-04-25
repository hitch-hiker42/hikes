constexpr int lim = 1'000'001;

vector<int> prime;
int p[lim], spf[lim]; //prime[p[i]] = i;

void spfsieve() { //call it during preprocessing
  for(int i = 1; i < lim; ++i) spf[i] = vector<int>{2, i}[i & 1];
  for(int i = 3; i < lim / i; i += 2) {
    if(spf[i] == i) { //implies i is prime
      for(int j = i * i, k = i << 1; j < lim; j += k) {
        if(spf[j] == j) spf[j] = i;
      }
    }
  }
  for(int i = 2, j = 0; i < lim; ++i) {
    if(spf[i] == i) prime.push_back(i), p[i] = j++;
  }
}
