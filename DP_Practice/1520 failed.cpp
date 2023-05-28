// 내리막 길 (잘못된 풀이)
// https://www.acmicpc.net/problem/1520

    // H(x, y)의 값을 확정하려면 확정된 H(x-1, y), H(x, y-1), H(x+1, y), H(x, y+1)의 값이 필요함.
    // => 좌표 평면에서는 불가능 => 아래 방법은 애초에 불가능.
    // => 이럴 땐 순수 DP만으로 풀 수 없으므로, 다른 방법을 생각하자.
    // => DFS?
    // + 이 코드는 down, right만 고려했을 때 좌표 평면의 가장자리 줄이 확정되었다고 가정했지만, 사실 그렇지 않은 경우가 있음.

#include <iostream>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int pos[500][500];  // int pos[N][M]도 됨.
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            cin >> pos[i][j];
        }
    }
    // cout << endl;
    int H[500][500] = {0};
    H[0][0] = 1;
    // check only down, right.
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (x == 0 && y == 0) {  // x == 0, y == 0
            } else if (y == 0) {     // x != 0, y == 0
                if (pos[x - 1][y] > pos[x][y])
                    H[x][y] += H[x - 1][y];
            } else if (x == 0) {  // x == 0, y != 0
                if (pos[x][y - 1] > pos[x][y])
                    H[x][y] += H[x][y - 1];
            } else {  // x != 0, y != 0
                if (pos[x - 1][y] > pos[x][y])
                    H[x][y] += H[x - 1][y];
                if (pos[x][y - 1] > pos[x][y])
                    H[x][y] += H[x][y - 1];
            }
            // cout << H[x][y] << " ";
        }
        // cout << endl;
    }

    // check reverse
    for (int y = M - 2; y >= 0; y--) {
        for (int x = N - 2; x >= 0; x--) {
            if (pos[x + 1][y] > pos[x][y])
                H[x][y] += H[x + 1][y];
            if (pos[x][y + 1] > pos[x][y])
                H[x][y] += H[x][y + 1];
        }
    }
    //cout << endl;

    // update route
    int before = 0;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            before = H[x][y];
            H[x][y] = 0;
            if (x > 0) {
                if (pos[x - 1][y] > pos[x][y])
                    H[x][y] += H[x - 1][y];
            }
            if (y > 0) {
                if (pos[x][y - 1] > pos[x][y])
                    H[x][y] += H[x][y - 1];
            }
            if (x < N - 1 && y > 0 && y < M - 1) {
                if (pos[x + 1][y] > pos[x][y])
                    H[x][y] += H[x + 1][y];
            }
            if (y < M - 1 && x > 0 && x < N - 1) {
                if (pos[x][y + 1] > pos[x][y])
                    H[x][y] += H[x][y + 1];
            }

            H[x][y] = max(H[x][y], before);
            //cout << H[x][y] << " ";
        }
        //cout << endl;
    }

    cout << H[N - 1][M - 1] << endl;

    return 0;
}