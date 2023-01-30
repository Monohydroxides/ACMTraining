#include <bits/stdc++.h>
using namespace std;

int sum;
int arr[8];

int main () {
	for (int i = 1; i <= 7; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	long double res = 1;
	for (int i = 1; i <= 7; ++i) {
		res = res * i;
	}
	for (int i = 1; i <= 6; ++i) {
		res = res * arr[i] / (double) (sum - i + 1);
	}
	res = res * arr[7];
	cout << fixed << setprecision(3) << res << endl;
	return 0;
}