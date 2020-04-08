#include <iostream>

using namespace std;

int dp[41];

int fibonacci(int n) {
	if (n == 0) {
		dp[0] = 0;
		return 0;
	}
	else if (n == 1) {
		dp[1] = 1;
		return 1;
	}
	else {
		if (dp[n] != 0) {
			//�̹� ���� �������� ��ͷ� �ٽ� ���� ������ �ʴ´�!!!
			return dp[n];
		}
		return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}
//0�� ���� : fibonacci(n-1)
//1�� ���� : fibonacci(n)
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;
		
		fibonacci(n);
		if (n == 0) {
			cout << "1 " << "0" << "\n";
		}
		else if (n == 1) {
			cout << "0 " << "1" << "\n";
		}
		else {
			cout << dp[n - 1] << " " << dp[n] << "\n";
		}
		
	}

	return 0;
}