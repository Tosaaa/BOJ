// 항체 인식
// https://www.acmicpc.net/problem/22352

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

void DFS(vvi &prev, vvi &visited, int x, int y, int val, int N, int M) {
    visited[x][y] = 1;
    int prevVal = prev[x][y];
    prev[x][y] = val;

    if (x > 0 && !visited[x - 1][y] && prevVal == prev[x - 1][y]) {
        DFS(prev, visited, x - 1, y, val, N, M);
    }
    if (y > 0 && !visited[x][y - 1] && prevVal == prev[x][y - 1]) {
        DFS(prev, visited, x, y - 1, val, N, M);
    }
    if (x < N - 1 && !visited[x + 1][y] && prevVal == prev[x + 1][y]) {
        DFS(prev, visited, x + 1, y, val, N, M);
    }
    if (y < M - 1 && !visited[x][y + 1] && prevVal == prev[x][y + 1]) {
        DFS(prev, visited, x, y + 1, val, N, M);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vvi prev(N, vi(M));
    vvi now(N, vi(M));
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> prev[i][j];
        }
    }
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> now[i][j];
        }
    }

    bool same = true;
    int x, y, val;
    REP(i, 0, N) {
        REP(j, 0, M) {
            if (prev[i][j] != now[i][j]) {
                x = i;
                y = j;
                val = now[i][j];
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        cout << "YES" << endl;
    } else {
        vvi visited(N, vi(M, 0));
        DFS(prev, visited, x, y, val, N, M);
        same = true;
        REP(i, 0, N) {
            REP(j, 0, M) {
                if (prev[i][j] != now[i][j]) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }
        if (same)
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            // REP(i, 0, N) {
            //     REP(j, 0, M) {
            //         cout << prev[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
    }

    return 0;
}