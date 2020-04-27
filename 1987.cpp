#include <iostream>

using namespace std;

int r; //세로
int c; //가로
int max_move = 1;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool checkAlpha[26] = { false, };
char board[21][21];

bool isInside(int x, int y) {
	return (x >= 1) && (y >= 1) && (x <= r) && (y <= c);
}

void dfs(int x, int y, int max) {
	if (max > max_move) {
		max_move = max;
	}

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (!checkAlpha[board[nx][ny] - 'A'] && isInside(nx, ny)) {
			//알파벳 방문
			//백트래킹이 필요한 이유 : 밟았던 알파벳이 포함된 다른 경로가 
			//더 많은 칸일 수 있기때문
			checkAlpha[board[nx][ny] - 'A'] = true;
			dfs(nx, ny, max + 1);
			checkAlpha[board[nx][ny] - 'A'] = false;
		}
	}
}

int main(void) {
	
	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
		}
	}

	checkAlpha[board[1][1] - 'A'] = true; //좌측 상단칸 포함
	dfs(1, 1, 1);
	cout << max_move << "\n";
	return 0;
}