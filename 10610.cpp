#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

//30�� ����� �Ƿ��� 0�� �ϳ��� �־�� �Ѵ�.
//30�� ����� �Ƿ��� 3���� �����������Ѵ� 
     //=> �� �ڸ��� ���ڸ� ���� ���ڰ� 3���� �����������Ѵ�.
int main(void) {
	string n;
	cin >> n;

	bool flag = false; 
	int sum = 0;
	
	for (int i = 0; i < n.size(); i++) {
		sum += (n[i] - '0');
		if (n[i] - '0' == 0) {
			flag = true; //0�� ����
		}
	}

	//3�� ����� �ƴϰų� 0�� ���������ʴ´ٸ� 30�� ��� �ƴ�
	if (sum % 3 != 0 || !flag) {
		cout << -1 << "\n";
	}
	else {
		sort(n.begin(), n.end(), cmp);
		cout << n << "\n";
	}

	return 0;
}