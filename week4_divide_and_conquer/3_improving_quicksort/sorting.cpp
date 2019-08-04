#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>

using std::vector;
using std::swap;
using std::pair;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

pair<int, int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int rt = r;
  int lt = l;
  for (int i = l; i <= rt; i++) {
    // a[i] = pivot, i++
    // a[i] < pivot,
    if (a[i] < x) {
      swap(a[i], a[lt]);
      lt++;
    }
    // a[i] > pivot,
    else if (a[i] > x) {
      swap(a[i], a[rt]);
      i--;
      rt--;
    }
  }
  // vector<int> pos(2);
  pair<int, int> p = {lt, rt};
  // pos[0] = lt; pos[1] = rt;
  return p;
}


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  // int m = partition2(a, l, r);
  pair<int, int> p = partition3(a, l, r);
  int m1 = p.first;
  int m2 = p.second;

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

int main() {
  // freopen("input.txt", "r" , stdin);
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
