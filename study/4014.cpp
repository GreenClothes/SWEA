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

int TC, N, X, arr[21][21], ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N >> X;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }

        // 가로 활주로
        for (int i = 0; i < N; i++) {
            // 현재 높이(height)와 이어져있는 같은 높이 땅 개수(width)
            int height = arr[i][0], max_height = arr[i][0], width = 1;
            bool isgood = true, slope = false;
            for (int j = 1; j < N; j++) {
                if (arr[i][j] == height) {
                    width++;
                }
                else if (abs(arr[i][j] - height) > 1) {
                    isgood = false;
                    break;
                }
                else {
                    max_height = max(max_height, arr[i][j]);
                    if (width < X && height != max_height) {
                        isgood = false;
                        break;
                    }
                    if (arr[i][j] > height && slope && width < 2 * X) {
                        isgood = false;
                        break;
                    }
                    if (arr[i][j] < height) {
                        slope = true;
                    }
                    else {
                        slope = false;
                    }
                    height = arr[i][j];
                    width = 1;
                }
            }
            if (width < X && slope) continue;
            if (isgood) ans++;
        }

        // 세로 활주로
        for (int j = 0; j < N; j++) {
            int height = arr[0][j], max_height = arr[0][j], width = 1;
            bool isgood = true, slope = false;
            for (int i = 1; i < N; i++) {
                if (arr[i][j] == height) {
                    width++;
                }
                else if (abs(arr[i][j] - height) > 1) {
                    isgood = false;
                    break;
                }
                else {
                    max_height = max(max_height, arr[i][j]);
                    if (width < X && height != max_height) {
                        isgood = false;
                        break;
                    }
                    if (arr[i][j] > height && slope && width < 2 * X) {
                        isgood = false;
                        break;
                    }
                    if (arr[i][j] < height) {
                        slope = true;
                    }
                    else {
                        slope = false;
                    }
                    height = arr[i][j];
                    width = 1;
                }
            }
            if (width < X && slope) continue;
            if (isgood) ans++;
        }

        cout << '#' << tc << ' ' << ans << '\n';
        ans = 0;
    }
}