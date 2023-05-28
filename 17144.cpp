// 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C, T;
    cin >> R >> C >> T;
    vvi map(R, vi(C));

    int down;  // 공기청정기 아래쪽의 row
    REP(i, 0, R) {
        REP(j, 0, C) {
            cin >> map[i][j];
            if (map[i][j] == -1) {
                down = i;
            }
        }
    }

    REP(t, 0, T) {
        vvi d_map(R, vi(C, 0));
        REP(i, 0, R) {
            REP(j, 0, C) {
                if (map[i][j] > 0) {
                    int div = map[i][j] / 5;
                    int cnt = 0;
                    if (i > 0 && !(i == down + 1 && j == 0)) {
                        d_map[i - 1][j] += div;
                        cnt++;
                    }
                    if (i < R - 1 && !(i == down - 2 && j == 0)) {
                        d_map[i + 1][j] += div;
                        cnt++;
                    }
                    if (j > 0 && !(i == down && j == 1) && !(i == down - 1 && j == 1)) {
                        d_map[i][j - 1] += div;
                        cnt++;
                    }
                    if (j < C - 1) {
                        d_map[i][j + 1] += div;
                        cnt++;
                    }
                    map[i][j] -= div * cnt;
                }
            }
        }
        REP(i, 0, R) {
            REP(j, 0, C) {
                map[i][j] += d_map[i][j];
            }
        }

        REP(i, 0, down - 2) {
            map[down - 2 - i][0] = map[down - 3 - i][0];
        }
        REP(j, 0, C - 1) {
            map[0][j] = map[0][j + 1];
        }
        REP(i, 0, down - 1) {
            map[i][C - 1] = map[i + 1][C - 1];
        }
        REP(j, 0, C - 2) {
            map[down - 1][C - 1 - j] = map[down - 1][C - 2 - j];
        }

        REP(i, down + 1, R - 1) {
            map[i][0] = map[i + 1][0];
        }
        REP(j, 0, C - 1) {
            map[R - 1][j] = map[R - 1][j + 1];
        }
        REP(i, down, R - 1) {
            map[down + R - 1 - i][C - 1] = map[down + R - 2 - i][C - 1];
        }
        REP(j, 0, C - 2) {
            map[down][C - 1 - j] = map[down][C - 2 - j];
        }

        map[down - 1][1] = 0;
        map[down][1] = 0;
        // cout << "T: " << t << endl;
        // REP(i, 0, R) {
        //     REP(j, 0, C) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    int ans = 0;
    REP(i, 0, R) {
        REP(j, 0, C) {
            if (map[i][j] > 0) {
                ans += map[i][j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}