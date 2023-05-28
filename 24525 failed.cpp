// SKK 문자열
// https://www.acmicpc.net/problem/24525
// O(N^2) 시간초과남.

#include <algorithm>
#include <iostream>
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

    string S;
    cin >> S;
    vi arr(S.size() + 1, 0);
    REP(i, 0, S.size()) {
        if (S[i] == 'S')
            arr[i + 1] = -2;
        else if (S[i] == 'K')
            arr[i + 1] = 1;
    }
    vector<pair<int, pair<int, int>>> sum(S.size() + 1, {0, {0, 0}});
    REP(i, 0, S.size()) {
        sum[i + 1].first = sum[i].first + arr[i + 1];
        sum[i+1].second.first = sum[i].second.first;
        sum[i+1].second.second = sum[i].second.second;
        if (arr[i + 1] == 1)
            sum[i + 1].second.second++;
        else if (arr[i + 1] == -2)
            sum[i + 1].second.first++;
    }

    // REP(i, 0, S.size() + 1) {
    //     cout << sum[i].first << " " << sum[i].second.first << " " << sum[i].second.second << endl;
    // }
    
    int ans = -1;
    REP(i, 0, S.size()) {
        REP(j, i + 1, S.size() + 1) {
            if (sum[j].first - sum[i].first == 0 && (sum[j].second.first - sum[i].second.first > 0 || sum[j].second.second - sum[i].second.second > 0)) {
                if (j - i > ans) {
                    ans = j - i;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}