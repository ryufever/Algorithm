#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}


//15kg을 들 수 있는 밧줄 한개로는 최대 15kg을 들 수 있고, 
//10kg을 들 수 있는 밧줄 한개로는 최대 10kg을 들 수 있다.

//15kg로프와, 10kg로프를 같이 사용해서는 25kg을 들 수 있어야 하지만
//10kg로프는 12.5kg을 들 수 없기때문에 kg이 적은 로프에 맞춰진다고 생각한다.
//그러므로 15kg과 10kg로프를 같이 사용하면 10 * 2이므로 20kg을 들 수 있게 된다.

//=> 내림차순으로 정렬한 후 각 로프가 들 수 있는 무게에 (i+1)을 곱한 후 제일 큰 값을 찾아내면 된다.
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