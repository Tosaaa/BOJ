// 좌표 정렬하기
// https://www.acmicpc.net/problem/11650

#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

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
    sort(arr.begin(), arr.end());

    REP(i, 0, N) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }

    return 0;
}