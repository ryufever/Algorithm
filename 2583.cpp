#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int map[101][101] = { 0, };
bool visit[101][101] = { false, };

int n, m;
int k;
int cnt = 0;
int cnt_area = 0;
vector<int> area;

bool isInside(int x, int y) {
	return (x >= 0) && (x < n) && (y >= 0) && (y < m);
}

void dfs(int x, int y) {
	visit[x][y] = 1;

	if (map[x][y] == 1) {
		return;
	}

	cnt_area++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
	
		if (isInside(nx, ny) && !visit[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main(void) {
	//x축이 뒤집혀있으므로 주의해서 입력받기
	cin >> n >> m >> k;
	for(int a = 0; a < k; a++) {
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				map[i][j] = 1;
				visit[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && map[i][j] == 0) {
				cnt++;
				cnt_area = 0;
				dfs(i, j);
				area.push_back(cnt_area);
			}
		}
	}

	sort(area.begin(), area.end());
	cout << cnt << "\n";
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}
	return 0;
}


//5 7 3
//0 2 4 4
//1 1 2 5
//4 0 6 2