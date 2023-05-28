// 합성함수와 쿼리
// https://www.acmicpc.net/problem/17435
// Sparse Table

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;
    vvi f;
    vi f1(m + 1, 0);
    REP(i, 1, m + 1) {
        cin >> f1[i];
    }
    f.push_back(f1);

    int log = 2;
    int idx = 1;
    while (log <= 500000) {
        vi tmpf(m + 1, 0);
        REP(i, 1, m + 1) {
            tmpf[i] = f[idx - 1][f[idx - 1][i]];
        }
        f.push_back(tmpf);
        log *= 2;
        idx++;
    }

    // REP(i, 0, f.size()) {
    //     REP(j, 1, m + 1) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int Q;
    cin >> Q;
    unsigned int n;
    int x;
    REP(i, 0, Q) {
        cin >> n >> x;
        int idx = 0;
        while (n != 0) {
            if (n & 1) {
                x = f[idx][x];
            }
            n >>= 1;
            idx++;
        }
        cout << x << endl;
    }

    return 0;
}