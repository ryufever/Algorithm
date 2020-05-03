#include<iostream>
#include<queue>
#include <cstring>

using namespace std;

int n; //세로
int m; //가로
int k; //배추위치개수
int bug = 0; //배추벌레 마리수
int map[51][51] = { 0, };
bool visit[51][51];
queue < pair<int, int>> q;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool isInside(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	visit[x][y] = true;

	while (!q.empty()) {
		int tmpx = q.front().first;
		int tmpy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tmpx + dx[i];
			int ny = tmpy + dy[i];

			if (!visit[nx][ny] && isInside(nx, ny) && map[nx][ny] == 1) {
				bfs(nx, ny);
			}
		}
	}
	
}

int main(void) {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		bug = 0;
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		while (!q.empty()) {
			q.pop();
		}
	
		cin >> m >> n >> k;
		for (int kc = 0; kc < k; kc++) {
			int a, b;
			cin >> b >> a;
			map[a][b] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					bug++;
					bfs(i, j);
				}
			}
		}
		cout << bug << "\n";
	}
	return 0;
}