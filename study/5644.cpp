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

struct BC {
    int y, x, C, P;
};
int TC, Aloc_y, Aloc_x, Bloc_y, Bloc_x, M, A, mv[2][101], charge[2][8], ans;
int dr, dc, dy[] = { 0, -1, 0, 1, 0 }, dx[] = { 0, 0, 1, 0, -1 };
BC bc[8];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> M >> A;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> mv[i][j];
            }
        }

        for (int i = 0; i < A; i++) {
            cin >> bc[i].x >> bc[i].y >> bc[i].C >> bc[i].P;
        }

        Aloc_y = 1; Aloc_x = 1;
        Bloc_y = 10; Bloc_x = 10;
        for (int i = 0; i <= M; i++) {
            Aloc_y += dy[mv[0][i]];
            Aloc_x += dx[mv[0][i]];
            Bloc_y += dy[mv[1][i]];
            Bloc_x += dx[mv[1][i]];

            for (int j = 0; j < A; j++) {
                if (abs(Aloc_y - bc[j].y) + abs(Aloc_x - bc[j].x) <= bc[j].C) {
                    charge[0][j] = bc[j].P;
                }
                else {
                    charge[0][j] = 0;
                }
                if (abs(Bloc_y - bc[j].y) + abs(Bloc_x - bc[j].x) <= bc[j].C) {
                    charge[1][j] = bc[j].P;
                }
                else {
                    charge[1][j] = 0;
                }
            }

            for (int j = 0; j < A; j++) {
                for (int k = 0; k < A; k++) {
                    if (j == k && charge[0][j] && charge[1][k]) {
                        pq.push(charge[0][j]);
                    }
                    else {
                        pq.push(charge[0][j] + charge[1][k]);
                    }
                }
            }

            ans += pq.top();
            while (!pq.empty()) pq.pop();
        }
        cout << '#' << tc << ' ' << ans << '\n';
        ans = 0;
    }
}