// 별 찍기 - 17
// https://www.acmicpc.net/problem/10992

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

    REP(i, 0, N - 1) {
        cout << " ";
    }
    cout << "*" << endl;

    REP(i, 1, N - 1) {
        REP(j, 1, N - i) {
            cout << " ";
        }
        cout << "*";
        REP(j, 0, 2 * i - 1) {
            cout << " ";
        }
        cout << "*" << endl;
    }
    if (N != 1) {
        REP(i, 0, 2 * N - 1) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}