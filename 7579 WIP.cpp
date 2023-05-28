// 앱
// https://www.acmicpc.net/problem/7579

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

bool cmp(pii a, pii b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<pii> info(N + 1);
    info[0] = {0, 0};
    REP(i, 1, N + 1) {
        cin >> info[i].first;
    }
    REP(i, 1, N + 1) {
        cin >> info[i].second;
    }

    sort(info.begin() + 1, info.end(), cmp);

    vi DP(M + 1, 10000000);

    //~~~~ 1차원으로 해보려고 발악함

    cout << DP[M] << endl;

    return 0;
}