// 주사위 세개
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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << 10000 + a * 1000 << endl;
    } else if (a != b && b != c && c != a) {
        cout << max(max(a, b), c) * 100 << endl;
    } else {
        if (a == b) {
            cout << 1000 + a * 100 << endl;
        } else if (b == c) {
            cout << 1000 + b * 100 << endl;
        } else {
            cout << 1000 + c * 100 << endl;
        }
    }

    return 0;
}