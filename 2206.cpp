// 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206
// 어려움.. 처음엔 노드마다 각각의 visited를 갖고 있고, 큐에 노드를 넣고, while 밖의 min_depth를 이용해 breakable, !breakable에 대해 깊이가 최소가 아니면(전에 이미 방문 했으면) continue 하는 방식으로 했음.
// 위 방법은 while 자체는 O(NM) 걸리는데, visited를 복사하는게 O(NM) 걸려서, 총 O((NM)^2)이 걸림 => 시간 초과.
// 그래서 visited를 각 노드마다 갖지 말고, 모두 공유하는 변형된 visited를 만들어서 체크함.

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

int bfs(vector<vector<int>> &pos, int N, int M) {
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2, 0)));  // {부신 적 O, 부신 적 X}
    queue<tuple<int, int, int, int>> q;
    int ans = -1;
    q.push({0, 0, 1, 1});
    int cnt = 0;
    while (!q.empty()) {
        int x, y, depth;
        int breakable;
        tie(x, y, depth, breakable) = q.front();
        q.pop();

        if (visited[x][y][breakable]) continue;
        visited[x][y][breakable] = 1;
        // cout << x << " " << y << " " << depth << " " << breakable << endl;
        if (x == N - 1 && y == M - 1) {
            ans = depth;
            break;
        }
        
        cnt++;
        // cout << x << " " << y << " " << depth << " " << breakable << endl;

        if (x > 0) {
            if (!pos[x - 1][y] && !visited[x - 1][y][breakable])
                q.push(make_tuple(x - 1, y, depth + 1, breakable));
            else if (pos[x - 1][y] && !visited[x - 1][y][!breakable] && breakable) {
                q.push(make_tuple(x - 1, y, depth + 1, !breakable));
            }
        }
        if (y > 0) {
            if (!pos[x][y - 1] && !visited[x][y - 1][breakable])
                q.push(make_tuple(x, y - 1, depth + 1, breakable));
            else if (pos[x][y - 1] && !visited[x][y - 1][!breakable] && breakable) {
                q.push(make_tuple(x, y - 1, depth + 1, !breakable));
            }
        }
        if (x < N - 1) {
            if (!pos[x + 1][y] && !visited[x + 1][y][breakable])
                q.push(make_tuple(x + 1, y, depth + 1, breakable));
            else if (pos[x + 1][y] && !visited[x + 1][y][!breakable] && breakable) {
                q.push(make_tuple(x + 1, y, depth + 1, !breakable));
            }
        }
        if (y < M - 1) {
            if (!pos[x][y + 1] && !visited[x][y + 1][breakable])
                q.push(make_tuple(x, y + 1, depth + 1, breakable));
            else if (pos[x][y + 1] && !visited[x][y + 1][!breakable] && breakable) {
                q.push(make_tuple(x, y + 1, depth + 1, !breakable));
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

    cout << bfs(pos, N, M) << endl;

    // REP(i, 0, N) {
    //     REP(j, 0, M) {
    //         cout << pos[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}