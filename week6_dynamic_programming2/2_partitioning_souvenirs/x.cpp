#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>

using std::vector;

int P3(vector<int> &A) {
    //write your code here
    int sum = std::accumulate(A.begin() , A.end() , 0);
    if (A.size() < 3 || !(sum % 3))
        return 0;
    
    int part = std::floor(sum / 3);
    vector<vector<int> > dp (A.size() + 1 , vector<int>(part + 1 , 0));

    for (int i = 1; i <= part; ++i)
    {
        for (int j = 1; j <= A.size(); ++j)
        {
            int k = i - A.at(j - 1);
            if (A.at(j - 1) == i || (k > 0 && dp.at(k).at(j - 1) > 0))
                if (dp.at(i).at(j - 1) == 0)
                    dp.at(i).at(j) = 1;
                else
                    dp.at(i).at(j) = 2;
            else
                dp.at(i).at(j) = dp.at(i).at(j - 1);
        }
    }

    if (dp.at(part).at(A.size()) == 2)
        return true;
    else 
        return false;

    //end
}

int main() 
{    freopen("input.txt", "r" , stdin);
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << P3(A) << '\n';
}