#include <iostream>
#include <vector>
using std::vector;
using ll = long long;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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

ll get_fibonacci_partial_sum_fast(ll m, ll n) {

    ll f1 = pisano( (ll)10, n + 2);
    ll f2 = pisano( (ll)10, m + 1);

    return (f1 - f2 + 10) % 10;

}

int main() {
    // freopen("input.txt", "r" , stdin);
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
