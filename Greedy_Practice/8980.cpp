// 택배
// https://www.acmicpc.net/problem/8980

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

// 정렬 순서 생각하는게 좀 어려웠음. 길이로 했다가 52점 나오고, 아래처럼 바꾸고 100 나옴.
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<1>(a) == get<1>(b)) {
        return get<0>(a) > get<0>(b);
    }
    return get<1>(a) < get<1>(b);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, C, M;
    cin >> N >> C >> M;

    vector<tuple<int, int, int>> info(M);
    int a, b, c;
    REP(i, 0, M) {
        cin >> a >> b >> c;
        info[i] = make_tuple(a, b, c);
    }

    sort(info.begin(), info.end(), cmp);

    // cout << endl;
    // REP(i, 0, M) {
    //     tie(a, b, c) = info[i];
    //     cout << a << " " << b << " " << c << " " << endl;
    // }

    int ans = 0;
    vector<int> freeSpace(N, C);
    int s, e, cnt, min;
    REP(i, 0, M) {
        tie(s, e, cnt) = info[i];
        min = C;
        REP(j, s, e) {
            if (min > freeSpace[j]) min = freeSpace[j];
        }
        if (min == 0) continue;
        if (cnt > min) {
            cnt = min;
        }
        ans += cnt;
        REP(j, s, e) {
            freeSpace[j] -= cnt;
        }
    }

    cout << ans << endl;

    return 0;
}