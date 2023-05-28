// 로프
// https://www.acmicpc.net/problem/2217

#include <iostream>
#include <algorithm>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int rope[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    REP(i, 0, N) {
        cin >> rope[i];
    }

    sort(rope, rope + N);

    int max = 0;
    REP(i, 0, N) {
        if (max < rope[i] * (N - i)) max = rope[i] * (N - i);
    }

    cout << max << endl;

    return 0;
}