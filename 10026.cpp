#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int n;
char color[101][101];
char tmp[101][101];
bool visit[101][101] = { false, };

int area_ori = 0;
int area_2 = 0; //적록색약

bool isInside(int x, int y) {
	return (x >= 1) && (x <= n) && (y >= 1) && (y <= n);
}

void bfs(int x, int y) {
	visit[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tmp[i][j] = color[i][j];
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (isInside(nx, ny) && tmp[nx][ny] == color[x][y] && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void turn_color() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (color[i][j] == 'G') {
				color[i][j] = 'R';
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> color[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j]) {
				bfs(i, j);
				area_ori++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		memset(visit[i], false, sizeof(bool) * n + 1);
	}

	turn_color();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j]) {
				bfs(i, j);
				area_2++;
			}
		}
	}

	cout << area_ori << " " << area_2 << "\n";
	return 0;
}