// 구간 합 구하기 5
// https://www.acmicpc.net/problem/11660

#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> pos(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> S(N + 1, vector<int>(N + 1, 0));
    REP(x, 1, N + 1) {
        REP(y, 1, N + 1) {
            cin >> pos[x][y];
        }
    } 

    REP(x, 1, N + 1) {
        REP(y, 1, N + 1) {
            if (x >= 2) S[x][y] += S[x - 1][y];
            if (y >= 2) S[x][y] += S[x][y - 1];
            if (x >= 2 && y >= 2) S[x][y] -= S[x-1][y-1];
            S[x][y] += pos[x][y];
            //cout << S[x][y] << " ";
        }
        //cout << endl;
    }

    int x1, x2, y1, y2;
    // S = S(x2, y2) + S(x1 - 1, y1 - 1) - S(x2, y1 - 1) - S(x1 - 1, y2)
    int ans;
    REP(i, 0, M) {
        ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        ans += S[x2][y2];
        if (x1 >= 2) ans -= S[x1 - 1][y2];
        if (y1 >= 2) ans -= S[x2][y1 - 1];
        if (x1 >= 2 && y1 >= 2) ans += S[x1 - 1][y1 - 1];
        cout << ans << endl;
    }

    return 0;
}