// 후위 표기식
// https://www.acmicpc.net/problem/1918

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

bool prior(pair<char, int> a, pair<char, int> b) {  // true if priority of a <= b
    if (a.second == b.second) {
        if (a.first == '*' || a.first == '/') {
            if (b.first == '*' || b.first == '/')
                return true;
            else
                return false;
        } else {
            return true;
        }
    } else if (a.second > b.second) {
        return false;
    } else {
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    cin >> input;
    int len = input.size();
    stack<pair<char, int>> s;
    int depth = 0;
    REP(i, 0, len) {
        if (input[i] >= 'A' && input[i] <= 'Z')
            cout << input[i];
        else if (input[i] == '(') {
            depth++;
        } else if (input[i] == ')') {
            depth--;
        } else {
            if (s.empty()) {
                s.push({input[i], depth});
            } else if (prior({input[i], depth}, s.top())) {
                while (!s.empty() && prior({input[i], depth}, s.top())) {
                    cout << s.top().first;
                    s.pop();
                }
                s.push({input[i], depth});
            } else {
                s.push({input[i], depth});
            }
        }
    }
    while (!s.empty()) {
        cout << s.top().first;
        s.pop();
    }
    cout << endl;
    return 0;
}