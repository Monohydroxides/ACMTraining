#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct medicine {
	long long time;
	long long value;
};

long long dp[10000001];
struct medicine data[10001];

long long maxab(long long a, long long b) {
	return a > b ? a : b;
}
int main() {

	long long totaltime, n;
	long long i, j;

	scanf("%lld %lld", &totaltime, &n);

	for (i = 1; i <= n; i++) {
		scanf("%lld %lld", &data[i].time, &data[i].value);
	}

	for (i = 1; i <= totaltime; i++) {
		for (j = 1; j <= n; j++) {
			if(i >= data[j].time)
			{
				dp[i] = maxab(dp[i], dp[i - data[j].time] + data[j].value);
			}
		}
	}
	printf("%lld", dp[totaltime]);
	return 0;
}