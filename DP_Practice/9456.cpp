// 스티커
// https://www.acmicpc.net/problem/9456

#include <iostream>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using namespace std;

int main() {
    
    // S[x][0]은 첫 번째 행, x번 째 열의 값까지 포함했을 때의 최대 점수
    // S[x][1]은 두 번째 행, x번 째 열의 값까지 포함했을 때의 최대 점수
    // S[x][0] = p[x][0] + max(S[x-1][1], S[x-2][1]) (S[x-2][0]은 고려 안해도 됨. 이 경우는 S[x-1][1]에 포함됨.)
    // S[x][1] = p[x][1] + max(S[x-1][0], S[x-2][0]) (S[x-2][1]은 고려 안해도 됨. 이 경우는 S[x-1][0]에 포함됨.)
    // S(x) = max(S[x][0], S[x][1])

    int T;
    cin >> T;

    REP(i, 0, T) {
        int n;
        cin >> n;

        int p[100000][2];
        REP(i, 0, n) {
            cin >> p[i][0];
        }
        REP(i, 0, n) {
            cin >> p[i][1];
        }

        int S[100000][2];
        S[0][0] = p[0][0];
        S[0][1] = p[0][1];

        REP(x, 1, n) {
            if (x == 1) {
                S[x][0] = p[x][0] + S[x-1][1];
                S[x][1] = p[x][1] + S[x-1][0];
            } else {
                S[x][0] = p[x][0] + max(S[x-1][1], S[x-2][1]);
                S[x][1] = p[x][1] + max(S[x-1][0], S[x-2][0]);
            }
        }

        cout << max(S[n-1][0], S[n-1][1]) << endl;
    }
    

    return 0;
}