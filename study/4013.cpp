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

int TC, K, num, direc, input, ans;
deque<int> magnet[5];

void init() {
	ans = 0;
	for (int i = 1; i <= 4; i++) {
		while (!magnet[i].empty()) magnet[i].pop_back();
	}
}

void set_left_magnet(int num, int direc) {
	if (direc == -1) {
		if (magnet[num + 1][7] == magnet[num][2]) return;
		int temp = magnet[num].front();
		magnet[num].pop_front();
		magnet[num].push_back(temp);
	}
	else {
		if (magnet[num + 1][5] == magnet[num][2]) return;
		int temp = magnet[num].back();
		magnet[num].pop_back();
		magnet[num].push_front(temp);
	}
	if (num > 1) {
		set_left_magnet(num - 1, -direc);
	}
}

void set_right_magnet(int num, int direc) {
	if (direc == -1) {
		if (magnet[num - 1][3] == magnet[num][6]) return;
		int temp = magnet[num].front();
		magnet[num].pop_front();
		magnet[num].push_back(temp);
	}
	else {
		if (magnet[num - 1][1] == magnet[num][6]) return;
		int temp = magnet[num].back();
		magnet[num].pop_back();
		magnet[num].push_front(temp);
	}
	if (num < 4) {
		set_right_magnet(num + 1, -direc);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		init();
		cin >> K;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> input;
				magnet[i].push_back(input);
			}
		}

		for (int k = 0; k < K; k++) {
			cin >> num >> direc;
			
			if (direc == -1) {
				int temp = magnet[num].front();
				magnet[num].pop_front();
				magnet[num].push_back(temp);
			}
			else {
				int temp = magnet[num].back();
				magnet[num].pop_back();
				magnet[num].push_front(temp);
			}

			if (num > 1) {
				set_left_magnet(num - 1, -direc);
			}
			if (num < 4) {
				set_right_magnet(num + 1, -direc);
			}		
		}
		for (int i = 1; i <= 4; i++) {
			ans += magnet[i][0] * pow(2, i - 1);
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}