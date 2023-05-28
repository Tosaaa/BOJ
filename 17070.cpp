// 파이프 옮기기 1
// https://www.acmicpc.net/problem/17070

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

int N;

int movePipe(vvi &map, vector<vvi> &memo, int x, int y, int state) {  // state: 0 horizontal, 1 vertical, 2 diagonal
    if (memo[x][y][state] != -1) {
        return memo[x][y][state];
    }

    if (x == N - 2 && y == N - 2 && state == 2) {
        memo[x][y][state] = 1;
        return 1;
    } else if (x == N - 1 && y == N - 2 && state == 0) {
        memo[x][y][state] = 1;
        return 1;
    } else if (x == N - 2 && y == N - 1 && state == 1) {
        memo[x][y][state] = 1;
        return 1;
    }
    
    memo[x][y][state] = 0;
    if (state == 0) {
        if (y < N - 2 && map[x][y + 2] == 0) {
            memo[x][y][state] += movePipe(map, memo, x, y + 1, 0);
        }
        if (x < N - 1 && y < N - 2 && map[x][y + 2] == 0 && map[x + 1][y + 1] == 0 && map[x + 1][y + 2] == 0) {
            memo[x][y][state] += movePipe(map, memo, x, y + 1, 2);
        }
    } else if (state == 1) {
        if (x < N - 2 && map[x + 2][y] == 0) {
            memo[x][y][state] += movePipe(map, memo, x + 1, y, 1);
        }
        if (x < N - 2 && y < N - 1 && map[x + 2][y] == 0 && map[x + 1][y + 1] == 0 && map[x + 2][y + 1] == 0) {
            memo[x][y][state] += movePipe(map, memo, x + 1, y, 2);
        }
    } else {
        if (x < N - 1 && y < N - 2 && map[x + 1][y + 2] == 0) {
            memo[x][y][state] += movePipe(map, memo, x + 1, y + 1, 0);
        }
        if (x < N - 2 && y < N - 1 && map[x + 2][y + 1] == 0) {
            memo[x][y][state] += movePipe(map, memo, x + 1, y + 1, 1);
        }
        if (x < N - 2 && y < N - 2 && map[x + 1][y + 2] == 0 && map[x + 2][y + 1] == 0 && map[x + 2][y + 2] == 0) {
            memo[x][y][state] += movePipe(map, memo, x + 1, y + 1, 2);
        }
    }

    return memo[x][y][state];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vvi map(N, vi(N));
    vector<vvi> memo(N, vvi(N, vi(3, -1)));
    REP(i, 0, N) {
        REP(j, 0, N) {
            cin >> map[i][j];
        }
    }

    cout << movePipe(map, memo, 0, 0, 0) << endl;

    // REP(i, 0, N) {
    //     REP(j, 0, N) {
    //         REP(k, 0, 3) {
    //             if (memo[i][j][k] == -1)
    //                 cout << "-";
    //             else
    //                 cout << memo[i][j][k];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}