// 알파벳
// https://www.acmicpc.net/problem/1987

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int R, C;

int DFS(vvi &map, int x, int y, vvi &visited, vi &alphabets, int depth) {
    alphabets[map[x][y]] = 1;
    visited[x][y] = 1;
    //cout << x << " " << y << " " << (char)(map[x][y] + 'A') << endl;

    int ret = depth;
    if (x > 0 && !visited[x - 1][y] && !alphabets[map[x - 1][y]]) {
        ret = max(ret, DFS(map, x - 1, y, visited, alphabets, depth + 1));
    }
    if (y > 0 && !visited[x][y - 1] && !alphabets[map[x][y - 1]]) {
        ret = max(ret, DFS(map, x, y - 1, visited, alphabets, depth + 1));
    }
    if (x < R - 1 && !visited[x + 1][y] && !alphabets[map[x + 1][y]]) {
        ret = max(ret, DFS(map, x + 1, y, visited, alphabets, depth + 1));
    }
    if (y < C - 1 && !visited[x][y + 1] && !alphabets[map[x][y + 1]]) {
        ret = max(ret, DFS(map, x, y + 1, visited, alphabets, depth + 1));
    }
    visited[x][y] = 0;
    alphabets[map[x][y]] = 0;
    //cout << x << " " << y << " Ended" << endl;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    vvi map(R, vi(C));
    REP(i, 0, R) {
        REP(j, 0, C) {
            char c;
            cin >> c;
            map[i][j] = c - 'A';
        }
    }

    vvi visited(R, vi(C, 0));
    vi alphabets(26, 0);
    cout << DFS(map, 0, 0, visited, alphabets, 1) << endl;

    return 0;
}