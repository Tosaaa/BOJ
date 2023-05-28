// 치즈
// https://www.acmicpc.net/problem/2638

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

int N, M;

void DFS_Util(vvi &pos, int x, int y, vvi &visited, vector<vvi> &marker);

bool DFS(vvi &pos, int x, int y, vector<vvi> &marker) {
    vvi visited(N, vi(M, 0));
    DFS_Util(pos, x, y, visited, marker);
    bool valid = false;
    REP(i, 0, N) {
        REP(j, 0, M) {
            int cnt = 0;
            REP(k, 0, 4) {
                if (marker[i][j][k]) {
                    marker[i][j][k] = 0;
                    cnt++;
                }
            }
            if (cnt >= 2) {
                pos[i][j] = 0;
                valid = true;
            }
        }
    }
    return valid;
}

void DFS_Util(vvi &pos, int x, int y, vvi &visited, vector<vvi> &marker) {
    visited[x][y] = 1;

    if (x > 0) {
        if (!pos[x - 1][y] && !visited[x - 1][y]) {
            DFS_Util(pos, x - 1, y, visited, marker);
        } else if (pos[x - 1][y]) {
            marker[x - 1][y][2] = 1;
        }
    }
    if (x < N - 1) {
        if (!pos[x + 1][y] && !visited[x + 1][y]) {
            DFS_Util(pos, x + 1, y, visited, marker);
        } else if (pos[x + 1][y]) {
            marker[x + 1][y][0] = 1;
        }
    }
    if (y > 0) {
        if (!pos[x][y - 1] && !visited[x][y - 1]) {
            DFS_Util(pos, x, y - 1, visited, marker);
        } else if (pos[x][y - 1]) {
            marker[x][y - 1][1] = 1;
        }
    }
    if (y < M - 1) {
        if (!pos[x][y + 1] && !visited[x][y + 1]) {
            DFS_Util(pos, x, y + 1, visited, marker);
        } else if (pos[x][y + 1]) {
            marker[x][y + 1][3] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vvi pos(N, vi(M));
    vector<vvi> marker(N, vvi(M, vi(4, 0)));  // 0 up, 1 right, 2 down, 3 left
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> pos[i][j];
        }
    }

    int ans = 0;
    while (DFS(pos, 0, 0, marker)) ans++;

    cout << ans << endl;

    return 0;
}