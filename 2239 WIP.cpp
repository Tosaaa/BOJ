// 스도쿠
// https://www.acmicpc.net/problem/2239

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

void find(vvi &map, vvi &visited_row, vvi &visited_col, vvi &visited_box, int x, int y) {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vvi map(9, vi(9));
    REP(i, 0, 9) {
        REP(j, 0, 9) {
            cin >> map[i][j];
        }
    }

    vvi visited_row(9, vi(10, 0));
    vvi visited_col(9, vi(10, 0));
    vvi visited_box(9, vi(10, 0));

    return 0;
}