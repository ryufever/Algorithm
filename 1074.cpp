#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int N;
int R;
int C;
int cnt = 0;

void Z(int n, int r, int c) {
	if (n == 2) {
		if (r == R && c == C) {
			cout << cnt << "\n";
			return;
		}
		cnt++;

		if (r == R && c+1 == C) {
			cout << cnt << "\n";
			return;
		}
		cnt++;

		if (r+1 == R && c == C) {
			cout << cnt << "\n";
			return;
		}
		cnt++;

		if (r+1 == R && c+1 == C) {
			cout << cnt << "\n";
			return;
		}
		cnt++;
		return;
	}
	Z(n / 2, r, c);
	Z(n / 2, r, c + n / 2);
	Z(n / 2, r + n / 2, c);
	Z(n / 2, r + n / 2, c + n / 2);
}
int main(void) {
	cin >> N >> R >> C;
	Z(pow(2, N), 0, 0);
	return 0;
}