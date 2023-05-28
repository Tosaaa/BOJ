// 가장 긴 바이토닉 부분 수열
// https://www.acmicpc.net/problem/11054

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int main() {
    int N;
    cin >> N;

    int P[1001] = {0};
    REP(i, 1, N + 1) {
        cin >> P[i];
    }

    int S[1001] = {0};
    int maxVal;
    REP(x, 1, N + 1) {
        maxVal = -1;
        REP(i, 1, x) {
            if (P[i] < P[x] && maxVal < S[i]) {
                maxVal = S[i];
            }
        }
        if (maxVal == -1) {
            S[x] = 1;
        } else {
            S[x] = maxVal + 1;
        }
    }

    int B[1001];
    REP(x, 1, N + 1) {
        maxVal = -1;
        REP(i, 1, x) {
            if (P[i] > P[x] && maxVal < max(S[i], B[i])) {
                maxVal = max(S[i], B[i]);
            }
        }
        if (maxVal == -1) {
            B[x] = 1;
        } else {
            B[x] = maxVal + 1;
        }
    }

    int ans = -1;
    REP(x, 1, N + 1) {
        if (ans < max(S[x], B[x])) ans = max(S[x], B[x]);
    }

    cout << ans << endl;

    return 0;
}