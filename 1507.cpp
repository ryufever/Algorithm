#include <iostream>
#include <cstring>

using namespace std;

int N;
int graph[21][21];
bool road[21][21];
int result = 0;

void floydWarshall() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j || j == k || k == i) {
					continue;
				}
				//�÷��̵� �ͼ��� �������� ����
				else if (graph[i][j] > graph[i][k] + graph[k][j]) {
					result = -1;
					return;
				}

				//i -> j�� ���� ��ΰ� k�� ���İ��� ���� ���ٸ�
				//��� ��θ� �ּ��� ���η� Ŀ���ؾ��ϹǷ� ���İ��� ���� ����
				else if (graph[i][j] == graph[i][k] + graph[k][j]) {
					road[i][j] = false;
				}
			}
		}
	}
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	memset(road, true, sizeof(road));
	floydWarshall();

	if(result != -1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (road[i][j] == true) {
					result += graph[i][j];
				}
			}
		}
		
	}


	if (result == -1) {
		cout << -1 << "\n";
	}

	//i->j �� j->i��� ��������Ƿ� 
	else {
		cout << result / 2 << "\n";
	}
	return 0;
}