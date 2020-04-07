#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main(void) {

	int n;

	cin >> n;
	/*dp[n]은 dp[n-1]/ dp[n/2] / dp[n/3]에서 연산을 한번 더 수행하면 만들 수 있음
		-> dp[n]은 최소연산수여서 min()을 사용*/
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[n] << "\n";

	return 0;
}