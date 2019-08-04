#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int n = stops.size();
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);


    int curr = 0, count = 0;

    while (curr <= n) {
        int i = curr;
        int j;
        for ( j = i + 1; j <= n + 1; j++) {

            if ((stops[j] - stops[i]) > tank) {
                break;
            }
        }

        j--;

        if (j == n + 1)
            break;

        if (i == j)
            return -1;

        curr = j;
        count++;

    }

    return count;

    // return -1;
}


int main() {
    // freopen("input.txt", "r" , stdin);
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
