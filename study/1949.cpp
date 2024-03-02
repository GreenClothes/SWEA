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

int TC, N, K, arr[8][8], max_height, ans, visited[8][8];
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };

void DFS(int depth, int y, int x, int k, bool iscut) {
    for (int i = 0; i < 4; i++) {
        int dr = y + dy[i];
        int dc = x + dx[i];
        if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
        if (visited[dr][dc]) continue;
        int temp_cut = 0;
        
        if (arr[dr][dc] >= arr[y][x]) {
            if (iscut) {
                temp_cut = arr[dr][dc] - arr[y][x] + 1;
                if (temp_cut > k) continue;
                iscut = false;
                arr[dr][dc] -= temp_cut;
                visited[dr][dc] = 1;
                DFS(depth + 1, dr, dc, k - temp_cut, iscut);
                iscut = true;
                arr[dr][dc] += temp_cut;
            }
            else {
                continue;
            }
        }
        else {
            visited[dr][dc] = 1;
            DFS(depth + 1, dr, dc, k, iscut);
        }
        visited[dr][dc] = 0;
    }
    ans = max(depth, ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                max_height = max(max_height, arr[i][j]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] != max_height) continue;
                visited[i][j] = 1;
                DFS(1, i, j, K, true);
                visited[i][j] = 0;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
        ans = 0;
        max_height = 0;
    }
}