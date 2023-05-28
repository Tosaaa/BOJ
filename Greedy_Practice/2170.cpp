// 선 긋기
// https://www.acmicpc.net/problem/2170

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);

    int a, b;
    REP(i, 0, N) {
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr.begin(), arr.end(), cmp);

    // REP(i, 0, N) {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    int ans = arr[0].second - arr[0].first;
    int M = arr[0].second;
    REP(i, 1, N) {
        if (arr[i].first <= M) {
            if (arr[i].second > M) {
                ans += arr[i].second - M;
                M = arr[i].second;
            }
        } else {
            ans += arr[i].second - arr[i].first;
            M = arr[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}