#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> ori;
vector<char> make;
stack<int> st;

int main(void) {
	int num = 1;
	int n;
	cin >> n;
	//만들어야 할 배열
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		ori.push_back(k);
	}

	for (int i = 0; i < n; i++) {
		if (st.empty() || st.top() != ori[i]) {
			while (1) {
				if (num > n) {
					cout << "NO" << "\n";
					return 0;
				}
				st.push(num++);
				make.push_back('+');
				if (st.top() == ori[i]) {
					st.pop();
					make.push_back('-');
					break;
				}
			}
		}
		else if (st.top() == ori[i]) {
			st.pop();
			make.push_back('-');
		}
	}

	for (int i = 0; i < make.size(); i++) {
		cout << make[i] << "\n";
	}

	return 0;
}
