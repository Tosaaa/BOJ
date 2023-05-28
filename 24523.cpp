// 내 뒤에 나와 다른 수
// https://www.acmicpc.net/problem/24523

#include <algorithm>
#include <iostream>
#include <queue>
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
    queue<int> q;
    int input;
    REP(i, 0, N) {
        cin >> input;
        if (q.empty()) {
            q.push(input);
        } else if (q.front() != input) {
            while (!q.empty()) {
                cout << i + 1 << " ";
                q.pop();
            }
            q.push(input);
        } else {
            q.push(input);
        }
    }
    while (!q.empty()) {
        cout << "-1 ";
        q.pop();
    }
    cout << endl;

    return 0;
}