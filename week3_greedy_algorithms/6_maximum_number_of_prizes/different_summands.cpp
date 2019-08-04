#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here

  int W = n;

  for(int i=1; i<=n and W>0 ; i++){
     if(i<=W){
      summands.push_back(i);
      W = W - i;
     }else if( i>W) {
      summands.push_back(W);
      W = 0;
     }

  }

  int len = summands.size();
  if(len>=2){
    if(summands[len-1]<=summands[len-2]){
      int x = summands[len-1] + summands[len - 2];
      summands.pop_back();
      summands.pop_back();
      summands.push_back(x);
    }
  }



  return summands;
}

int main() {
  // freopen("input.txt", "r" , stdin);
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
