#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int n = a.size();//len
  int m = b.size();//len
  int r = c.size();

  int dp[n + 1][m + 1][r + 1];

  for (int i = 0; i <= n; ++i)
  {
    /* code */

    for (int j = 0; j <= m; j++) {

      for (int k = 0; k <= r ; ++k)
      {
        /* code */
        if (i == 0 or j == 0 or k == 0)
          dp[i][j][k] = 0;

        else if (a[i - 1] == b[j - 1] and b[j - 1] == c[k - 1]) {
          dp[i][j][k] = 1 + dp[i - 1][j - 1][k-1];
        }
        else {
          dp[i][j][k] = std::max({dp[i ][j -1][k-1], dp[i][j][k-1],dp[i][j-1][k], dp[i-1][j][k-1], dp[i-1][j][k], dp[i][j][k-1], dp[i-1][j-1][k], dp[i-1][j][k], dp[i][j-1][k]});
        }
      }

    }
  }

  return dp[n][m][r];

}

int main() {
  // freopen("input.txt", "r" , stdin);
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
