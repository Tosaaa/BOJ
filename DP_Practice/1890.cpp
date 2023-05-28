// 점프
// https://www.acmicpc.net/problem/1890

#include <iostream>

using namespace std;

int main() {

    // s(x, y) = 0
    // s(x, y) += s(x, i) if pos(x, i) = y - i
    // s(x, y) += s(j, y) if pos(j, y) = x - j

    int N;
    cin >> N;
    int pos[100][100] = {0};

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            cin >> pos[i][j];
        }
    }

    long long s[100][100] = {0};
    s[0][0] = 1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            for (int i = 0; i < y; i++) { // search above
                if (pos[x][i] == y - i) {
                    s[x][y] += s[x][i];
                }
            }
            for (int j = 0; j < x; j++) { // search left
                if (pos[j][y] == x - j) {
                    s[x][y] += s[j][y];
                }
            }
        }
    }

    cout << s[N-1][N-1] << endl;
    return 0;
}