#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node {
    int id, direc, cnt;
};
int TC, N, M, K, r, c, num, direc, total_num;
int dr, dc, dy[] = { 0, -1, 1, 0, 0 }, dx[] = { 0, 0, 0, -1, 1 };
deque<Node> v[100][100];
unordered_map<int, int> bio;

void init() {
    bio.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v[i][j].clear();
        }
    }
    total_num = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N >> M >> K;
        init();
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            cin >> r >> c >> num >> direc;
            total_num += num;
            v[r][c].push_back({cnt, direc, 0});
            bio[cnt] = num;
            cnt++;
        }

        cnt = 0;
        while (cnt < M) {
            cnt++;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (v[i][j].size() == 0) continue;
                    while (!v[i][j].empty()) {
                        Node temp = v[i][j].front();
                        if (temp.cnt == cnt) break;
                        v[i][j].pop_front();
                        if (bio[temp.id] == 0) continue;

                        dr = i + dy[temp.direc];
                        dc = j + dx[temp.direc];
                        if (dr == 0 || dr == N - 1 || dc == 0 || dc == N - 1) {
                            int temp_num = bio[temp.id] / 2;
                            total_num -= (bio[temp.id] - temp_num);
                            bio[temp.id] = temp_num;
                            if (temp_num == 0) {
                                continue;
                            }
                            int n_direc = temp.direc == 2 || temp.direc == 4 ? temp.direc - 1 : temp.direc + 1;
                            v[dr][dc].push_back({ temp.id, n_direc, cnt });
                        }
                        else {
                            v[dr][dc].push_back({ temp.id, temp.direc, cnt });
                        }
                    }
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (v[i][j].size() < 2) continue;
                    int max_id = 0;
                    deque<Node> temp_q = v[i][j];
                    for (int k = 1; k < temp_q.size(); k++) {
                        if (bio[temp_q[k].id] > bio[temp_q[max_id].id]) {
                            max_id = k;
                        }
                    }
                    for (int k = 0; k < temp_q.size(); k++) {
                        if (k == max_id) continue;
                        bio[temp_q[max_id].id] += bio[temp_q[k].id];
                        bio[temp_q[k].id] = 0;
                    }
                }
            }
        }
        cout << '#' << tc << ' ' << total_num << '\n';
    }
}