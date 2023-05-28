// 정수 삼각형
// https://www.acmicpc.net/problem/

#include <iostream>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

using namespace std;

int main() {
    int N;
    cin >> N;

    int P[501][501] = {0};
    REP(i, 1, N + 1) {
        REP(j, 1, i + 1) {
            cin >> P[i][j];
        }
    }

    int S[501][501] = {0};
    S[1][1] = P[1][1];
    REP(i, 2, N + 1) {
        REP(j, 1, i + 1) {
            if (j == 1) {
                S[i][j] = S[i-1][j] + P[i][j];
            } else if (j == i) {
                S[i][j] = S[i-1][j-1] + P[i][j];
            } else {
                S[i][j] = max(S[i-1][j-1], S[i-1][j]) + P[i][j];
            }
        }
    }

    int M = S[N][1];
    REP(i, 2, N + 1) {
        if (M < S[N][i])
            M = S[N][i];
    }

    cout << M << endl;

    return 0;
}