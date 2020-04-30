#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int map[301][301];
bool visit[301][301] = { false, };
int year = 0;
int cnt = 0; //¶³¾îÁø ºù»ê¼ö

int n; //¼¼·Î
int m; //°¡·Î
bool flag = false;

bool isInside(int x, int y) {
	return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}

void melt() {
	int copy[301][301];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			if (copy[i][j] > 0) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					
					if (copy[nx][ny] == 0) {
						cnt++;
					}
				}
				map[i][j] -= cnt;
				if (map[i][j] < 0) {
					map[i][j] = 0;
				} 
			}
			
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = true;

	if (map[x][y] == 0) {
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

void printmap() {
	cout << "-------printmap-----------------" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

}

int main(void) {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		memset(visit, false, sizeof(visit));
		flag = false;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !visit[i][j]) {
					cnt++;
					if (cnt >= 2) {
						flag = true;
						break;
					}
					dfs(i, j);
				}
			}
			
		}
		if (flag == true) {
			break;
		}
		if (cnt == 0) {
			year = 0;
			break;
		}
		melt();
		//printmap();
		year++;
	}

	cout << year << "\n";

	return 0;
}