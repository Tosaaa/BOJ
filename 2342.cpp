// Dance Dance Revolution
// https://www.acmicpc.net/problem/2342

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int cost(int a, int b) {
    if (a == 0) {
        return 2;
    } else if (b - a == 2 || b - a == -2) {
        return 4;
    } else {
        return 3;
    }
}

int solve(vector<vvi> &DP, vi &input, int cnt, int x, int y) {
    if (cnt == input.size()) return 0;

    if (DP[cnt][x][y] != -1) {
        DP[cnt][y][x] = DP[cnt][x][y];
        return DP[cnt][x][y];
    } else if (DP[cnt][y][x] != -1) {
        DP[cnt][x][y] = DP[cnt][y][x];
        return DP[cnt][y][x];
    }

    if (x == input[cnt] && y == input[cnt]) {
        cout << "wtf" << endl;
        exit(0);
    } else if (x == input[cnt] || y == input[cnt]) {
        DP[cnt][x][y] = solve(DP, input, cnt + 1, x, y) + 1;
    } else {
        DP[cnt][x][y] = min(solve(DP, input, cnt + 1, input[cnt], y) + cost(x, input[cnt]), solve(DP, input, cnt + 1, x, input[cnt]) + cost(y, input[cnt]));
    }
    return DP[cnt][x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char c;
    cin >> c;
    vi input;
    while (c != '0') {
        input.push_back(c - '0');
        cin >> c;
    }
    vector<vvi> DP(input.size(), vvi(5, vi(5, -1)));  // count, x, y
    cout << solve(DP, input, 0, 0, 0) << endl;

    // REP(i, 0, input.size()) {
    //     REP(j, 0, 5) {
    //         REP(k, 0, 5) {
    //             cout << "cnt, x, y, DP: " << i << " " << j << " " << k << " " << DP[i][j][k] << endl;
    //         }
    //     }
    //     cout << endl;
    // }

    return 0;
}