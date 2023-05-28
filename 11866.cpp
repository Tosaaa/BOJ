// 요세푸스 문제 0
// https://www.acmicpc.net/problem/11866

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

    int N, K;
    cin >> N >> K;
    queue<int> q;
    vi ans;
    REP(i, 1, N+1) {
        q.push(i);
    }
    int tmp;
    while (!q.empty()) {
        REP(i, 0, K-1) {
            q.push(q.front());
            q.pop();
        }
        ans.push_back(q.front());
        q.pop();
    }

    cout << "<";
    REP(i, 0, N-1) {
        cout << ans[i] << ", ";
    }
    cout << ans[N-1] << ">" << endl;

    return 0;
}