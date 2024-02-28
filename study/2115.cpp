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

int TC, N, M, C, arr[10][10], honey[10][10];
priority_queue<int> pq, row_pq;

void init() {
    memset(honey, 0, sizeof(honey));
    while (!pq.empty()) pq.pop();
    while (!row_pq.empty()) row_pq.pop();
}

int get_honey(int depth, int num, int sum, int start, int row) {
    if (sum > C) return -1;
    if (depth == M) {
        return num;
    }

    return max(get_honey(depth + 1, num + arr[row][start + depth] * arr[row][start + depth], sum + arr[row][start + depth], start, row), get_honey(depth + 1, num, sum, start, row));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N >> M >> C;
        init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - M + 1; j++) {
                honey[i][j] = get_honey(0, 0, 0, j, i);
            }
            int max_honey = honey[i][0], max_row_honey = honey[i][0];
            for (int j = 0; j < N - M + 1; j++) {
                int now_honey = honey[i][j];
                if (now_honey > max_row_honey) max_row_honey = now_honey;
                for (int k = j + M; k < N - M + 1; k++) {
                    if (now_honey + honey[i][k] > max_honey) {
                        max_honey = now_honey + honey[i][k];
                    }
                }
            }
            pq.push(max_honey);
            row_pq.push(max_row_honey);
        }
        int row_max = row_pq.top();
        row_pq.pop();
        row_max += row_pq.top();
        if (row_max > pq.top()) {
            cout << '#' << tc << ' ' << row_max << '\n';
        }
        else {
            cout << '#' << tc << ' ' << pq.top() << '\n';
        }
    }
}