#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
int M;

string origin[51];


string whiteFirst[9] = {
	{ "WBWBWBWB" },

	{ "BWBWBWBW" },

	{ "WBWBWBWB" },

	{ "BWBWBWBW" },

	{ "WBWBWBWB" },

	{ "BWBWBWBW" },

	{ "WBWBWBWB" },

	{ "BWBWBWBW" }
};

string blackFirst[9] = {
	{ "BWBWBWBW" },

	{ "WBWBWBWB" },

	{ "BWBWBWBW" },

	{ "WBWBWBWB" },

	{ "BWBWBWBW" },

	{ "WBWBWBWB" },

	{ "BWBWBWBW" },

	{ "WBWBWBWB" }
};

int whiteFirstCh(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (origin[i][j] != whiteFirst[i - x][j - y]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int blackFirstCh(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (origin[i][j] != blackFirst[i - x][j - y]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> origin[i];
	}
	
	int result = 987654321;

	for (int i = 0; i + 7 < N; i++) {
		for (int j = 0; j + 7 < M; j++) {
			result = min(result, min(whiteFirstCh(i, j), blackFirstCh(i, j)));
		}
	}
	cout << result << "\n";
	return 0;
}