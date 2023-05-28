// 피보나치 함수
// https://www.acmicpc.net/problem/1003

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

    int T;
    cin >> T;
    REP(tc, 0, T) {
        int N;
        cin >> N;
        vector<pii> dp(N + 1, {0, 0});
        dp[0].first = 1;
        dp[1].second = 1;
        REP(i, 2, N + 1) {
            dp[i].first = dp[i - 1].first + dp[i - 2].first;
            dp[i].second = dp[i - 1].second + dp[i - 2].second;
        }

        cout << dp[N].first << " " << dp[N].second << endl;
    }

    return 0;
}