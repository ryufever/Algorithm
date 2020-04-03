#include <iostream>

using namespace std;

int main(void) {
	int x;
	cin >> x;
	int cnt = 1;
	int min = 64;
	int sum = 64;

	while (sum > x) {
		min = min / 2;
		if (sum - min >= x) {
			sum = sum - min;
		}
		else
			cnt++;
	}

	cout << cnt << "\n";
	

	return 0;
}