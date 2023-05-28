// 쿼드트리
// https://www.acmicpc.net/problem/1992

#include <stdio.h>
int arr[100][100];

int quad(int x, int y, int N) {
    if (N == 1) {
        return -100;
    } else {
        printf("(");
        int tmp = arr[x][y];
        int isSame = 1;
        for (int i = x; i < x + N / 2; i++) {
            for (int j = y; j < y + N / 2; j++) {
                if (arr[i][j] != tmp) {
                    isSame = 0;
                    break;
                }
            }
        }
        if (!isSame) {
            quad(x, y, N / 2);
        } else {
            printf("%d", tmp);
        }

        tmp = arr[x][y + N / 2];
        isSame = 1;
        for (int i = x; i < x + N / 2; i++) {
            for (int j = y + N / 2; j < y + N; j++) {
                if (arr[i][j] != tmp) {
                    isSame = 0;
                    break;
                }
            }
        }
        if (!isSame) {
            quad(x, y + N / 2, N / 2);
        } else {
            printf("%d", tmp);
        }

        tmp = arr[x + N / 2][y];
        isSame = 1;
        for (int i = x + N / 2; i < x + N; i++) {
            for (int j = y; j < y + N / 2; j++) {
                if (arr[i][j] != tmp) {
                    isSame = 0;
                    break;
                }
            }
        }
        if (!isSame) {
            quad(x + N / 2, y, N / 2);
        } else {
            printf("%d", tmp);
        }

        tmp = arr[x + N / 2][y + N / 2];
        isSame = 1;
        for (int i = x + N / 2; i < x + N; i++) {
            for (int j = y + N / 2; j < y + N; j++) {
                if (arr[i][j] != tmp) {
                    isSame = 0;
                    break;
                }
            }
        }
        if (!isSame) {
            quad(x + N / 2, y + N / 2, N / 2);
        } else {
            printf("%d", tmp);
        }
        printf(")");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    int tmp = arr[0][0];
    int isSame = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tmp != arr[i][j]) {
                isSame = 0;
                break;
            }
        }
    }

    if (!isSame) {
        quad(0, 0, N);
    } else {
        printf("%d", arr[0][0]);
    }

    return 0;
}