# Introduction:

Here's the classic implementation, call it the vanilla sieve (i.e. without any dilutions):
```cpp
auto sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for(int i = 2; i < n / i; ++i) if(p[i]) {
        for(int j = i * i; j <= n; j += i) p[j] = false;
    }
    vector<int> prime;
    for(int i = 2; i <= n; ++i) if(p[i]) prime.emplace_back(i);
    return move(prime);
}
```

The only optimizations at the moment, as can be seen, is iterating **till** the square root in the outer loop, and iterating **from** the multiple that is the square in the inner loop. In the outer loop, we go through the numbers that are the candidates for being a prime, in the hope that when we actually **hit** a prime, we'll mark its multiples in the given range in the inner loop. So, just keep in mind that the outer loop passes through candidate primes and the inner, through multiples of actual primes. Every number from the outer loop that doesn't pass the if statement corresponds to a wasted operation in the sense that the algorithm can skip those iterations without compromising correctness. Similarly, every multiple of the prime in the inner loop that has previously been marked by an earlier prime corresponds to a wasted operation in the same sense. Evidently, there is a lot of redundant work. It provides a motivation for algorithms that tends to eliminate this redundancy (with varying degrees), including **Linear Sieve** and **Wheel of Factorization**. Well, then.

# Wheel of Factorization:

You might have been familiar with the following optimization:
```cpp
auto sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for(int i = 3; i < n / i; i += 2) if(p[i]) {
        for(int j = i * i, k = i << 1; j <= n; j += k) p[j] = false;
    }
    vector<int> prime{2};
    for(int i = 3; i <= n; i += 2) if(p[i]) prime.emplace_back(i);
    return move(prime);
}
```
We exploit the fact that **2** is the only even prime so we can eliminate all even numbers greater than that from being a candidate in the outer loop. As a result, it runs from **3** and skips every even number. Similarly, in the inner loop, we skip every even multiple of the selected prime. Notice that even in post-processing, we don't need to make the loop pass through any even number (so that takes care of the fact that we never actually marked an even number as non-prime). Consequently, we have eliminated **50%** of the redundant work  by just this observation. If only, we can extend this... Well, turns out that we can! In fact, the generalization of this observation is exactly what Wheel of Factorization is.

The idea is this: we select an initial set of numbers, the basis (generally, the first few prime numbers). Using this, we mark off all the numbers which can be divided by at least one number in the basis. What we are left with are all the numbers that are co-prime with the elements of the basis. These will form the candidates to be used in the outer loop. I'll continue with an example. Say our basis, **B = {2, 3, 5}**. Now, **LCM(B) = 30**. So, we can have **30** different remainders **(0 - 29)** representing all natural numbers. Out of these, we cancel all such remainders (and hence classes of numbers) that are divisible by at least one of **2**, **3**, or **5**. What we are left with is this set **W = {1, 7, 11, 13, 17, 19, 23, 29}** which are the remainder classes co-prime with the basis. This set is called the **wheel**, and its elements, not surprisingly, are called **spokes**. The LCM is sometimes called the **modulus** or the **circumference** of the wheel.

Enough theory, now let's get concrete. Here's an implementation of the wheel, modulo **30**:

```cpp
auto sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    int skip[] = {6, 4, 2, 4, 2, 4, 6, 2};
    map<int, int> wheel = {{1, 0}, {7, 1}, {11, 2}, {13, 3}, {17, 4}, {19, 5}, {23, 6}, {29, 7}};
    for(int i = 7, j = 1; i <= n / i; i += skip[j], j = (j + 1) % 8) {
        if(p[i]) {
            for(int k = i * i, l = wheel[i % 30]; k <= n; k += i * skip[l], l = (l + 1) % 8) {
                p[k] = false;
            }
        }
    }
    vector<int> prime{2, 3, 5};
    for(int i = 7, j = 1; i <= n; i += skip[j], j = (j + 1) % 8) {
        if(p[i]) prime.emplace_back(i);
    }
    return move(prime);
}
```
The skip array contains the difference between the spokes, which we use to jump through the numbers in the outer loop, and through the multiples in the inner loop. Since we used **2**, **3**, and, **5** on our basis: we assume that we marked off all their multiples and hence we start with **7** (note this is the first number after **1** in the wheel, and that **1** will always be on the wheel since it's co-prime with everything). After that, we use the skip-list to jump through numbers with the remainders in the wheel in the outer loop: I used a map to convert between remainders and indices of the skip-list. In the inner loop too, we go through only those multiples that have remainders in the skip-list (starting from the **i<sup>th</sup>** multiple). Finally, we initialize the primes list with the basis and traverse the loop in a similar manner in post-processing. Working modulo 30, we only have to jump through **8** *(the size of the wheel)* / **30** *(the circumference)* of the numbers which is about **26%** of the actual range!

This might seem like a constant-factor optimization but it drastically reduces the runtime as you extend it to modulo **210** and higher (though the benefit grows quite slowly after that). Finally, its asymptotic complexity is **O(N / log(log(N)))** according to the paper which popularized the method :slightly_smiling_face:

# References:

1. [Wikipedia](https://en.wikipedia.org/wiki/Wheel_factorization#:~:text=Wheel%20factorization%20is%20an%20improvement,until%20finding%20a%20divisor.)
2. [CP-Algorithms](https://cp-algorithms.com/algebra/factorization.html)
3. [An answer on Quora](https://www.quora.com/How-do-I-solve-problem-PRIMES-2-on-SPOJ)
4. [A Codeforces thread](https://codeforces.com/blog/entry/57826)
