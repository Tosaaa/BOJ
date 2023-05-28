// SKK 문자열
// https://www.acmicpc.net/problem/24525

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;
    vi arr(S.size() + 1, 0);
    REP(i, 0, S.size()) {
        if (S[i] == 'S')
            arr[i + 1] = -2;
        else if (S[i] == 'K')
            arr[i + 1] = 1;
    }
    vector<tuple<int, int, int, int>> sum(S.size() + 1, {0, 0, 0, 0});
    REP(i, 0, S.size()) {
        int val, idx, s, k;
        tie(val, idx, s, k) = sum[i];
        if (arr[i + 1] == -2)
            s++;
        else if (arr[i + 1] == 1) {
            k++;
        }
        sum[i + 1] = {val + arr[i + 1], i + 1, s, k};
    }

    // REP(i, 0, S.size() + 1) {
    //     int a, b, c, d;
    //     tie(a, b, c, d) = sum[i];
    //     cout << a << " " << b << " " << c << " " << d << endl;
    // }

    map<int, tuple<int, int, int>> s;
    int ans = -1;
    REP(i, 0, S.size() + 1) {
        int a, b, c, d;
        tie(a, b, c, d) = sum[i];
        // auto it = find_if(s.begin(), s.end(), [tmp](const tuple<int, int, int, int>& p) { return get<0>(p) == tmp; });
        auto it = s.find(a);
        if (it == s.end()) {
            s.insert({a, {b, c, d}});
        } else {
            int val, idx, s, k;
            val = (*it).first;
            tie(idx, s, k) = (*it).second;
            int val2, idx2, s2, k2;
            tie(val2, idx2, s2, k2) = sum[i];
            if (s2 - s > 0 || k2 - k > 0) {
                ans = max(ans, idx2 - idx);
            }
        }
    }

    cout << ans << endl;

    return 0;
}