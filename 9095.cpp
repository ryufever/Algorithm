#include <iostream>

using namespace std;

//f(x) = f(x-1) + f(x-2) + f(x-3)

int main(void) {
	int t;
	cin >> t;

	int sumOfnum[11];

	sumOfnum[1] = 1;
	sumOfnum[2] = 2;
	sumOfnum[3] = 4;
	for (int i = 4; i < 11; i++) {
		sumOfnum[i] = sumOfnum[i - 1] + sumOfnum[i - 2] + sumOfnum[i - 3];
	}

	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		cout << sumOfnum[num] << "\n";
	}

	return 0;
}