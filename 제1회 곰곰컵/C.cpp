// C번 - 곰곰이의 식단 관리
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
    string input;
    cin >> N >> input;

    int chicken = 0;
    int other = 0;
    REP(i, 0, input.size()) {
        if (input[i] == 'C')
            chicken++;
        else
            other++;
    }

    int Q = chicken / (other + 1);
    int R = chicken % (other + 1);

    int ans;
    if (R)
        ans = Q + 1;
    else
        ans = Q;

    cout << ans << endl;

    return 0;
}