
/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define dbg(x) cerr << #x << " = " << x << endl
#define endl "\n"
#define int long long int
#define double long double
#define pb push_back
#define mp make_pair
#define PI acos(-1)

//const int INF=1e9+5;//billion
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
string alpha = "abcdefghijklmnopqrstuvwxyz";
/*----------JU IS LOVE----------*/
//int power(int a,int b,int m){int ans=1;while(b){if(b&1)ans=(ans*a)%m;b/=2;a=(a*a)%m;}return ans;}
//int power(int a, int b){int ans=1;while(b){if(b&1)ans=ans*a;b/=2;a=a*a;}return ans;}

void merge(int arr[], int l, int m, int r) {

	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1];
	int R[n2];

	for (int i = 0; i < n1; ++i)
	{
		/* code */
		L[i] = arr[l + i];
	}

	for (int j = 0; j < n2; ++j)
	{
		/* code */
		R[j] = arr[m + j + 1];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 and j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		}
		else if (L[i] > R[j]) {
			arr[k++] = R[j++];
		} 
		 
	}

	while (i < n1) {
		arr[k++] = L[i++];
	}

	while (j < n2) {
		arr[k++] = R[j++];
	}
		

}



void mergeSort(int arr[], int l, int r) {

	if (l < r)
	{	int m = (l+r) / 2;

		mergeSort(arr, l , m);
		mergeSort(arr, m + 1 , r);

		merge(arr, l , m, r);
	}
}

signed main() {

	freopen("input.txt", "r", stdin);
	crap;

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> arr[i];
	}

	mergeSort(arr, 0 , n - 1);

	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout << arr[i] << " ";
	}

	return 0;
}




