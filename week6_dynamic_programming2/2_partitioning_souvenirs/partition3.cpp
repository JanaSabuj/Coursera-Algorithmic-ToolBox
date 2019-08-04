#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
	//write your code here
	int sum=0;
	for(auto x:A)
		sum+= x;
	
	return sum/3;
}

int main() {
	freopen("input.txt", "r" , stdin);
	int n;
	std::cin >> n;
	vector<int> A(n);

	for (size_t i = 0; i < A.size(); ++i) {
		std::cin >> A[i];
	}
	std::cout << partition3(A) << '\n';
}
