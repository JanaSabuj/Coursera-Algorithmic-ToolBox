#include <iostream>

int get_change(int m) {
	//write your code here
	int ans = 0;

	int k1 = m / 10;
	m = m % 10;

	int k2 = m / 5;
	m = m % 5;

	ans = k1 + k2 + m;	



	return ans;
}

int main() {
	// freopen("input.txt", "r" , stdin);
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
