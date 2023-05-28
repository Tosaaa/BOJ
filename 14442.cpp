// 벽 부수고 이동하기 2
// https://www.acmicpc.net/problem/2206

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <utility>

#define INF INT_MAX
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int bfs(vector<vector<int>> &pos, int N, int M, int K) {
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(K + 1, 0)));  // {0번 부심, 1번 부심, ... K-1번 부심, K번 부심}
    queue<tuple<int, int, int, int>> q;
    int ans = -1;
    q.push({0, 0, 1, 0});
    int cnt = 0;
    while (!q.empty()) {
        int x, y, depth, breakCnt;
        tie(x, y, depth, breakCnt) = q.front();
        q.pop();

        if (visited[x][y][breakCnt]) continue;
        visited[x][y][breakCnt] = 1;
        // cout << x << " " << y << " " << depth << " " << breakCnt << endl;
        if (x == N - 1 && y == M - 1) {
            ans = depth;
            break;
        }

        cnt++;
        // cout << x << " " << y << " " << depth << " " << breakCnt << endl;

        if (x > 0) {
            if (!pos[x - 1][y] && !visited[x - 1][y][breakCnt])
                q.push(make_tuple(x - 1, y, depth + 1, breakCnt));
            else if (pos[x - 1][y] && breakCnt < K && !visited[x - 1][y][breakCnt + 1]) {
                q.push(make_tuple(x - 1, y, depth + 1, breakCnt + 1));
            }
        }
        if (y > 0) {
            if (!pos[x][y - 1] && !visited[x][y - 1][breakCnt])
                q.push(make_tuple(x, y - 1, depth + 1, breakCnt));
            else if (pos[x][y - 1] && breakCnt < K && !visited[x][y - 1][breakCnt + 1]) {
                q.push(make_tuple(x, y - 1, depth + 1, breakCnt + 1));
            }
        }
        if (x < N - 1) {
            if (!pos[x + 1][y] && !visited[x + 1][y][breakCnt])
                q.push(make_tuple(x + 1, y, depth + 1, breakCnt));
            else if (pos[x + 1][y] && breakCnt < K && !visited[x + 1][y][breakCnt + 1]) {
                q.push(make_tuple(x + 1, y, depth + 1, breakCnt + 1));
            }
        }
        if (y < M - 1) {
            if (!pos[x][y + 1] && !visited[x][y + 1][breakCnt])
                q.push(make_tuple(x, y + 1, depth + 1, breakCnt));
            else if (pos[x][y + 1] && breakCnt < K && !visited[x][y + 1][breakCnt + 1]) {
                q.push(make_tuple(x, y + 1, depth + 1, breakCnt + 1));
            }
        }
    }
    // cout << cnt << endl;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> pos(N, vector<int>(M, 0));

    char c;
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> c;
            pos[i][j] = c - '0';
        }
    }

    cout << bfs(pos, N, M, K) << endl;

    // REP(i, 0, N) {
    //     REP(j, 0, M) {
    //         cout << pos[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}