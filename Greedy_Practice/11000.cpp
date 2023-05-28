// 강의실 배정
// https://www.acmicpc.net/problem/11000

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

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

    int room_cnt = 1;
    int room_in_use = 1;
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(arr[0].second);
    REP(i, 1, N) {
        while (!q.empty() && arr[i].first >= q.top()) {
            room_in_use--;
            q.pop();
        }
        if (room_cnt == room_in_use) {
            room_cnt++;
        }
        room_in_use++;
        q.push(arr[i].second);

    }

    cout << room_cnt << endl;

    return 0;
}