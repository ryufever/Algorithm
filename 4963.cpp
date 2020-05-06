#include <iostream>
#include <cstring>

using namespace std;

int w; //가로
int h; //세로
int cnt = 0; //섬의 개수

int map[51][51];
bool visit[51][51] = { false, };

int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

bool isInside(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < h) && (y < w);
}

void bfs(int x, int y) {
	visit[x][y] = true;

	if (map[x][y] == 0) {
		return;
	}

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isInside(nx, ny) && !visit[nx][ny]) {
			bfs(nx, ny);
		}
	}
}

int main(void) {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		else {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					cin >> map[i][j];
				}
			}

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (!visit[i][j] && map[i][j] == 1) {
						cnt++;
						bfs(i, j);
					}
				}
			}
			cout << cnt << "\n";
			memset(visit, false, sizeof(visit));
			memset(map, 0, sizeof(map));
			cnt = 0;
		}
		
	}

	return 0;
}