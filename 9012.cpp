// 괄호
// https://www.acmicpc.net/problem/9012

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
    string in;
    REP(i, 0, N) {
        cin >> in;
        int st = 0;
        bool valid = true;
        REP(j, 0, in.size()) {
            if (in[j] == '(') {
                st++;
            } else {
                st--;
            }
            if (st < 0) {
                valid = false;
                break;
            }
        }
        if (st != 0) {
            valid = false;
        }
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}