// 스택
// https://www.acmicpc.net/problem/10828

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
    cin >> N;
    string input;
    int val;
    stack<int> st;
    REP(i, 0, N) {
        cin >> input;
        if (input == "push") {
            cin >> val;
            st.push(val);
        } else if (input == "top") {
            if (st.empty()) {
                cout << -1 << endl;
            } else {
                cout << st.top() << endl;
            }
        } else if (input == "size") {
            cout << st.size() << endl;
        } else if (input == "empty") {
            cout << st.empty() << endl;
        } else if (input == "pop") {
            if (st.empty()) {
                cout << -1 << endl;
            } else {
                cout << st.top() << endl;
                st.pop();
            }
        }
    }

    return 0;
}