#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> con;


//ȸ�ǰ� ������ �ð��� ������쿡 �����ϴ½ð��� ���� �������ֱ�
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main(void) {

	int n;//ȸ�� ����
	cin >> n;
	int cnt = 0; //ȸ���� �ִ� ����
	int allEnd = 0;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		con.push_back(make_pair(start, end));
	}

	//ȸ�ǰ� ������ ������� ���� => ����ȸ�Ǹ� ���� ������ �� ����
	sort(con.begin(), con.end(), cmp);

	allEnd = con[0].second;
	cnt++;
	for (int i = 1; i < n; i++){
		//���� ȸ�ǰ� ������ ���ÿ� ����ȸ�ǰ� ������ �� ����
		if (allEnd <= con[i].first) {
			cnt++;
			allEnd = con[i].second;
		}
	}
	cout << cnt << "\n";

	return 0;
}