// 별 찍기 - 10
// https://www.acmicpc.net/problem/2447

#include <stdio.h>

void star(int i, int j, int N) {
    if ((i / N) % 3 == 1 && (j / N) % 3 == 1)
        printf(" ");
    else {
        if (N == 1)
            printf("*");
        else {
            star(i, j, N / 3);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int tmp = 1;
    int K = 0;

    while (tmp != N) {
        K++;
        tmp *= 3;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            star(i, j, N);
        }
        printf("\n");
    }

    return 0;
}
