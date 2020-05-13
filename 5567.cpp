#include <iostream>
#include <vector>

using namespace std;

int n; //������ ��
int m; //����Ʈ�� ����

vector<int> fri[501];
bool visit[501] = { false, };
int result = 0;

void findFri(int node) {
	
	//node�� ģ���ľ�
	for (int i = 0; i < fri[node].size(); i++) {
		int next = fri[node][i];
		visit[next] = true;
	}

	//ģ���� ģ���ľ�
	if (node == 1) {
		for (int i = 0; i < fri[node].size(); i++) {
			int next = fri[node][i];
			findFri(next);
		}
	}
}

int main(void) {
	
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		fri[a].push_back(b);
		fri[b].push_back(a);
	}

	findFri(1);

	for (int i = 2; i <= n; i++) {
		if (visit[i] == true) {
			result++;
		}
	}

	cout << result << "\n";

	return 0;
}