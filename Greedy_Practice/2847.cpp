// 게임을 만든 동준이
// https://www.acmicpc.net/problem/2847

#include <iostream>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int score[100];
    REP(i, 0, N) {
        cin >> score[i];
    }

    int diff = 0, cnt = 0;
    for (int i = N-1; i > 0; i--) {
        if (score[i] <= score[i-1]) {
            diff = score[i-1] - score[i];
            cnt += diff + 1;
            score[i-1] = score[i]-1;
        }
    }

    cout << cnt << endl;

    return 0;
}