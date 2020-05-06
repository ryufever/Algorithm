#include <iostream>
#include <queue>

using namespace std;

char map[1001][1001];
int path[1001][1001][2]; //x, y, 벽을 뚫을 수 있는 횟수

bool wall = false;
bool block = false;
int n; //세로
int m; //가로


int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool isIniside(int x, int y) {
	return (x > 0) && (y > 0) && (x <= n) && (y <= m);
}

void printMap() {
	cout << "-----------printMap--------------" << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << path[i][j][0];
		}
		cout << "\n";
	}

	cout << "------------printMap1-------------" << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << path[i][j][1];
		}
		cout << "\n";
	}
}

void bfs(int x, int y, int flag) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(x, y), flag));
	path[1][1][1] = 1;
	

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		flag = q.front().second;
		q.pop();

		if (x == n && y == m) {
			cout << path[x][y][flag] << "\n";
			return;
		}
		//cout << path[x][y][flag] << " ";


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isIniside(nx, ny)) {
				//갈수 없는 길 + 벽을 아직 안뚫었을때
				if (map[nx][ny] == '1' && flag == 1) {
					path[nx][ny][flag - 1] = path[x][y][flag] + 1;
					q.push(make_pair(make_pair(nx, ny), flag - 1));
				}
				//갈수 있는 길 + 방문하지 x
				if (map[nx][ny] == '0' && path[nx][ny][flag] == 0) {
					path[nx][ny][flag] = path[x][y][flag] + 1;
					q.push(make_pair(make_pair(nx, ny), flag));
				}
			}
		}
	}
	//목적지도착x + 탐색 끝
	cout << -1 << "\n";
	return;
}

int main(void) {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	
	bfs(1, 1, 1);
	//printMap();
	//cout << path[n][m] << "\n";

	return 0;
}