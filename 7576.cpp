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

//���� �丶��� ������ �丶�並 �Ϸ絿�� ���� �� �ִ�.
//���� �丶�信 ������ �丶�並 �׳� �ٷ� üũ�ϸ� �ȵȴ�
//  -> �ѹ� ������ ���� ������ �丶�並 �;��ٰ� üũ�ع����� ���� �˻��Ҷ� ������ �丶�䵵 ���Ե�
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