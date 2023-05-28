// 별 찍기 - 16
// https://www.acmicpc.net/problem/10991

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

    REP(i, 0, N) {
        REP(j, 0, N - i - 1) {
            cout << " ";
        }
        REP(j, 0, i+1) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}