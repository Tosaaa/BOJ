// B
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
    cout << fixed;
    cout.precision(6);

    vector<float> p(10);
    REP(i, 0, 10) {
        cin >> p[i];
    }
    sort (p.begin(), p.end());

    float ans = 1;
    REP(i, 1, 10) {
        ans *= p[i] / i;
    }

    cout << ans * pow(10, 9) << endl;

    return 0;
}