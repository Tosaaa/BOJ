// 체스판 조각
// https://www.acmicpc.net/problem/3004

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int gap = 1;
    int ans = 1;
    REP(i, 1, N+1) {
        if (i % 2 == 1) {
            ans += gap;
        } else {
            gap++;
            ans += gap;
        }
    }
    cout << ans << endl;

    return 0;
}