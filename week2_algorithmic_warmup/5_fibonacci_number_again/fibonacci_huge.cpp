#include <iostream>
using ll = long long;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


ll pisano(ll m, ll n) {

    ll dp[m * m];

    dp[0] = 0;
    dp[1] = 1;
    ll p;
    for (ll i = 2 ; i <= m * m + 2; ++i)
    {
        /* code */

        dp[i] = (dp[i - 1] + dp[i - 2]) % m;
        if (dp[i - 1] == 0 and dp[i] == 1) {
            p = i - 2 + 1;
            break;
        }
    }

    return dp[n % p];
}

int main() {
    // freopen("input.txt", "r" , stdin);
    long long n, m;
    std::cin >> n >> m;

    ll p = pisano(m, n);
    std::cout <<  p << '\n';
}
