#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::map;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

int hashmap(vector<int> &a, int left, int right){

    map<int,int> hash;

    for(auto x: a){
      hash[x]++;
    }

    int n = a.size();

    for(auto x:hash){
       if(x.second > n/2)
         return 1;
    }

    return 0;


}

int main() {
  // freopen("input.txt", "r" , stdin);
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  std::cout << hashmap(a, 0, a.size())  << '\n';
}
