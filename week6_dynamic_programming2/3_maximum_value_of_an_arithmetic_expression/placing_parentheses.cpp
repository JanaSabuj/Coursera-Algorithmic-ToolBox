#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::cout;
using std::cin;

using ll = long long;


long long get_maximum_value(const string &exp) {
  //write your code here


  std::vector<int> d;
  std::vector<char> op;

  d.push_back(0);
  op.push_back('/');

  for (int i = 0; i < exp.size(); ++i)
  {
    /* code */
    if (exp[i] == '-' or exp[i] == '+' or exp[i] == '*')
      op.push_back(exp[i]);
    else {
      int val = exp[i] - '0';
      d.push_back(val);
    }

  }

  int n = d.size() - 1;

  ll M[n + 1][n + 1];
  ll m[n + 1][n + 1];

  for (int i = 1; i <= n; ++i)
  {
    /* code */
    m[i][i] = d[i];
    M[i][i] = d[i];
  }

  for (int s = 1; s <= n - 1; ++s)
  {
    /* code */

    for (int i = 1; i <= n - s; i++) {

       int j= i + s;

        ll minAns = LLONG_MAX;
        ll maxAns = LLONG_MIN;


        for (int k = i; k <= j - 1; k++) {
            

          char c = op[k];
          if (c == '+') {
            ll a = M[i][k] + M[k + 1][j];
            ll b = m[i][k] + m[k + 1][j];
            ll c = M[i][k] + m[k + 1][j];
            ll d = m[i][k] + M[k + 1][j];

            minAns = min({minAns, a, b, c, d});
            maxAns = max({maxAns, a, b, c, d});

          } else if (c == '*') {
            ll a = M[i][k] * M[k + 1][j];
            ll b = m[i][k] * m[k + 1][j];
            ll c = M[i][k] * m[k + 1][j];
            ll d = m[i][k] * M[k + 1][j];

            minAns = min({minAns, a, b, c, d});
            maxAns = max({maxAns, a, b, c, d});

          } else if (c == '-') {
            ll a = M[i][k] - M[k + 1][j];
            ll b = m[i][k] - m[k + 1][j];
            ll c = M[i][k] - m[k + 1][j];
            ll d = m[i][k] - M[k + 1][j];

            minAns = min({minAns, a, b, c, d});
            maxAns = max({maxAns, a, b, c, d});

          }
        }

        m[i][j] = minAns;
        M[i][j] = maxAns;

       

    }
  }




  return M[1][n];
}

int main() {
  // freopen("input.txt", "r" , stdin);
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
