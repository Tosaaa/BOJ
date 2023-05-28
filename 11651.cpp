// 좌표 정렬하기 2
// https://www.acmicpc.net/problem/11651

#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
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
        arr[i] = make_pair(a, b);
    }
    sort(arr.begin(), arr.end(), cmp);

    REP(i, 0, N) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }

    return 0;
}