//basis:
length: b, composed of the first 'b' natural primes

//circumference:
w[b - 1] = product of elements of the basis

//stokes:
vector<bool> p(w[b - 1], true);
p[0] = false;
for(int& i: basis) {
    for(int j = i * i; j < w[b - 1]; j += i) p[j] = false;
}
for(int i = 1; i < w[b - 1]; ++i) if(p[i]) stokes[b - 1].emplace_back(i);

//skiplists:
for(int i = 1; i < (int)stokes[b - 1].size(); i++) {
    skip[b - 1].emplace_back(stokes[b - 1][i] - stokes[b - 1][i - 1]);
}

//wheel hashes:
for(int i = 0; i < (int)stokes[b - 1].size() - 1; i++) {
    wheel[stokes[b - 1][i]] = i;
}
