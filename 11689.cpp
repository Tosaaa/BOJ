// GCD(n, k) = 1
// https://www.acmicpc.net/problem/11689

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

    ll N;
    cin >> N;

    vector<ll> p_arr;
    ll sqrtN = (ll)sqrt(N);
    ll tmpN = N;
    REP(i, 2, sqrtN + 1) {
        if (tmpN % i == 0) {
            p_arr.push_back(i);
            while (tmpN % i == 0) {
                tmpN /= i;
            }
        }
    }
    if (tmpN != 1) p_arr.push_back(tmpN);

    // REP(i, 0, p_arr.size()) {
    //     cout << p_arr[i] << endl;
    // }

    ll ans = 1;
    double ans_double = N;
    REP(i, 0, p_arr.size()) {
        ans_double *= (1 - 1/(double)p_arr[i]);
        //cout << ans_double << endl;
    }
    ans = (ll)ans_double;
    cout << ans << endl;

    return 0;
}