#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

	int dp[1001][3] = { 0, }; //비용의 최솟값 저장
	int cost[1001][3] = { 0, }; //각 색의 비용
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	//이전의 집과 같은 색을 칠하면 x
	//dp[n][0] = cost[n][0] + min(dp[n-1][1], dp[n-1][2])
	for (int i = 1; i <= n; i++) {

		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

	return 0;
}