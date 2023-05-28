// 쉬운 계단 수
// https://www.acmicpc.net/problem/10844

#include <iostream>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define DIV 1000000000

using namespace std;

int main() {
    // S(x, l)
    //  = S(x-1, l-1) + S(x+1, l-1) (if 1 <= x <= 8)
    //  = S(x+1, l-1) (if x = 0)
    //  = S(x-1, l-1) (if x = 9)
    //  S(x, 0) = 0

    int N;
    cin >> N;

    int S[10][101] = {0};
    REP(i, 0, 10)
        S[i][1] = 1;

    REP(l, 2, N + 1) {
        REP(x, 0, 10) {
            if (x == 0)
                S[x][l] = S[x + 1][l - 1] % DIV;
            else if (x == 9)
                S[x][l] = S[x - 1][l - 1] % DIV;
            else
                S[x][l] = (S[x - 1][l - 1] % DIV + S[x + 1][l - 1] % DIV) % DIV;
        }
    }

    int sum = 0;
    REP(i, 1, 10) {
        //cout << i << ": " << S[i][N] << endl;
        sum += S[i][N];
        sum %= DIV;
    }
    cout << sum << endl;

    return 0;
}