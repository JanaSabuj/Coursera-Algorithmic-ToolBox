#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
 
int optimal_sequence(int n, int dp[]) {

  if (n == 1)
    return 0;

  if (dp[n] != -1)
    return dp[n];

  int x = optimal_sequence(n - 1, dp);

  int ans = x ;
  int val = n - 1;

  if (!(n & 1)) {
    int y = optimal_sequence(n / 2, dp);
    if (y < ans) {
      ans = y;
      val = n / 2;
    }

  }

  if (n % 3 == 0) {
    int z = optimal_sequence(n / 3, dp);
    if (z < ans) {
      ans = z;
      val = n / 3;
    }

  }


  dp[n] = 1 + ans;
  // global.push_back(val);
  return dp[n];

}

void optimal_sequence(int n) {


  int dp[n + 1];

  for (int i = 0; i <= n; ++i)
  {
    /* code */
    dp[i] = -1;
  }

  int ans = optimal_sequence(n, dp);

  int target = n;
  std::vector<int> vec;
  vec.push_back(target);
  while (target!=1) {

    if (dp[target - 1] == dp[target] - 1) {
      target = target - 1;
      vec.push_back(target);
    }
    else if ( (target % 2 == 0) and (dp[target / 2] = dp[target] - 1)) {
      target /= 2;
      vec.push_back(target);
    }
    else {
      target /= 3;
      vec.push_back(target);
    }

  }

  reverse(vec.begin(), vec.end());

  std::cout << vec.size() - 1 << std::endl;

  for (auto x : vec)
    std::cout << x << " ";

}

int main() {
  freopen("input.txt", "r" , stdin);
  int n;
  std::cin >> n;
   

  optimal_sequence(n) ;

   

}
