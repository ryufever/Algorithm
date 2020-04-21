#include <iostream>
#include <algorithm>

using namespace std;

//dp[n] = max(dp[n-2] + cost[n], dp[n-3] + cost[n-1] + cost[n])
int main(void) {
	int dp[301] = { 0, };
	int cost[301] = { 0, };

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	dp[1] = cost[1];
	dp[2] = cost[1] + cost[2];
	dp[3] = max(cost[1] + cost[3], cost[2] + cost[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + cost[i], dp[i - 3] + cost[i - 1] + cost[i]);
	}

	cout << dp[n] << "\n";

	return 0;
}