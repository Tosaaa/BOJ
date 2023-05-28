// 덱
// https://www.acmicpc.net/problem/10866

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
    deque<int> dq;
    REP(i, 0, N) {
        cin >> input;
        if (input == "push_front") {
            cin >> val;
            dq.push_front(val);
        } else if (input == "push_back") {
            cin >> val;
            dq.push_back(val);
        } else if (input == "front") {
            if (dq.empty()) {
                    cout << -1 << endl;
                }
            else {
                cout << dq.front() << endl;
            }
        } else if (input == "back") {
            if (dq.empty()) {
                    cout << -1 << endl;
                }
            else {
                cout << dq.back() << endl;
            }
        } else if (input == "size") {
            cout << dq.size() << endl;
        } else if (input == "empty") {
            cout << dq.empty() << endl;
        } else if (input == "pop_front") {
            if (dq.empty()) {
                    cout << -1 << endl;
                }
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        } else if (input == "pop_back") {
            if (dq.empty()) {
                    cout << -1 << endl;
                }
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
    }

    return 0;
}