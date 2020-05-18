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
				//플로이드 와샬이 성립하지 않음
				else if (graph[i][j] > graph[i][k] + graph[k][j]) {
					result = -1;
					return;
				}

				//i -> j로 가는 경로가 k를 거쳐가는 경우와 같다면
				//모든 경로를 최소의 도로로 커버해야하므로 거쳐가는 도로 선택
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

	//i->j 와 j->i모두 계산했으므로 
	else {
		cout << result / 2 << "\n";
	}
	return 0;
}