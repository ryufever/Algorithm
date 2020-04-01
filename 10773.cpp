#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main(void) {
	int sum = 0;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if(!st.empty())
				st.pop();
		}
		else
			st.push(num);
	}
	
	for (int i = 0; !st.empty(); i++) {
		sum += st.top();
		st.pop();
	}
	cout << sum << "\n";
	return 0;
}