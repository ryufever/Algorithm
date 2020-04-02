#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> people;

int main(void) {

	int remain[4];

	for (int i = 0; i < 4; i++) {
		int in, out;
		cin >> out >> in;
		people.push_back(make_pair(out, in));
	}


	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			remain[i] = people[i].second - people[i].first;
		}
		else {
			remain[i] = remain[i - 1] - people[i].first + people[i].second;
		}
	}
	
	sort(remain, remain + 4);


	cout << remain[3] << "\n";


	return 0;
}