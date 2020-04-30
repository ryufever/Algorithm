#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>;

using namespace std;

vector<vector<int>> fri(101); //ģ������
int cnt[101]; //�� ģ��������� �Ÿ��� ����

int n;
int m;
int person = 101;
int ans = 987654321;

//dis = �Ÿ���, num = ģ����ȣ
void dfs(int dis, int num) {
	//cnt[num]�� �Ÿ��� ����
	if (cnt[num] != 0) {
		cnt[num] = min(dis, cnt[num]);
	}
	else {
		cnt[num] = dis;
	}

	//����� ģ�� Ž��
	for (int j = 0; j < fri[num].size(); j++) {
		int next = fri[num][j];

		//ģ���� ���������ʾҰų� �� ����� ������ ģ����� Ž��
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
		//���� ����
		fri[a].push_back(b);
		fri[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		//�Ÿ��� �ʱ�ȭ
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

		//�ּ����� �˻�
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