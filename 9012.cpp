#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isVps(string a) {
	stack<char> st;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '(') {
			st.push(a[i]);
		}
		else if (a[i] == ')') {
			if (!st.empty()) {
				st.pop();
			}
			else {
				return false;
			}
		}
	}

	if (!st.empty()) {
		return false;
	}
	else {
		return true;
	}
	
}

int main(void) {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		string a;
		cin >> a;
		if (isVps(a) == false) {
			cout << "NO" << "\n";
		}
		else if (isVps(a) == true) {
			cout << "YES" << "\n";
		}
	}
	return 0;
}