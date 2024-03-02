#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
using namespace std;

struct Node {
	int y, x;
};
int TC, N, M, R, C, L, dr, dc, arr[50][50], visited[50][50], cnt;
int dd[8][4][2] = {
	{{0, 0}, {0, 0}, {0, 0}, {0, 0}},
	{{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
	{{-1, 0}, {1, 0}, {0, 0}, {0, 0}},
	{{0, -1}, {0, 1}, {0, 0}, {0, 0}},
	{{-1, 0}, {0, 1}, {0, 0}, {0, 0}},
	{{1, 0}, {0, 1}, {0, 0}, {0, 0}},
	{{1, 0}, {0, -1}, {0, 0}, {0, 0}},
	{{-1, 0}, {0, -1}, {0, 0}, {0, 0}}
};
queue<Node> q;
Node qp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}

		L--;
		cnt++;
		visited[R][C] = 1;
		q.push({ R, C });
		while (!q.empty() && L > 0) {
			int q_size = q.size();
			L--;
			for (int qs = 0; qs < q_size; qs++) {
				qp = q.front();
				q.pop();
				int qpy = qp.y, qpx = qp.x;
				int pipe = arr[qpy][qpx];
				for (int i = 0; i < 4; i++) {
					if (dd[pipe][i][0] == 0 && dd[pipe][i][1] == 0) break;
					dr = qpy + dd[pipe][i][0];
					dc = qpx + dd[pipe][i][1];
					if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
					if (visited[dr][dc] || arr[dr][dc] == 0) continue;

					int npipe = arr[dr][dc];
					if (dd[pipe][i][0] == -1 && (npipe == 3 || npipe == 4 || npipe == 7)) continue;
					if (dd[pipe][i][0] == 1 && (npipe == 3 || npipe == 5 || npipe == 6)) continue;
					if (dd[pipe][i][1] == -1 && (npipe == 2 || npipe == 6 || npipe == 7)) continue;
					if (dd[pipe][i][1] == 1 && (npipe == 2 || npipe == 4 || npipe == 5)) continue;

					visited[dr][dc] = 1;
					q.push({ dr, dc });
					cnt++;
				}
			}
		}
		cout << '#' << tc << ' ' << cnt << '\n';
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		while (!q.empty()) q.pop();
	}
}