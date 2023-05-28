// 균형잡힌 세상
// https://www.acmicpc.net/problem/4949

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


    while(1) {
        string in;
        getline(cin, in);
        if (in == ".") break;
        stack<char> st;
        bool valid = true;
        REP(j, 0, in.size()) {
            if (in[j] == '(' || in[j] == '[') {
                st.push(in[j]);
            } else if (in[j] == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else {
                    valid = false;
                    break;
                }
            } else if (in[j] == ']') {
                if (!st.empty() && st.top() == '[') st.pop();
                else {
                    valid = false;
                    break;
                }
            } 
        }
        if (!st.empty()) {
            valid = false;
        }
        if (valid) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}