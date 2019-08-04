#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::map;
using std::cout;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {

  //write your code here

  vector<int> cazz = points;

  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  sort(points.begin(), points.end());

  std::vector<int> num;

  for (auto x : starts) {

    num.push_back(x);
  }
  for (auto x : ends)
    num.push_back(x);
  for (auto x : points)
    num.push_back(x);


  sort(num.begin(), num.end());

  map<int, int> hash;

  int count = 0;

  for (auto x : num) {

    if (binary_search(starts.begin(), starts.end(), x))
      count++;
     if (binary_search(ends.begin(), ends.end(), x))
      count--;
     if (binary_search(points.begin(), points.end(), x))
    {
      hash[x] = count;
    }



  }



  std::vector<int> temp;

  for (auto x : cazz) {

    int val = hash[x];

    temp.push_back(val);
  }

  return temp;
}

// vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//   vector<int> cnt(points.size());
//   for (size_t i = 0; i < points.size(); i++) {
//     for (size_t j = 0; j < starts.size(); j++) {
//       cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
//     }
//   }
//   return cnt;
// }

int main() {
  // freopen("input.txt", "r" , stdin);
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);

  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
