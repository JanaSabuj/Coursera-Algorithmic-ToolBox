#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using std::vector;
using std::pair;

bool comp(pair<int,int>& a, pair<int,int>& b){

  double r1 = (double) ( (double)a.first / a.second);
  double r2 = (double) ( (double)b.first / b.second);

  return r1>r2;


}


double get_optimal_value(int w, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double W = w;
  // write your code here
  std::vector<pair<int, int>> vec;
  int n = weights.size();

  for (int i = 0; i < n ; ++i)
  {
    /* code */
      vec.push_back({values[i], weights[i]});
  }

  sort(vec.begin(), vec.end(), comp);


  for(auto x: vec){

     if(x.second <= W){
        //include whole
          value+= (double) x.first;
          W = W - (double)x.second;
       }
       else {

           value += (double) ( (double)x.first / x.second) * W ;
           break;
       }

  }


  return value;
}

int main() {
  // freopen("input.txt", "r" , stdin);
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
