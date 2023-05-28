// A
// https://www.acmicpc.net/problem/

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
    int N, X;
    cin >> N >> X;
    vi limit(N);
    REP(i, 0, N) {
        cin >> limit[i];
    }

    int idx = 0;
    while (limit[idx] >= X) {
        X++;
        idx++;
        idx %= N;
    }

    cout << idx + 1 << endl;

    return 0;
}