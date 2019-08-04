#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include<bits/stdc++.h>

using std::vector;
using std::pair;

struct Segment {
  int start, end;
};

bool comp(pair<int,int>& a, pair<int,int>& b){

   return a.second<b.second;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  std::vector<pair<int,int>> vec;

  for (size_t i = 0; i < segments.size(); ++i) {
    // points.push_back(segments[i].start);
    // points.push_back(segments[i].end);
    vec.push_back({segments[i].start, segments[i].end});
  }

  sort(vec.begin(), vec.end(), comp);

  int curr;
  int count=0;

  curr = vec[0].second;
  count++;
  points.push_back(curr);

  for (int i = 1; i < vec.size(); ++i)
  {
    /* code */
     int l = vec[i].first;
     int r = vec[i].second;

     if(curr>= l and curr<=r){
       continue;
     }
     else {
       curr = vec[i].second;
       count++;
       points.push_back(curr);
     }
  }
 
  

  return points;
}
 
int main() {
  // freopen("input.txt", "r" , stdin);
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
