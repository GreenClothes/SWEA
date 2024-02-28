#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int TC, N, plu, sub, mul, di, nums[12];
vector<int> v;

void DFS(int num, int idx) {
    if (idx == N) {
        v.push_back(num);
        return;
    }

    if (plu > 0) {
        plu--;
        DFS(num + nums[idx], idx + 1);
        plu++;
    }
    if (sub > 0) {
        sub--;
        DFS(num - nums[idx], idx + 1);
        sub++;
    }
    if (mul > 0) {
        mul--;
        DFS(num * nums[idx], idx + 1);
        mul++;
    }
    if (di > 0) {
        di--;
        DFS(num / nums[idx], idx + 1);
        di++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N;
        cin >> plu >> sub >> mul >> di;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        DFS(nums[0], 1);
        sort(v.begin(), v.end());
        cout << '#' << tc << ' ' << v[v.size() - 1] - v[0] << '\n';
        v.clear();
    }
}