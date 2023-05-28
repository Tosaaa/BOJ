// 가장 긴 증가하는 부분 수열 3
// https://www.acmicpc.net/problem/12738

#include <algorithm>
#include <iostream>
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

    int N;
    cin >> N;

    vi v;
    int ans = 0;
    int a;
    REP(i, 0, N) {
        cin >> a;
        if (v.empty()) {
            v.push_back(a);
            ans++;
        } else if (v.back() < a) {
            v.push_back(a);
            ans++;
        } else {
            auto it = lower_bound(v.begin(), v.end(), a);
            (*it) = a;
        }
    }

    cout << ans << endl;

    return 0;
}