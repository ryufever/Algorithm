#include<iostream>
#include<cstring>

using namespace std;

int m; //가로
int n; //세로
int k; //배추가 심어져 있는 위치의 개수
int bugs = 0; //배추벌레

int bat[51][51];
bool visit[51][51];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

bool isInside(int x, int y){
	return (x >= 0) && (x < n) && (y >= 0) && (y < m);
}

void dfs(int x, int y){
	visit[x][y] = 1;

	if (bat[x][y] == 0){
		return;
	}

	for (int k = 0; k < 4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (isInside(nx, ny) && !visit[nx][ny]){
			dfs(nx, ny);
		}
	}
}

int main(void){
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++){
		cin >> m >> n >> k;
		//밭 초기화
		for (int i = 0; i < n; i++){
			memset(bat[i], 0, sizeof(int) * m);
		}
		for (int i = 0; i < n; i++){
			memset(visit[i], 0, sizeof(bool) * m);
		}
		for (int i = 0; i < k; i++){
			int from;
			int to;
			cin >> from >> to;
			bat[to][from] = 1;
		}

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (bat[i][j] == 1 && !visit[i][j]){
					bugs++;
					dfs(i, j);
				}
			}
		}
		cout << bugs << "\n";
		bugs = 0;
	}
	return 0;
}