// 용액
// https://www.acmicpc.net/problem/2467

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
#define INF INT_MAX

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vi neg;
    vi pos;
    int a;
    REP(i, 0, N) {
        cin >> a;
        a < 0 ? neg.push_back(a) : pos.push_back(a);
    }

    int l = neg.size() - 1;
    int r = 0;
    int neg_size = neg.size();
    int pos_size = pos.size();
    int m1 = INF, m2 = INF, m3 = INF;
    pii ans1, ans2, ans3;
    if (neg_size >= 2) {
        m1 = neg[l] + neg[l - 1];
        ans1 = {neg[l - 1], neg[l]};
    }
    if (pos_size >= 2) {
        m2 = pos[r] + pos[r + 1];
        ans2 = {pos[r], pos[r + 1]};
    }

    while (l >= 0 && r <= pos_size - 1) {
        // cout << "l, r: " << l << " " << r << endl;
        int s = neg[l] + pos[r];
        if (s == 0) {
            m3 = 0;
            ans3 = {neg[l], pos[r]};
            break;
        }
        if (abs(m3) > abs(s)) {
            m3 = s;
            ans3 = {neg[l], pos[r]};
        }
        s > 0 ? l-- : r++;
    }

    pii ans;
    if (abs(m1) > abs(m2)) {
        if (abs(m2) > abs(m3)) {
            ans = ans3;
            // cout << 1 << endl;
        } else {
            ans = ans2;
            // cout << 2 << endl;
        }
    } else {
        if (abs(m1) > abs(m3)) {
            ans = ans3;
            // cout << 3 << endl;
        } else {
            ans = ans1;
            // cout << 4 << endl;
        }
    }
    cout << ans.first << " " << ans.second << endl;

    return 0;
}