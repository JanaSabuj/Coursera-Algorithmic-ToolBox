#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

 

vector<int> DS(int n) {
  vector<int> a(n+1);
  vector<int> pred(n+1);

  for (int i = 2; i <= n; i++) {
    a[i] = a[i-1] + 1;
    pred[i] = i - 1;
    if (i % 3 == 0) {
      if (a[i/3] + 1 < a[i]) {
        a[i] = a[i/3] + 1;
        pred[i] = i/3;
      }
    }
    if (i % 2 == 0) {
      if (a[i/2] + 1 < a[i]) {
        a[i] = a[i/2] + 1;
        pred[i] = i/2;
      }
    }
  }

  vector<int> sequence;

  for (int i = n; i !=0; i = pred[i]) {
    sequence.push_back(i);
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
   // freopen("input.txt", "r" , stdin);
  int n;
  std::cin >> n;
  vector<int> sequence = DS(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}