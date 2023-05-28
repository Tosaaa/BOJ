// Sequence Conversion
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

    int N;
    cin >> N;
    vi av(N);
    vi bv(N);

    REP(i, 0, N) {
        cin >> av[i];
    }
    REP(i, 0, N) {
        cin >> bv[i];
    }

    int cnt = 0;
    REP(i, 0, N-1) {
        int tmp = av[i] ^ bv[i];
        if (tmp == 0) continue;
        av[i] = bv[i];
        av[i+1] = av[i+1] ^ tmp;
        cnt++;
    }

    if (av[N-1] == bv[N-1])
        cout << cnt << endl;
    else
        cout << -1 << endl;

    return 0;
}