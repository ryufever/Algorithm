#include <iostream>

using namespace std;

#define INF 987654321

int n; //도시의 개수
int m; //버스의 개수

int graph[101][101];
int dist[101][101];

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}

			if (graph[i][j] != INF) {
				dist[i][j] = graph[i][j];
			}
			else {
				dist[i][j] = INF;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if (k == i || k == j) {
					continue;
				}

				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

}

int main(void) {
	cin >> n;
	cin >> m;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (graph[from][to] > cost) {
			graph[from][to] = cost;
		}
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}


	return 0;
}