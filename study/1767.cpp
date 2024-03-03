#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

struct CORE {
    int y, x;
};
int TC, N, arr[12][12], max_depth, max_core, min_length;
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
CORE core[12];
vector<int> v;

void DFS(int depth, int connect, int length) {
    if (depth == max_depth) {
        if (connect > max_core) {
            max_core = connect;
            min_length = length;
        }
        else if (connect == max_core) {
            min_length = min(min_length, length);
        }
        return;
    }

    // 현재 core 연결 X
    DFS(depth + 1, connect, length);

    // 현재 core 연결 O
    int cy = core[v[depth]].y, cx = core[v[depth]].x;
    for (int d = 0; d < 4; d++) {
        bool isgood = true;
        int line = 0;

        int dr = cy, dc = cx;
        while (1) {
            dr += dy[d];
            dc += dx[d];
            if (dr < 0 || dr >= N || dc < 0 || dc >= N) break;
            if (arr[dr][dc] == 1 || arr[dr][dc] == 2) {
                isgood = false;
                break;
            }
            line++;
        }
        if (not isgood) continue;

        while (1) {
            dr -= dy[d];
            dc -= dx[d];
            if (dr == cy && dc == cx) break;
            arr[dr][dc] = 2;
        }
        DFS(depth + 1, connect + 1, length + line);
        while (1) {
            dr += dy[d];
            dc += dx[d];
            if (dr < 0 || dr >= N || dc < 0 || dc >= N) break;
            arr[dr][dc] = 0;
        }
    }
}

void init() {
    v.clear();
    max_core = 0;
    min_length = INT_MAX;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        init();
        cin >> N;
        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 0) continue;

                core[idx].y = i; core[idx].x = j;
                if (i > 0 && i < N - 1 && j>0 && j < N - 1) {
                    v.push_back(idx);
                }
                idx++;
            }
        }

        max_depth = v.size();
        DFS(0, 0, 0);

        cout << '#' << tc << ' ' << min_length << '\n';
    }
}