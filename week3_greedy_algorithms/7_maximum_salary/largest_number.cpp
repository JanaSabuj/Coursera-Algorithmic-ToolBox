#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using std::vector;
using std::string;

bool comp(string& X, string& Y){
  string XY = X + Y;
  string YX = Y + X;

  if(XY.compare(YX)>0)
    return 1;
  else
    return 0;
}

string largest_number(vector<string> a) {
  //write your code here

  sort(a.begin(), a.end(),comp);

  string ans = "";
  for(auto x:a){
    ans += x;
  }

  return ans;

}

int main() {
  // freopen("input.txt", "r" , stdin);
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
