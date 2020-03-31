#include <iostream>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m; //방사이즈
int x, y; //현재위치
int dir;//방향
int map[51][51] = { 0, };

bool isInside(int x, int y) {
	return (x >= 0) && (x < n) && (y >= 0) && (y < m);
}

int turnDir(int dir) {
	if (dir == 0)
		return 3;
	else if (dir == 1)
		return 0;
	else if (dir == 2)
		return 1;
	else if (dir == 3)
		return 2;
}

void Clean() {
	int room = 0;

	//시작지점
	map[x][y] = 2;
	room++;

	int nx, ny, nd;

	while (1) {
		int first_d = dir;
		bool can = false;
		int cant = 0;

		//네방향 확인
		for (int i = 0; i < 4; i++) {
			nd = turnDir(dir); 
			nx = x + dx[nd];
			ny = y + dy[nd];

			if (map[nx][ny] == 0) {
				can = true;
				break;
			}

			else if (map[nx][ny] == 1 || map[nx][ny] == 2 || !isInside(nx, ny)) {
				dir = nd;
				cant++;
			}
		}

		if (can == true) {
			room++;
			map[nx][ny] = 2;
			dir = nd;
		}

		if (cant == 4) {
			nx = x - dx[first_d];
			ny = y - dy[first_d];
			dir = first_d;

			if (!isInside(nx, ny) || map[nx][ny] == 1) {
				break;
			}
		}

		x = nx;
		y = ny;
	}

	cout << room << "\n";
}

int main(void) {
	
	cin >> n >> m; 
	cin >> x >> y >> dir;

	//방구조
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	Clean();


	return 0;
}


