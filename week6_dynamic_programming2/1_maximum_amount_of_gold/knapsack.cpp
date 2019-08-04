#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &wt) {
  //write your code here
  int n = wt.size();

    int dp[n+1][W+1];

    for (int i = 0; i <= n; ++i)
    {
      /* code */

      for(int w=0; w<= W; w++){

          if(i == 0 or w == 0)
             dp[i][w] = 0;

          else if(wt[i-1]<=w){
             dp[i][w] = std::max(dp[i-1][w], wt[i-1] + dp[i-1][w - wt[i-1]]);
          }
          else
            dp[i][w] = dp[i-1][w];
        
      }
    }

  

 return dp[n][W];

}

int main() {
  // freopen("input.txt", "r" , stdin);
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  // sort()
  std::cout << optimal_weight(W, w) << '\n';
}
