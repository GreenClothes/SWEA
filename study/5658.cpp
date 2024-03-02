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

int TC, N, K;
string input;
unordered_map<string, int> um;
vector<int> v;

bool cmp(int& left, int& right) {
	return left > right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> K;
		cin >> input;

		for (int r = 0; r < N / 4; r++) {
			for (int i = 0; i < N; i += N / 4) {
				char temp[10];
				for (int j = 0; j < N / 4; j++) {
					int idx = (r + i + j) % N;
					temp[j] = input[idx];
				}
				if (um.count(temp)) continue;
				um[temp] = 1;
				v.push_back(int(strtol(temp, NULL, 16)));
			}
		}
		sort(v.begin(), v.end(), cmp);
		cout << '#' << tc << ' ' << v[K - 1] << '\n';
		v.clear();
		um.clear();
	}
}