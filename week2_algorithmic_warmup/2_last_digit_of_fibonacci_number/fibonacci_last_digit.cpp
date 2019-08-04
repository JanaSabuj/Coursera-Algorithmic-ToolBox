#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp = previous;
        previous = current;
        current = tmp + current;
    }

    return current % 10;
}


int get_fibonacci_last_digit_fast(int n){
    int fib[n];
    fib[0]=0;
    fib[1]=1;

    for (int i = 2; i <= n; ++i)
    {
        /* code */
        fib[i] = (fib[i-1]+fib[i-2]) % 10;
    }

    return fib[n];
}

int main() {
     // freopen("input.txt", "r" , stdin);
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);

    std::cout << c << '\n';
    }
