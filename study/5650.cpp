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

int TC, N, arr[101][101], ans;
int dr, dc, dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
int block[6][4] = {
    {0, 0, 0, 0},
    {1, 3, 0, 2},
    {3, 0, 1, 2},
    {2, 0, 3, 1},
    {1, 2, 3, 0},
    {1, 0, 3, 2}
};
unordered_map<int, vector<pair<int, int>>> um;

int game(int sy, int sx, int y, int x, int d) {
    int score = 0;

    while (1) {

        if ((y == sy && x == sx) || arr[y][x] == -1) {
            return score;
        }
        if (y < 0 || y >= N || x < 0 || x >= N) {
            if (d == 1 || d == 3) d--;
            else d++;
            y += dy[d];
            x += dx[d];
            score++;
        }
        else if (arr[y][x] == 0) {
            y += dy[d];
            x += dx[d];
        }
        else if (arr[y][x] >= 6) {
            auto worm = um[arr[y][x]];
            if (worm[0].first == y && worm[0].second == x) {
                y = worm[1].first;
                x = worm[1].second;
            }
            else {
                y = worm[0].first;
                x = worm[0].second;
            }
            y += dy[d];
            x += dx[d];
        }
        else {
            int b = arr[y][x];
            d = block[b][d];
            y += dy[d];
            x += dx[d];
            score++;
        }
    }
}

void init() {
    ans = 0;
    um.clear();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N;
        init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                if (arr[i][j] >= 6) {
                    um[arr[i][j]].push_back(make_pair(i, j));
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] != 0) continue;
                for (int d = 0; d < 4; d++) {
                    ans = max(ans, game(i, j, i + dy[d], j + dx[d], d));
                }

            }
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }
}