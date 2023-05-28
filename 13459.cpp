// 구슬 탈출
// https://www.acmicpc.net/problem/13459

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int N, M;

pair<vvc, int> leanLeft(vvc map) {
    bool isRed = false;
    bool isBlue = false;
    REP(x, 1, N - 1) {
        REP(y, 1, M - 1) {
            if (map[x][y] == 'R' || map[x][y] == 'B') {
                char ball = map[x][y];
                RREP(i, y, 0) {
                    if (map[x][i] == '#' || map[x][i] == 'R' || map[x][i] == 'B') {
                        char tmp = map[x][i + 1];
                        map[x][i + 1] = ball;
                        map[x][y] = tmp;
                        break;
                    } else if (map[x][i] == 'O') {
                        map[x][y] = '.';
                        if (ball == 'R') {
                            isRed = true;
                        } else {
                            isBlue = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    // 0: nothing, 1: success, -1: failed
    if (isBlue) return {map, -1};
    if (isRed) return {map, 1};
    return {map, 0};
}

pair<vvc, int> leanRight(vvc map) {
    bool isRed = false;
    bool isBlue = false;
    REP(x, 1, N - 1) {
        RREP(y, M - 1, 1) {
            if (map[x][y] == 'R' || map[x][y] == 'B') {
                char ball = map[x][y];
                REP(i, y + 1, M) {
                    if (map[x][i] == '#' || map[x][i] == 'R' || map[x][i] == 'B') {
                        char tmp = map[x][i - 1];
                        map[x][i - 1] = ball;
                        map[x][y] = tmp;
                        break;
                    } else if (map[x][i] == 'O') {
                        map[x][y] = '.';
                        if (ball == 'R') {
                            isRed = true;
                        } else {
                            isBlue = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    // 0: nothing, 1: success, -1: failed
    if (isBlue) return {map, -1};
    if (isRed) return {map, 1};
    return {map, 0};
}

pair<vvc, int> leanUp(vvc map) {
    bool isRed = false;
    bool isBlue = false;
    REP(y, 1, M - 1) {
        REP(x, 1, N - 1) {
            if (map[x][y] == 'R' || map[x][y] == 'B') {
                char ball = map[x][y];
                RREP(i, x, 0) {
                    if (map[i][y] == '#' || map[i][y] == 'R' || map[i][y] == 'B') {
                        char tmp = map[i + 1][y];
                        map[i + 1][y] = ball;
                        map[x][y] = tmp;
                        break;
                    } else if (map[i][y] == 'O') {
                        map[x][y] = '.';
                        if (ball == 'R') {
                            isRed = true;
                        } else {
                            isBlue = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    // 0: nothing, 1: success, -1: failed
    if (isBlue) return {map, -1};
    if (isRed) return {map, 1};
    return {map, 0};
}

pair<vvc, int> leanDown(vvc map) {
    bool isRed = false;
    bool isBlue = false;
    REP(y, 1, M - 1) {
        RREP(x, N - 1, 1) {
            if (map[x][y] == 'R' || map[x][y] == 'B') {
                char ball = map[x][y];
                REP(i, x + 1, N) {
                    if (map[i][y] == '#' || map[i][y] == 'R' || map[i][y] == 'B') {
                        char tmp = map[i - 1][y];
                        map[i - 1][y] = ball;
                        map[x][y] = tmp;
                        break;
                    } else if (map[i][y] == 'O') {
                        map[x][y] = '.';
                        if (ball == 'R') {
                            isRed = true;
                        } else {
                            isBlue = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    // 0: nothing, 1: success, -1: failed
    if (isBlue) return {map, -1};
    if (isRed) return {map, 1};
    return {map, 0};
}

int escape(vvc map) {
    queue<pair<pair<vvc, int>, pii>> q;  // map, success?, depth, prev (prev, 0: up-down, 1: left-right)
    q.push({{map, 0}, {0, 0}});
    q.push({{map, 0}, {0, 1}});

    int ans = 0;
    while (!q.empty()) {
        pair<vvc, int> m = q.front().first;
        int depth = q.front().second.first;
        int prev = q.front().second.second;
        q.pop();
        // cout << "m.second: " << m.second << endl;
        if (m.second == -1 || depth > 10)
            continue;
        else if (m.second == 1) {
            ans = 1;
            break;
        }
        if (prev == 0) {
            q.push({leanLeft(m.first), {depth + 1, 1}});
            q.push({leanRight(m.first), {depth + 1, 1}});
        } else {
            q.push({leanUp(m.first), {depth + 1, 0}});
            q.push({leanDown(m.first), {depth + 1, 0}});
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vvc map(N, vector<char>(M));
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> map[i][j];
        }
    }

    int ans = escape(map);
    cout << ans << endl;

    // cout << endl;
    // REP(i, 0, N) {
    //     REP(j, 0, M) {
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}