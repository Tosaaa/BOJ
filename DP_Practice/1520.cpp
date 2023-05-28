// 내리막 길
// https://www.acmicpc.net/problem/1520

#include <iostream>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using namespace std;

int M, N;
int pos[500][500];
int S[500][500];

int DFS(int x, int y) {
    if (S[x][y] != -1) return S[x][y];
    S[x][y] = 0; // mark as visited
    if (x < N-1 && pos[x][y] > pos[x+1][y]) {
        S[x][y] += DFS(x+1, y);
    }
    if (y < M-1 && pos[x][y] > pos[x][y+1]) {
        S[x][y] += DFS(x, y+1);
    }
    if (x > 0 && pos[x][y] > pos[x-1][y]) {
        S[x][y] += DFS(x-1, y);
    }
    if (y > 0 && pos[x][y] > pos[x][y-1]) {
        S[x][y] += DFS(x, y-1);
    }
    return S[x][y];
}



int main() {
    cin >> M >> N;

    REP(j, 0, M) {
        REP(i, 0, N) {
            cin >> pos[i][j];
        }
    }

    REP(j, 0, M) {
        REP(i, 0, N) {
            S[i][j] = -1;
        }
    }
    S[N-1][M-1] = 1;

    cout << DFS(0, 0) << endl;

}