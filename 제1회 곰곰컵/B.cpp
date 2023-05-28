// B번 - 인사성 밝은 곰곰이
// https://www.acmicpc.net/problem/

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
    set<string> names;
    int ans = 0;
    REP(i, 0, N) {
        string input;
        cin >> input;
        if (input == "ENTER") {
            names.clear();
        }
        else {
            if (names.insert(input).second) { // inserted
                ans++;
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}