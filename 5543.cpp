// 상근날드
// https://www.acmicpc.net/problem/5543

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

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << min(min(a, b), c) + min(d, e) - 50 << endl;

    return 0;
}