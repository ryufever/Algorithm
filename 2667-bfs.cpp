#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;
	cnt_home++;

	while (!q.empty()) {
		int tmpx = q.front().first;
		int tmpy = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = tmpx + dx[i];
			int ny = tmpy + dy[i];
			if (map[nx][ny] == '1' && isInside(nx, ny) && !visit[nx][ny]) {
				bfs(nx, ny);
			}
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
			if (map[i][j] == '1' && !visit[i][j]) {
				cnt++;
				cnt_home = 0; //단지마다 집 수 초기화
				bfs(i, j);
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