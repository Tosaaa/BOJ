// 아름다운 문자열
// https://www.acmicpc.net/problem/24524
// 문자열 폭발과 비슷? XXXX

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

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

    string S;
    string T;
    cin >> S >> T;
    vi step(T.size(), 0);

    int ans = 0;
    REP(i, 0, S.size()) {
        int idx = T.find(S[i]);
        if (idx != string::npos) {
            if (idx == 0) {
                step[idx]++;
            } else if (step[idx-1] > 0) {
                step[idx-1]--;
                step[idx]++;
            }
        }
    }
    
    cout << step[T.size()-1] << endl;

    return 0;
}