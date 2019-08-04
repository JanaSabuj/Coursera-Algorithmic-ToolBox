#include <iostream>
// #define int long long int
using ll = long long ;
#include<bits/stdc++.h>

long long lcm_naive(int a, int b) {
	for (long l = 1; l <= (long long) a * b; ++l)
		if (l % a == 0 && l % b == 0)
			return l;

	return (long long) a * b;
}

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

ll lcm_fast(int a, int b){

	return ((ll)a * b) / (gcd(a,b)) ;

}

int main() {
	// freopen("input.txt", "r" , stdin);
	int a, b;
	std::cin >> a >> b;
	// std::cout << lcm_naive(a, b) << std::endl;
	std::cout << lcm_fast(a, b) << std::endl;
	return 0;
}
