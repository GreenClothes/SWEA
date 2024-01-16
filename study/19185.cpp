#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int N, M, Q, Y[2020], s_idx, t_idx;
        string s[20], t[20];
        cin >> N >> M;

        for (int n = 0; n < N; n++) {
            cin >> s[n];
        }
        for (int m = 0; m < M; m++) {
            cin >> t[m];
        }
        cin >> Q;
        for (int q = 0; q < Q; q++) {
            cin >> Y[q];
        }
        printf("#%d ", i);
        for (int q = 0; q < Q; q++) {
            s_idx = (Y[q] % N - 1 == -1) ? N-1 : Y[q] % N - 1;
            t_idx = (Y[q] % M - 1 == -1) ? M-1 : Y[q] % M - 1;
            cout << s[s_idx] << t[t_idx] << " ";
        }
        cout << endl;
    }
}