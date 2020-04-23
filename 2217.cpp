#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}


//15kg�� �� �� �ִ� ���� �Ѱ��δ� �ִ� 15kg�� �� �� �ְ�, 
//10kg�� �� �� �ִ� ���� �Ѱ��δ� �ִ� 10kg�� �� �� �ִ�.

//15kg������, 10kg������ ���� ����ؼ��� 25kg�� �� �� �־�� ������
//10kg������ 12.5kg�� �� �� ���⶧���� kg�� ���� ������ �������ٰ� �����Ѵ�.
//�׷��Ƿ� 15kg�� 10kg������ ���� ����ϸ� 10 * 2�̹Ƿ� 20kg�� �� �� �ְ� �ȴ�.

//=> ������������ ������ �� �� ������ �� �� �ִ� ���Կ� (i+1)�� ���� �� ���� ū ���� ã�Ƴ��� �ȴ�.
int main(void) {
	int rope[100001] = { 0, };
	long long result = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}

	sort(rope, rope + n, cmp);

	for (int i = 0; i < n; i++) {
		long long tmp = rope[i] * (i + 1);
		if (tmp > result) {
			result = tmp;
		}
	}

	cout << result;

	return 0;
}