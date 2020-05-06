#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101];
bool visit[101][101] = { false, };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int n;
int minRoad = 987654321; //다른섬까지의 최소거리
int landNum = 1;
vector<int> cnt_arr;

bool isInside(int x, int y) {
	return (x >= 0) && (x < n) && (y >= 0) && (y < n);
}

//떨어져있는 섬별로 번호붙이기
void landNum_dfs(int x, int y) {
	visit[x][y] = true;
	map[x][y] = landNum;
	
	if (map[x][y] == 0) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isInside(nx, ny) && !visit[nx][ny]) {
			if (map[nx][ny] == 1) {
				landNum_dfs(nx, ny);
			}
		}
	}
}

//cnt = 섬번호
int bfs(int cnt) {
	queue<pair<int, int>> q;
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == cnt) {
				visit[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (isInside(nx, ny)) {
					//다른섬에 도착
					if (map[nx][ny] && map[nx][ny] != cnt) {
						return result;
					}
					//아직 다른섬에 방문 x + 방문 x
					if (map[nx][ny] == 0 && !visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}

			}
		}
		result++;
	}
}


void printMap() {
	cout << "-------------printmap-------------" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
void printvisit() {
	cout << "-------------printvisit-------------" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				landNum_dfs(i, j);
				landNum++;
			}
		}
	}

	//printMap();

	for (int i = 1; i < landNum; i++) {
		memset(visit, false, sizeof(visit));
		minRoad = min(minRoad, bfs(i));
		//printvisit();
	}
	
	cout << minRoad << "\n";

	return 0;
}