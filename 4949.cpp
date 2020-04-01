#include <iostream>
#include <stack>
#include <string>

using namespace std;


string Check(string s) {
	stack<int> st;
	bool flag = true; 

	for (int i = 0; i < s.length(); i++) {
		//'(', '[' 라면 스택에 저장
		if (s[i] == '(' || s[i] == '[') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (!st.empty() && st.top() == '(') {
				st.pop();
			}
			else {
				flag = false; //균형 x
			}
		} 
		else if (s[i] == ']') {
			if (!st.empty() && st.top() == '[') {
				st.pop();
			}
			else {
				flag = false; 
			}
		}
	}
	if (!st.empty() || flag == false) {
		return "no";
	}
	else {
		return "yes";
	}
}

int main(void) {
	while (1) {
		string s;
		getline(cin, s);

		//입력종료
		if (s == ".") {
			break;
		}
		else {
			cout << Check(s) << "\n";
		}
	}

	return 0;
}