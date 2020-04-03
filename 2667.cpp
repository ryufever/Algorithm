#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

char map[25][25];
bool visit[25][25] = { 0, };

int n;
int cnt = 0; //단지 수
vector<int> home; //단지마다 집 수
int cnt_home = 0;


bool isInside(int x, int y) {
	return (x >= 1) && (x <= n) && (y >= 1) && (y <= n);
}

void dfs(int x, int y) {
	visit[x][y] = 1;

	if (map[x][y] == '0') {
		return;
	}
	
	cnt_home++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isInside(nx, ny) && !visit[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == '1'&& !visit[i][j]) {
				cnt++;
				cnt_home = 0; //단지마다 집 수 초기화
				dfs(i, j);
				home.push_back(cnt_home);
			}
		}
	}

	cout << cnt << "\n";
	sort(home.begin(), home.end());
	for (int i = 0; i < home.size(); i++) {
		cout << home[i] << "\n";
	}

	return 0;
}

