// 듣보잡
// https://www.acmicpc.net/problem/1764

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
    int N, M;
    cin >> N >> M;
    set<string> DB;
    vector<string> ans;
    string in;
    REP(i, 0, N + M) { 
        cin >> in;
        if (DB.insert(in).second == false) {
            ans.push_back(in);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    REP(i, 0, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}