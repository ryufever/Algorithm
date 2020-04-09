#include <iostream>

using namespace std;

// 0~ 9 �� ���� ������ �迭
long long check[10];


// ten�� �ڸ� ��(���� �ڸ�, �����ڸ� .. )
// calc�Լ��� n�̶�� ���ڿ� ������ 0~9���� check�迭�� �־��ش�.
void calc(long long n, long long ten){
	while (n > 0) {
		check[n % 10] += ten;
		n /= 10;
	}
}

void solve(long long A, long long B, long long ten) {
	// A�� ++ ��Ű�鼭 0�� �����.
	while (A % 10 != 0 && A <= B){
		// A�� ++ ��ų���� calc�� ���ľ��Ѵ�.
		calc(A, ten);
		A++;
	}
	if (A > B) return;

	while (B % 10 != 9 && B >= A){
		//B�� -- ��ų���� calc�� ���ľ� �Ѵ�.
		calc(B, ten);
		B--;
	}

	long long cnt = (B / 10 - A / 10 + 1);

	//B-A +1 * �ڸ��� ��ŭ 0~9�� ���� �����ش�
	for (int i = 0; i < 10; ++i)
		check[i] += cnt * ten;

	// �����ڸ� ���� ������� ����Լ� ȣ���Ѵ�.
	solve(A / 10, B / 10, ten * 10);
}

int main(void){

	long long n;
	cin >> n;

	solve(1, n, 1);
	for (int i = 0; i < 10; ++i)
		cout << check[i] << " ";

	return 0;
}