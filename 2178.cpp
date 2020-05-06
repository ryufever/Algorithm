#include <iostream>
#include <queue>

using namespace std;

char map[101][101];
int path[101][101] = { 0, };

int n; //세로
int m; //가로

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool isInside(int x, int y) {
	return (x > 0) && (y > 0) && (x <= n) && (y <= m);
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	path[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny) && map[nx][ny] == '1' && path[nx][ny] == 0) {
				path[nx][ny] = path[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

}

int main(void) {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	bfs(1, 1);

	cout << path[n][m] << "\n";
	
	return 0;
}