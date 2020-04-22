#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> con;


//회의가 끝나는 시간이 같을경우에 시작하는시간에 따라서 정렬해주기
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main(void) {

	int n;//회의 개수
	cin >> n;
	int cnt = 0; //회의의 최대 개수
	int allEnd = 0;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		con.push_back(make_pair(start, end));
	}

	//회의가 끝나는 순서대로 정렬 => 다음회의를 빨리 시작할 수 있음
	sort(con.begin(), con.end(), cmp);

	allEnd = con[0].second;
	cnt++;
	for (int i = 1; i < n; i++){
		//이전 회의가 끝남과 동시에 다음회의가 시작할 수 있음
		if (allEnd <= con[i].first) {
			cnt++;
			allEnd = con[i].second;
		}
	}
	cout << cnt << "\n";

	return 0;
}