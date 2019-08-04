#include <iostream>
#include <vector>

using std::vector;
using ll  = long long;
//welcome 

ll get_inversions(vector<int> &a, vector<int> &b, size_t left, int ave, size_t right) {
  size_t i = left, j = ave, k = left;
  ll invCount = 0;
  while (i <= ave - 1 && j <= right) {
    if (a[i] <= a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      invCount += ave - i;
      j++;
    }
    k++;
  }
  while (i <= ave - 1) {
    b[k] = a[i];
    i++;
    k++;
  }
  while (j <= right) {
    b[k] = a[j];
    j++;
    k++;
  }
  for (i = left; i <= right; i++) {
    a[i] = b[i];
  }
  return invCount;
}

ll merge_sort(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long invCount = 0;
  if (right <= left) return invCount;
  size_t ave = left + (right - left) / 2;
  //your code here
  invCount += merge_sort(a, b, left, ave);
  invCount += merge_sort(a, b, ave + 1, right);
  invCount += get_inversions(a, b, left, ave + 1, right);
  return invCount;
}

int main() {
  // freopen("input.txt", "r" , stdin);
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << merge_sort(a, b, 0, a.size() - 1) << '\n';
}