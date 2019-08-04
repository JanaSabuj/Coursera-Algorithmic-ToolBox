#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using std::cin;
using std::vector;
using std::cout;

#define int long long int

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int optimum(std::vector<int> vec){

    std::sort(vec.begin(), vec.end());
    int n = vec.size();

    return vec[n-1]*vec[n-2];
}

signed main() {
    // freopen("input.txt", "r", stdin);
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << optimum(numbers) << "\n";
    return 0;
}
