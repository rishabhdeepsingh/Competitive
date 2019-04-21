VB SieveOfEratosthenes(int n) {
    VB prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}

