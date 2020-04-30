#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>;

using namespace std;

vector<vector<int>> fri(101); //친구관계
int cnt[101]; //각 친구들까지의 거리차 저장

int n;
int m;
int person = 101;
int ans = 987654321;

//dis = 거리차, num = 친구번호
void dfs(int dis, int num) {
	//cnt[num]에 거리차 저장
	if (cnt[num] != 0) {
		cnt[num] = min(dis, cnt[num]);
	}
	else {
		cnt[num] = dis;
	}

	//연결된 친구 탐색
	for (int j = 0; j < fri[num].size(); j++) {
		int next = fri[num][j];

		//친구를 포함하지않았거나 더 가까운 사이의 친구라면 탐색
		if (cnt[next] == 0 || cnt[next] > dis + 1) {
			dfs(dis + 1, next);
		}
	}
}

int main(void) {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		//서로 연결
		fri[a].push_back(b);
		fri[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		//거리차 초기화
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < fri[i].size(); j++) {
			dfs(1, fri[i][j]);
		}

		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (j == i) {
				continue;
			}
			tmp += cnt[j];
		}

		//최소인지 검사
		if (ans > tmp) {
			ans = tmp;
			person = i;
		}
		else if (ans == tmp) {
			person = min(person, i);
		}
	}

	cout << person << "\n";
	return 0;
}