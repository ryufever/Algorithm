#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int n;
int cnt = 0; //안전지역 개수
int height;
int min_height = 98765431;
int max_height = 0;

int map[101][101];
bool visit[101][101] = { false, };


bool isInside(int x, int y) {
	return (x >= 1) && (x <= n) && (y >= 1) && (y <= n);
}

void dfs(int x, int y) {
	visit[x][y] = true;

	if (map[x][y] <= height) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isInside(nx, ny) && !visit[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int result = 1;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			min_height = min(min_height, map[i][j]);
			max_height = max(max_height, map[i][j]);
		}
	}

	for (height = min_height; height <= max_height; height++) {
		memset(visit, false, sizeof(visit)); //높이 바뀔때마다 방문 초기화
		cnt = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visit[i][j] && map[i][j] > height) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		result = max(result, cnt);
	}

	cout << result << "\n";

	return 0;
}