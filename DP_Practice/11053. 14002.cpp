// 가장 긴 증가하는 부분 수열
// // 가장 긴 증가하는 부분 수열 4
// https://www.acmicpc.net/problem/11053
// // https://www.acmicpc.net/problem/14002

#include <iostream>
#include <stack>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using namespace std;

int main() {
    int N;
    cin >> N;

    int P[1001] = {0};
    REP(i, 1, N+1) {
        cin >> P[i];
    }

    int pre[1001] = {0};
    int S[1001] = {0};
    int maxVal;
    REP(x, 1, N+1) {
        maxVal = -1;
        REP(i, 1, x) {
            if (P[i] < P[x] && maxVal < S[i]) {
                maxVal = S[i];
                pre[x] = i;
            }
        }
        if (maxVal == -1) {
            S[x] = 1;
        } else {
            S[x] = maxVal + 1;
        }
    }

    int ans = S[1];
    int ans_idx = 1;
    REP(i, 2, N+1) {
        if (ans < S[i]) {
            ans = S[i];
            ans_idx = i;
        }
    }

    stack<int> s;
    int idx = ans_idx;
    while (pre[idx]) {
        s.push(P[idx]);
        idx = pre[idx];
    }
    s.push(P[idx]);

    cout << ans << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}