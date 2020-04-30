#include <iostream>
#include <vector>

using namespace std;

int box[1002][1002];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int m, n;
int day = 0;
int cntZero = 0;

vector<pair<int, int>> tmp;
vector<pair<int, int>> v;

void dfs() {
	while (!v.empty()) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < 4; j++) {
				int nx = v[i].first + dx[j];
				int ny = v[i].second + dy[j];
				if (box[nx][ny] == 0) {
					box[nx][ny] = 1;
					tmp.emplace_back(nx, ny);
					cntZero--;
				}
			}
		}
		if (tmp.empty())
			break;
		v.clear();
		while (!tmp.empty()) {
			v.push_back(tmp.back());
			tmp.pop_back();
		}
		day++;
	}
}

//익은 토마토는 인접한 토마토를 하루동안 익힐 수 있다.
//익은 토마토에 익혀진 토마토를 그날 바로 체크하면 안된다
//  -> 한번 루프를 돌때 익혀진 토마토를 익었다고 체크해버리면 다음 검사할때 익혀진 토마토도 포함됨
int main() {

	cin >> m >> n;

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++)
			box[i][j] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				v.emplace_back(i, j);
			if (box[i][j] == 0)
				cntZero++;
		}
	}
	dfs();
	
	if (cntZero > 0) {
		cout << -1 << "\n";
	}
	else {
		cout << day << "\n";
	}
	return 0;
}