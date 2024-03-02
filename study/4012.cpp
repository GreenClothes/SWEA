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

int TC, N, arr[16][16], ans;
vector<int> A, B;

void cook(int depth, int foodA, int foodB) {
	if (foodA == N / 2) {
		int sa = 0, sb = 0;
		for (int i = 0; i < N / 2 - 1; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				sa += arr[A[j]][A[i]];
			}
		}
		for (int d = depth; d < N; d++) {
			B.push_back(d);
		}
		for (int i = 0; i < N / 2 - 1; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				sb += arr[B[j]][B[i]];
			}
		}
		for (int d = depth; d < N; d++) {
			B.pop_back();
		}
		ans = min(ans, abs(sa - sb));
		return;
	}
	else if (foodB == N / 2) {
		int sa = 0, sb = 0;
		for (int i = 0; i < N / 2 - 1; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				sb += arr[B[j]][B[i]];
			}
		}
		for (int d = depth; d < N; d++) {
			A.push_back(d);
		}
		for (int i = 0; i < N / 2 - 1; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				sb += arr[A[j]][A[i]];
			}
		}
		for (int d = depth; d < N; d++) {
			A.pop_back();
		}
		ans = min(ans, abs(sa - sb));
		return;
	}

	A.push_back(depth);
	cook(depth + 1, foodA + 1, foodB);
	A.pop_back();
	B.push_back(depth);
	cook(depth + 1, foodA, foodB + 1);
	B.pop_back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				arr[i][j] += arr[j][i];
			}
		}

		ans = INT_MAX;
		cook(0, 0, 0);

		cout << '#' << tc << ' ' << ans << '\n';
		A.clear();
		B.clear();
	}
}