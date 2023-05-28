// 헤이카카오
// https://www.acmicpc.net/problem/22353

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

    int a, d, k;
    cin >> a >> d >> k;
    
    int n = 1;
    double p = d * 0.01;
    double dp = 1 + k * 0.01;
    double ans = 0;
    double prevP;
    bool coin = false;
    double failP = 1;
    vector<double> pv;
    for (int n = 1; p <= 1; n++) {
        if (n == 1) {
            ans += a * p;
        } else {
            failP = 1;
            for (int i = 0; i < pv.size(); i++) {
                failP *= 1 - pv[i];
            }
            ans += n * a * failP * p;
        }
        pv.push_back(p);
        p *= dp;        
        //cout << ans << " " << failP << " " << p << endl;
        if (coin) break;
        if (p >= 1) {
            p = 1;
            coin = true;
        }
    }
    cout << fixed;
    cout.precision(7);
    cout << ans << endl;

    return 0;
}