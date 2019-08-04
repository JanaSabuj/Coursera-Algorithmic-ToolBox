#include <iostream>
using ll = long long;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

ll fibonacci_sum_squares_fast(ll n){

    ll fn = pisano( (ll)10, n);
    ll fn1 = pisano( (ll)10, n-1);


    return ((fn*fn)%10 + (fn1*fn)%10)%10;   

}

int main() {
    // freopen("input.txt", "r" , stdin);
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n);
    std::cout << fibonacci_sum_squares_fast(n);
}
