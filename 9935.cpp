// 문자열 폭발
// https://www.acmicpc.net/problem/9935

#include <algorithm>
#include <iostream>
#include <stack>
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

    string str, bomb;
    cin >> str >> bomb;

    stack<pair<int, int>> s;  // str에서 idx, bomb에서 idx
    int idx = 0;
    vector<int> valid(str.size(), 1);
    REP(i, 0, str.size()) {
        if (str[i] == bomb[idx]) {
            s.push({i, idx++});
        } else if (str[i] == bomb[0]) {
            idx = 0;
            s.push({i, idx++});
        } else {
            while (!s.empty()) s.pop();
            idx = 0;
        }
        if (idx == bomb.size()) {
            REP(i, 0, bomb.size()) {
                valid[s.top().first] = 0;
                s.pop();
            }
            if (!s.empty()) {
                idx = s.top().second + 1;
            } else {
                idx = 0;
            }
        }
    }

    bool left = false;
    REP(i, 0, str.size()) {
        if (valid[i]) {
            left = true;
            break;
        }
    }

    if (left) {
        REP(i, 0, str.size()) {
            if (valid[i]) cout << str[i];
        }
        cout << endl;
    } else {
        cout << "FRULA" << endl;
    }

    return 0;
}