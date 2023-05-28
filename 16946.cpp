// 벽 부수고 이동하기 4
// https://www.acmicpc.net/problem/16946

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF INT_MAX
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

vector<vector<pii>> bfs(vvi &pos, int N, int M) {
    vvi visited(N, vi(M, 0));
    vector<vector<pii>> ret(N, vector<pii>(M, {0, 0}));
    int idx = 1;
    REP(i, 0, N) {
        REP(j, 0, M) {
            if (!visited[i][j] && pos[i][j] == 0) {
                queue<pii> q;
                vector<pii> reached;
                q.push({i, j});
                int cnt = 0;
                while (!q.empty()) {
                    int x, y;
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();

                    if (visited[x][y]) continue;
                    visited[x][y] = 1;
                    cnt++;
                    reached.push_back({x, y});

                    if (x > 0 && !pos[x - 1][y] && !visited[x - 1][y]) {
                        q.push({x - 1, y});
                    }
                    if (y > 0 && !pos[x][y - 1] && !visited[x][y - 1]) {
                        q.push({x, y - 1});
                    }
                    if (x < N - 1 && !pos[x + 1][y] && !visited[x + 1][y]) {
                        q.push({x + 1, y});
                    }
                    if (y < M - 1 && !pos[x][y + 1] && !visited[x][y + 1]) {
                        q.push({x, y + 1});
                    }
                }
                REP(i, 0, cnt) {
                    int a, b;
                    a = reached[i].first;
                    b = reached[i].second;
                    ret[a][b].first = cnt;
                    ret[a][b].second = idx;
                }
                idx++;
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> pos(N, vector<int>(M, 0));

    char c;
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> c;
            pos[i][j] = c - '0';
        }
    }

    vector<vector<pii>> dp = bfs(pos, N, M);

    // REP(i, 0, N) {
    //     REP(j, 0, M) {
    //         cout << dp[i][j].first << "(" << dp[i][j].second << ")";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    vvi ans(N, vi(M, 0));
    REP(x, 0, N) {
        REP(y, 0, M) {
            if (pos[x][y] == 1) {
                int a = -1, b = -1, c = -1, d = -1;
                if (x > 0) {
                    int tmp = dp[x - 1][y].second;
                    if (tmp != a && tmp != b && tmp != c && tmp != d) {
                        ans[x][y] += dp[x - 1][y].first;
                        a = tmp;
                    }
                }
                if (y > 0) {
                    int tmp = dp[x][y - 1].second;
                    if (tmp != a && tmp != b && tmp != c && tmp != d) {
                        ans[x][y] += dp[x][y - 1].first;
                        b = tmp;
                    }
                }
                if (x < N - 1) {
                    int tmp = dp[x + 1][y].second;
                    if (tmp != a && tmp != b && tmp != c && tmp != d) {
                        ans[x][y] += dp[x + 1][y].first;
                        c = tmp;
                    }
                }
                if (y < M - 1) {
                    int tmp = dp[x][y + 1].second;
                    if (tmp != a && tmp != b && tmp != c && tmp != d) {
                        ans[x][y] += dp[x][y + 1].first;
                        d = tmp;
                    }
                }
                ans[x][y]++;
                ans[x][y] %= 10;
            }
        }
    }

    REP(i, 0, N) {
        REP(j, 0, M) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}