#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using ll = long long;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

bool comp(int a, int b) {
  return a > b;
}

ll max_dot_product_fast(std::vector<int> a, std::vector<int> b) {
  ll result = 0;
  sort(a.begin(), a.end(), comp);
  sort(b.begin(), b.end(), comp);

  for (int i = 0; i < a.size(); ++i)
  {
    /* code */
    result += (((ll)a[i]) * b[i]);
  }

  return result;


}




int main() {
  // freopen("input.txt", "r" , stdin);
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product_fast(a, b) << std::endl;
}
