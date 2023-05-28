// 제로
// https://www.acmicpc.net/problem/10773

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

    int K;
    cin >> K;
    stack<int> st;
    REP(i, 0, K) {
        int in;
        cin >> in;
        if (in == 0 && !st.empty()) {
            st.pop();
        } else if (in != 0) {
            st.push(in);
        }
    }
    int ans = 0;
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << ans << endl;

    return 0;
}