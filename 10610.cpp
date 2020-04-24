#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

//30의 배수가 되려면 0이 하나라도 있어야 한다.
//30의 배수가 되려면 3으로 나누어져야한다 
     //=> 각 자리의 숫자를 더한 숫자가 3으로 나누어져야한다.
int main(void) {
	string n;
	cin >> n;

	bool flag = false; 
	int sum = 0;
	
	for (int i = 0; i < n.size(); i++) {
		sum += (n[i] - '0');
		if (n[i] - '0' == 0) {
			flag = true; //0이 존재
		}
	}

	//3의 배수가 아니거나 0이 존재하지않는다면 30의 배수 아님
	if (sum % 3 != 0 || !flag) {
		cout << -1 << "\n";
	}
	else {
		sort(n.begin(), n.end(), cmp);
		cout << n << "\n";
	}

	return 0;
}