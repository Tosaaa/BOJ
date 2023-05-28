// 나누기
// https://www.acmicpc.net/problem/1075

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

    int N, F;
    cin >> N >> F;
    N = (N / 100) * 100;

    int ans;
    REP(i, 0, 100) {
        if ((N + i) % F == 0) {
            ans = i;
            break;
        }
    }

    if (ans < 10) {
        cout << "0" << ans << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}