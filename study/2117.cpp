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
int TC, N, M, arr[20][20], max_home_cnt;
int dr, dc, dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
queue<Node> q;
Node qp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int visited[20][20], cnt = 1, home_cnt = 0, temp_cost = 0;
				memset(visited, 0, sizeof(visited));
				visited[i][j] = 1;
				if (arr[i][j]) home_cnt = 1;
				q.push({ i, j });
				while (!q.empty()) {
					temp_cost = home_cnt * M - cnt * cnt - (cnt - 1) * (cnt - 1);
					if (temp_cost >= 0 && home_cnt > max_home_cnt) {
						max_home_cnt = home_cnt;
					}
					cnt++;
					int q_size = q.size();
					for (int qs = 0; qs < q_size; qs++) {
						qp = q.front();
						q.pop();

						for (int d = 0; d < 4; d++) {
							dr = qp.y + dy[d];
							dc = qp.x + dx[d];
							if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
							if (visited[dr][dc]) continue;
							visited[dr][dc] = 1;
							if (arr[dr][dc]) home_cnt++;
							q.push({ dr, dc });
						}
					}
				}
			}
		}

		cout << '#' << tc << ' ' << max_home_cnt << '\n';
		max_home_cnt = 0;
	}
}